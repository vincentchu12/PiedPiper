#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


#include "Pass1Visitor.h"
#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"
#include "wci/util/CrossReferencer.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::util;

extern string program_name;
extern unordered_map<string, int> sizeTable;
static string function_name = "";

static SymTabEntry *variable_id;

static void EXCEPTION(string message)
{
	cout << "Error: " << message << endl;
	exit(1);
}

bool Pass1Visitor::determineType(mmcParser::TypeIDContext *ctx, TypeSpec ** type, string * type_indicator)
{
	if(ctx == NULL)
	{
		EXCEPTION("No type found");
	}

	string type_name = ctx->IDENTIFIER()->toString();
    
    bool success = true;
    if(type_name == "int")
    {
        *type = Predefined::integer_type;
        *type_indicator = "I";
    }
    else if (type_name == "bool")
    {
        *type = Predefined::boolean_type;
        *type_indicator = "Z";
    }
    else if (type_name == "string")
    {
        *type = Predefined::char_type;
        *type_indicator = "Ljava/lang/String;";
    }
    else if (type_name == "void")
    {
        *type = Predefined::void_type;
        *type_indicator = "V";
    }
    else
    {
        *type = nullptr;
        *type_indicator = "?";
        success = false;
    }
    return success;
}

bool Pass1Visitor::lookupVariable(mmcParser::VariableContext *ctx, SymTabEntry ** var_id)
{
	if(ctx == NULL)
	{
		EXCEPTION("Variable is missing");
	}

	string variable_name = function_name + ctx->IDENTIFIER()->toString();
    *var_id = symtab_stack->lookup(variable_name);

    return *var_id != NULL;
}

Pass1Visitor::Pass1Visitor()
    : program_id(nullptr), j_file(nullptr)
{
    // Create and initialize the symbol table stack.
    symtab_stack = SymTabFactory::create_symtab_stack();
    Predefined::initialize(symtab_stack);

    cout << "=== Pass1Visitor(): symtab stack initialized." << endl;
}

Pass1Visitor::~Pass1Visitor() {}

ostream& Pass1Visitor::get_assembly_file() { return j_file; }

antlrcpp::Any Pass1Visitor::visitRoot(mmcParser::RootContext *ctx)
{   
    // Visit Header Block
    cout << "=== visitRoot: " + ctx->getText() << endl;

    program_id = symtab_stack->enter_local(program_name);
    program_id->set_definition((Definition)DF_PROGRAM);
    program_id->set_attribute((SymTabKey) ROUTINE_SYMTAB,
                              symtab_stack->push());
    symtab_stack->set_program_id(program_id);

    // Create the assembly output file.
    j_file.open(program_name + ".j");
    if (j_file.fail())
    {
            cout << "***** Cannot open assembly file." << endl;
            exit(-99);
    }

    // Emit the program header.
    j_file << ".class public " << program_name << endl;
    j_file << ".super java/lang/Object" << endl;

    // Emit the RunTimer and PascalTextIn fields.
    j_file << endl;
    j_file << ".field private static _runTimer LRunTimer;" << endl;
    j_file << ".field private static _standardIn LPascalTextIn;" << endl;

    auto value = visitChildren(ctx);

    // Emit the class constructor.
    j_file << endl;
    j_file << ".method public <init>()V" << endl;
    j_file << endl;
    j_file << "\taload_0" << endl;
    j_file << "\tinvokenonvirtual    java/lang/Object/<init>()V" << endl;
    j_file << "\treturn" << endl;
    j_file << endl;
    j_file << ".limit locals 1" << endl;
    j_file << ".limit stack 1" << endl;
    j_file << ".end method" << endl;

       cout << "=== visitRoot: Printing xref table." << endl;

    // Print the cross-reference table.
    CrossReferencer cross_referencer;
    cross_referencer.print(symtab_stack);

    return value;
}

antlrcpp::Any Pass1Visitor::visitVariableDeclaration(mmcParser::VariableDeclarationContext *ctx)
{
    cout << "=== visitVariableDeclarations: " << ctx->getText() << endl;
    
    variable_id = nullptr;
    
    auto value = visitChildren(ctx);

    TypeSpec *type;
    string type_indicator;

    if(determineType(ctx->typeID(), &type, &type_indicator) == false)
    {
        EXCEPTION("Invalid type!");
    }

    // set the variable type
    variable_id->set_typespec(type);

    // Emit a field declaration.
    j_file << ".field private static " << variable_id->get_name() << " " << type_indicator << endl;
    
    return value;
}

antlrcpp::Any Pass1Visitor::visitArrayDeclaration(mmcParser::ArrayDeclarationContext *ctx)
{
    cout << "=== visitArrayDeclarations: " << ctx->getText() << endl;
    variable_id = nullptr;

    auto value = visitChildren(ctx);

    TypeSpec *type;
    string type_indicator;
    
    if(determineType(ctx->typeID(), &type, &type_indicator) == false)
    {
        EXCEPTION("Invalid type!");
    }
    
    // Set the Variable Type
    variable_id->set_typespec(type);

    // Emit a field declaration for arrays [.
    j_file << ".field private static " << variable_id->get_name() << " " << "[" << type_indicator << endl;

    return value;
}

