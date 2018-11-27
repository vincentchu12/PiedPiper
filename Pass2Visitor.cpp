#include <iostream>
#include <string>
#include <cstdio>

#include "Pass2Visitor.h"
#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"
#include "wci/intermediate/symtabimpl/Predefined.h"

using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

extern string program_name;

Pass2Visitor::Pass2Visitor(ostream& j_file)
    : j_file(j_file) {}

Pass2Visitor::~Pass2Visitor() {}

int label_num = 0;
char label[4];

antlrcpp::Any Pass2Visitor::visitRoot(mmcParser::RootContext *ctx)
{
    cout << "\tvisitRoot      " << ctx->getText() << endl;
    // visitMainBlock
        // Emit the main program header.
        j_file << endl;
        j_file << ".method public static main([Ljava/lang/String;)V" << endl;
        j_file << endl;
        j_file << "\tnew RunTimer" << endl;
        j_file << "\tdup" << endl;
        j_file << "\tinvokenonvirtual RunTimer/<init>()V" << endl;
        j_file << "\tputstatic        " << program_name
               << "/_runTimer LRunTimer;" << endl;
        j_file << "\tnew PascalTextIn" << endl;
        j_file << "\tdup" << endl;
        j_file << "\tinvokenonvirtual PascalTextIn/<init>()V" << endl;
        j_file << "\tputstatic        " + program_name
               << "/_standardIn LPascalTextIn;" << endl;

        auto value = visitChildren(ctx);

        // Emit the main program epilogue.
        j_file << endl;
        j_file << "\tgetstatic     " << program_name
                   << "/_runTimer LRunTimer;" << endl;
        j_file << "\tinvokevirtual RunTimer.printElapsedTime()V" << endl;
        j_file << endl;
        j_file << "\treturn" << endl;
        j_file << endl;
        j_file << ".limit locals 16" << endl;
        j_file << ".limit stack 16" << endl;
        j_file << ".end method" << endl;
    //
    //j_file.close();
    return value;
}

// antlrcpp::Any Pass2Visitor::visitDeclaration(mmcParser::DeclarationContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitDefinition(mmcParser::DefinitionContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitFunctionDeclaration(mmcParser::FunctionDeclarationContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitFunctionCall(mmcParser::FunctionCallContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitParameters(mmcParser::ParametersContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitIdentifiers(mmcParser::IdentifiersContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitTypeID(mmcParser::TypeIDContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitFunctionID(mmcParser::FunctionIDContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitFunction(mmcParser::FunctionContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitVariableID(mmcParser::VariableIDContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitVariable(mmcParser::VariableContext *ctx)
// {

// }

antlrcpp::Any Pass2Visitor::visitNumber(mmcParser::NumberContext *ctx)
{
    cout << "\tvisitNumber      " << ctx->getText() << endl;
    // Emit a load constant instruction.
    j_file << "\tldc\t" << ctx->getText() << endl;
    cout << ctx->getText() << endl;

    return visitChildren(ctx);
}

antlrcpp::Any Pass2Visitor::visitSignedNumber(mmcParser::SignedNumberContext *ctx)
{
    cout << "\tvisitSignedNumber      " << ctx->getText() << endl;
    auto value = visitChildren(ctx);
    TypeSpec *type = ctx->number()->type;

    if (ctx->sign()->children[0]->getText() == "-")
    {
        string opcode = (type == Predefined::integer_type) ? "ineg"
                      :                                      "?neg";

        // Emit a negate instruction.
        j_file << "\t" << opcode << endl;
    }

    return value;
}

// antlrcpp::Any Pass2Visitor::visitSign(mmcParser::SignContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitStatement(mmcParser::StatementContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitDeclarationStatement(mmcParser::DeclarationStatementContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitDefinitionStatement(mmcParser::DefinitionStatementContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitExpressionStatement(mmcParser::ExpressionStatementContext *ctx)
// {

// }

antlrcpp::Any Pass2Visitor::visitIfStatement(mmcParser::IfStatementContext *ctx)
{
    cout << "\tvisitIfStatement      " << ctx->getText() << endl;

    int expression_size = ctx->expression().size();
    int original_label = label_num;
    int statement_size = ctx->statementList().size();

    char current_label[4];

    bool has_else = (expression_size < statement_size) ? true : false;

    char last_label[4];
    sprintf(last_label, "%d", label_num+statement_size);

    for(int i = 0; i < expression_size; i++)
    {
    	visitChildren(ctx->expression(i));
    }

    if(has_else)
    {
    	visitChildren(ctx->statementList(statement_size - 1));
    }

    j_file << "goto " << "Label_" << last_label << endl;

    for(int i = 0; i < expression_size; i++)
	{
    	sprintf(current_label, "%d", original_label++);
    	j_file << "Label_" << current_label << ":" << endl;
    	visitChildren(ctx->statementList(i));
		j_file << "goto " << "Label_" << last_label << endl;
	}
    j_file << "Label_" << last_label << ":" << endl;

    return NULL;
}

// antlrcpp::Any Pass2Visitor::visitForStatement(mmcParser::ForStatementContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitUnaryStatement(mmcParser::UnaryStatementContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitStatementList(mmcParser::StatementListContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitAssignmentStatement(mmcParser::AssignmentStatementContext *ctx)
// {

// }

antlrcpp::Any Pass2Visitor::visitBoolExpr(mmcParser::BoolExprContext *ctx)
{
    cout << "\tvisitBoolExpr      " << ctx->getText() << endl;
    string boolean_flag = (ctx->BOOL()->getText() == "true") ? "1" : "0";
    // Emit a load constant instruction.
    j_file << "\tldc\t" << boolean_flag << endl;

    return visitChildren(ctx);
}