antlrcpp::Any Pass1Visitor::visitVariableDef(mmcParser::VariableDefContext *ctx)
{
    cout << "=== visitVariableDefs: " << ctx->getText() << endl;
    variable_id = nullptr;

    auto value = visitChildren(ctx);

    TypeSpec *type;
    string type_indicator;

    if(determineType(ctx->typeID(), &type, &type_indicator) == false)
    {
        EXCEPTION("Invalid type!");
    }

    // Set the Variable Type
    variable_id->set_typespec(type);

    // Emit a field declaration.
    j_file << ".field private static " << variable_id->get_name() << " " << type_indicator << endl;

    return value;
}

antlrcpp::Any Pass1Visitor::visitArrayDef(mmcParser::ArrayDefContext *ctx)
  {
    cout << "=== visitArrayDefs: " << ctx->getText() << endl;
    variable_id = nullptr;

    auto value = visitChildren(ctx);

    TypeSpec *type;
    string type_indicator;

    if(determineType(ctx->typeID(), &type, &type_indicator) == false)
    {
        EXCEPTION("Invalid type!");
    }

    // Set the Variable Type
    variable_id->set_typespec(type);

    // Emit a field declaration for arrays [.
    j_file << ".field private static " << variable_id->get_name() << " " << "[" << type_indicator << endl;
    
    // Add array size to dictionary
    string array_name = variable_id->get_name();
    int    array_size = stoi(ctx->number()->getText());
    
    sizeTable.emplace(array_name, array_size);

    return value;
  }

antlrcpp::Any Pass1Visitor::visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx)
{
    cout << "=== visitFunctionDefinition: " + ctx->getText() << endl;

    function_name = ctx->functionID()->getText() + "_";
        
    variable_id = nullptr;
    auto value = visit(ctx->functionID());
    visit(ctx->typeID());

    TypeSpec *type;
    string type_indicator;
    
    if(determineType(ctx->typeID(), &type, &type_indicator) == false)
    {
        EXCEPTION("Invalid type!");
    }
    
    variable_id->set_typespec(type);

    visit(ctx->parameters());
    visit(ctx->statementList());
    visit(ctx->expression());
    function_name = "";

    return value;
}

antlrcpp::Any Pass1Visitor::visitFunctionID(mmcParser::FunctionIDContext *ctx)
{
    cout << "=== visitFunctionID: " + ctx->getText() << endl;

    string func_name = ctx->IDENTIFIER()->toString();
    
    if(symtab_stack->lookup(func_name) != NULL)
    {
        EXCEPTION("Redeclaration of function");
    }

    variable_id = symtab_stack->enter_local(func_name);
    variable_id->set_definition((Definition) DF_FUNCTION);

    return visitChildren(ctx);
}

antlrcpp::Any Pass1Visitor::visitVariableID(mmcParser::VariableIDContext *ctx)
{
    cout << "=== visitVariableID: " + ctx->getText() << endl;

    string variable_name = function_name + ctx->IDENTIFIER()->toString();
    
    if(symtab_stack->lookup(variable_name) != NULL)
    {
        EXCEPTION("Redeclaration of variable");
    }

    variable_id = symtab_stack->enter_local(variable_name);
    variable_id->set_definition((Definition) DF_VARIABLE);

    return visitChildren(ctx);
}

 antlrcpp::Any Pass1Visitor::visitVariable(mmcParser::VariableContext *ctx)
 {
     cout << "=== visitVariable: " + ctx->getText() << endl;

     if(lookupVariable(ctx, &variable_id) == false)
     {
         EXCEPTION("Variable is not defined");
     }

	 ctx->type = variable_id->get_typespec();
     return visitChildren(ctx);
 }