antlrcpp::Any Pass2Visitor::visitVariableExpr(mmcParser::VariableExprContext *ctx)
{
    cout << "\tvisitVariableExpr      " << ctx->getText() << endl;
    string variable_name = ctx->variable()->IDENTIFIER()->toString();
    TypeSpec *type = ctx->type;

    string type_indicator = (type == Predefined::integer_type) ? "I"
                          : (type == Predefined::boolean_type) ? "Z"
                          :                                      "?";

    // Emit a field get instruction.
    j_file << "\tgetstatic\t" << program_name
           << "/" << variable_name << " " << type_indicator << endl;

    return visitChildren(ctx);
}

// antlrcpp::Any Pass2Visitor::visitBitExpr(mmcParser::BitExprContext *ctx)
// {

// }

antlrcpp::Any Pass2Visitor::visitAddSubExpr(mmcParser::AddSubExprContext *ctx)
{
    cout << "\tvisitAddSubExpr      " << ctx->getText() << endl;
    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expression(0)->type;
    TypeSpec *type2 = ctx->expression(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);

    string op = ctx->ADD_SUB_OP()->getText();
    string opcode;

    if (op == "+")
    {
        opcode = integer_mode ? "iadd"
               :                "????";
    }
    else
    {
        opcode = integer_mode ? "isub"
               :                "????";
    }

    // Emit an add or subtract instruction.
    j_file << "\t" << opcode << endl;

    return value;
}

// antlrcpp::Any Pass2Visitor::visitArrayExpr(mmcParser::ArrayExprContext *ctx)
// {

// }

antlrcpp::Any Pass2Visitor::visitMathExpr(mmcParser::MathExprContext *ctx)
{
    cout << "\tvisitMathExpr      " << ctx->getText() << endl;
    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expression(0)->type;
    TypeSpec *type2 = ctx->expression(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);

    string op = ctx->MATH_COMP()->getText();
    string opcode;

    if (op == "==")
    {
        opcode = integer_mode ? "if_icmpeq"
               :                "????";
    }
    else if (op == "!=")
    {
        opcode = integer_mode ? "if_icmpne"
               :                "????";
    }
    else if (op == "<")
    {
        opcode = integer_mode ? "if_icmplt"
               :                "????";
    }
    else if (op == "<=")
    {
        opcode = integer_mode ? "if_icmple"
               :                "????";
    }
    else if (op == ">")
    {
        opcode = integer_mode ? "if_icmpgt"
               :                "????";
    }
    else // >=
    {
        opcode = integer_mode ? "if_icmpge"
               :                "????";
    }

    sprintf(label, "%d", label_num++);
    // Emit an add or subtract instruction.
    j_file << "\t" << opcode << " Label_" << label << endl;

    return value;
}

//antlrcpp::Any Pass2Visitor::visitLogicExpr(mmcParser::LogicExprContext *ctx)
//{
//    cout << "\visitLogicExpr" << endl;
//    auto value = visitChildren(ctx);
//
//    TypeSpec *type1 = ctx->expression(0)->type;
//    TypeSpec *type2 = ctx->expression(1)->type;
//
//    bool integer_mode =    (type1 == Predefined::integer_type)
//                        && (type2 == Predefined::integer_type);
//
//    string op = ctx->MUL_DIV_MOD_OP()->getText();
//    string opcode;
//
//    if (op == "&&")
//    {
//        opcode = integer_mode ? "iand"
//               :                "????";
//    }
//    else if (op == "||")
//    {
//        opcode = integer_mode ? "idiv"
//               :                "????";
//    }
//    else // !
//    {
//        opcode = integer_mode ? "irem"
//               :                "????";
//    }
//
//    // Emit a multiply or divide instruction.
//    j_file << "\t" << opcode << endl;
//
//    return value;
//}

antlrcpp::Any Pass2Visitor::visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx)
{
    cout << "\tvisitMulDivModExpr      " << ctx->getText() << endl;
    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expression(0)->type;
    TypeSpec *type2 = ctx->expression(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);

    string op = ctx->MUL_DIV_MOD_OP()->getText();
    string opcode;

    if (op == "*")
    {
        opcode = integer_mode ? "imul"
               :                "????";
    }
    else if (op == "/")
    {
        opcode = integer_mode ? "idiv"
               :                "????";
    }
    else
    {
        opcode = integer_mode ? "irem"
               :                "????";
    }

    // Emit a multiply or divide instruction.
    j_file << "\t" << opcode << endl;

    return value;
}

// antlrcpp::Any Pass2Visitor::visitFuncCallExpr(mmcParser::FuncCallExprContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitUnsignedNumberExpr(mmcParser::UnsignedNumberExprContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitParenExpr(mmcParser::ParenExprContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitSignedNumberExpr(mmcParser::SignedNumberExprContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitPreInc(mmcParser::PreIncContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitPreDec(mmcParser::PreDecContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitPostInc(mmcParser::PostIncContext *ctx)
// {

// }

// antlrcpp::Any Pass2Visitor::visitPostDec(mmcParser::PostDecContext *ctx)
// {

// }

antlrcpp::Any Pass2Visitor::visitAssignment(mmcParser::AssignmentContext *ctx)
{
    cout << "\tvisitAssignment      " << ctx->getText() << endl;
    auto value = visit(ctx->expression());

    string type_indicator =
                  (ctx->expression()->type == Predefined::integer_type) ? "I"
                : (ctx->expression()->type == Predefined::boolean_type) ? "Z"
                :                                                   "?";

    // Emit a field put instruction.
    j_file << "\tputstatic\t" << program_name
           << "/" << ctx->variable()->IDENTIFIER()->toString()
           << " " << type_indicator << endl;

    return value;
}