antlrcpp::Any Pass1Visitor::visitBitIndexExpr(mmcParser::BitIndexExprContext *ctx)
{
    cout << "=== visitBitIndexExpr: " + ctx->getText() << endl;
    auto value = visitChildren(ctx);
    ctx->type = ctx->variable()->type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitVariableExpr(mmcParser::VariableExprContext *ctx)
{
    cout << "=== visitVariableExpr: " + ctx->getText() << endl;
    auto value =  visitChildren(ctx);
    ctx->type = ctx->variable()->type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitBitExpr(mmcParser::BitExprContext *ctx)
{
   cout << "=== visitBitExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expression(0)->type;
    TypeSpec *type2 = ctx->expression(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   :                nullptr;
    ctx->type = type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitAddSubExpr(mmcParser::AddSubExprContext *ctx)
{
   cout << "=== visitAddSubExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);
    
    TypeSpec *type1 = ctx->expression(0)->type;
    TypeSpec *type2 = ctx->expression(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   :                nullptr;
    ctx->type = type;

    return value;
}

 antlrcpp::Any Pass1Visitor::visitArrayExpr(mmcParser::ArrayExprContext *ctx)
 {
	cout << "=== visitArrayExpr: " + ctx->getText() << endl;

	auto value = visitChildren(ctx);
	ctx->type = ctx->variable()->type;

	return value;
 }

antlrcpp::Any Pass1Visitor::visitNumber(mmcParser::NumberContext *ctx)
{
    cout << "=== visitNumber: " + ctx->getText() << endl;

    ctx->type = Predefined::integer_type;
    
    return visitChildren(ctx);
}

antlrcpp::Any Pass1Visitor::visitSignedNumber(mmcParser::SignedNumberContext *ctx)
{
    cout << "=== visitSignedNumber: " + ctx->getText() << endl;

    auto value = visit(ctx->number());
    ctx->type = ctx->number()->type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitSignedNumberExpr(mmcParser::SignedNumberExprContext *ctx)
{
   cout << "=== visitSignedNumberExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);
    ctx->type = ctx->signedNumber()->type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitBoolExpr(mmcParser::BoolExprContext *ctx)
{
   cout << "=== visitBoolExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);
    ctx->type = Predefined::boolean_type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitStr(mmcParser::StrContext *ctx)
{
	 cout << "=== visitStrExpr: " + ctx->getText() << endl;
	 
     ctx->type = Predefined::char_type;

	 return visitChildren(ctx);
}

antlrcpp::Any Pass1Visitor::visitStringExpr(mmcParser::StringExprContext *ctx)
{
	   cout << "=== visitStringExpr: " + ctx->getText() << endl;
	    
        auto value = visitChildren(ctx);
	    ctx->type = ctx->str()->type;

	    return value;
}

antlrcpp::Any Pass1Visitor::visitUnsignedNumberExpr(mmcParser::UnsignedNumberExprContext *ctx)
{
    cout << "=== visitUnsignedNumberExpr: " + ctx->getText() << endl;
    
    auto value = visitChildren(ctx);
    ctx->type = ctx->number()->type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitMathExpr(mmcParser::MathExprContext *ctx)
{
    cout << "=== visitMathExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);
    ctx->type = Predefined::boolean_type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx)
{
    cout << "=== visitMulDivExpr: " + ctx->getText() << endl;
    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expression(0)->type;
    TypeSpec *type2 = ctx->expression(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);

    TypeSpec *type = integer_mode ? Predefined::integer_type
                   :                nullptr;
    ctx->type = type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitFuncCallExpr(mmcParser::FuncCallExprContext *ctx)
{
    cout << "=== visitFuncCallExpr: " + ctx->getText() << endl;

    string func_name = ctx->functionCall()->function()->IDENTIFIER()->toString();
    SymTabEntry *function_id = symtab_stack->lookup(func_name);

    if(function_id == NULL)
    {
    	EXCEPTION("Function is not defined");
    }
    ctx->type = function_id->get_typespec();

    return visitChildren(ctx);
}

antlrcpp::Any Pass1Visitor::visitParenExpr(mmcParser::ParenExprContext *ctx)
{
    cout << "=== visitParenExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);
    ctx->type = ctx->expression()->type;

    return value;
}

antlrcpp::Any Pass1Visitor::visitUnaryExpr(mmcParser::UnaryExprContext *ctx)
{
    cout << "=== visitUnaryExpr: " + ctx->getText() << endl;

    auto value = visitChildren(ctx);
    ctx->type = ctx->unary()->type;

    return value;
}

 antlrcpp::Any Pass1Visitor::visitPreInc(mmcParser::PreIncContext *ctx)
 {
    cout << "=== visitPreInc: " + ctx->getText() << endl;
    
    auto value = visitChildren(ctx);

    if(lookupVariable(ctx->variable(), &variable_id) == false)
    {
        EXCEPTION("Variable is not defined");
    }
    ctx->type = variable_id->get_typespec();

    return value;
 }

 antlrcpp::Any Pass1Visitor::visitPreDec(mmcParser::PreDecContext *ctx)
 {
    cout << "=== visitPreDec: " + ctx->getText() << endl;
    
    auto value = visitChildren(ctx);

    if(lookupVariable(ctx->variable(), &variable_id) == false)
    {
        EXCEPTION("Variable is not defined");
    }
    ctx->type = variable_id->get_typespec();

    return value;
 }

 antlrcpp::Any Pass1Visitor::visitPostInc(mmcParser::PostIncContext *ctx)
 {
	cout << "=== visitPostInc: " + ctx->getText() << endl;
	
    auto value = visitChildren(ctx);
    
    if(lookupVariable(ctx->variable(), &variable_id) == false)
    {
        EXCEPTION("Variable is not defined");
    }
	ctx->type = variable_id->get_typespec();

	return value;
 }

 antlrcpp::Any Pass1Visitor::visitPostDec(mmcParser::PostDecContext *ctx)
 {
    cout << "=== visitPostDec: " + ctx->getText() << endl;
    
    auto value = visitChildren(ctx);

    if(lookupVariable(ctx->variable(), &variable_id) == false)
    {
        EXCEPTION("Variable is not defined");
    }
    ctx->type = variable_id->get_typespec();

    return value;
 }
