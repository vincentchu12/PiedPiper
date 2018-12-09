#include <iostream>
#include <string>
#include <cstdio>


#include <unordered_map>
#include <vector>

#include "Pass2Visitor.h"
#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"
#include "wci/intermediate/symtabimpl/Predefined.h"

using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

static unordered_map<string, vector<vector<string>>> function_param_map;

extern string program_name;
extern unordered_map<string, int> sizeTable;

static string function_name = "";


#include <stdio.h>
static string EXCEPTION(string message)
{
	cout << "Error: " << message << endl;
	{
		string filename = program_name + ".j";
		char file[filename.length() + 1];
		strcpy(file, filename.c_str());

		std::remove(file);
	}
	exit(1);
}


Pass2Visitor::Pass2Visitor(ostream& j_file)
    : j_file(j_file) {}

Pass2Visitor::~Pass2Visitor() {}

int label_num = 0;

antlrcpp::Any Pass2Visitor::visitRoot(mmcParser::RootContext *ctx)
{
    // cout << "\tvisitRoot      " << ctx->getText() << endl;
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

    cout << "Generated: " << program_name << ".j" << endl;
    return value;
}


 antlrcpp::Any Pass2Visitor::visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx)
 {

	 // cout << "\tvisitFunctionDefinition" << ctx->getText() << endl;
	 function_name = ctx->functionID()->getText() + "_";

	 j_file << "\tgoto " << function_name << "end" << endl;

	 j_file << ctx->functionID()->getText() << ":" << endl;

	 j_file << "\tastore_1" << endl;

	 vector<vector<string>> params;

	 if(ctx->parameters() != NULL)
	 {
		 for(int i = 0; i < ctx->parameters()->declaration().size(); i++)
		 {
			 string type_name     = ctx->parameters()->declaration(i)->children[0]->getText();
			 string variable_name = ctx->parameters()->declaration(i)->children[1]->getText();

			 params.push_back({function_name + variable_name, type_name});
		 }
	 }

	 function_param_map.emplace(ctx->functionID()->IDENTIFIER()->getText(), params);

	 auto value = visitChildren(ctx->statementList());

	 if(ctx->expression() != NULL)
	 {
		 visit(ctx->expression());
	 }

	 j_file << "\tret 1" << endl;
	 j_file << function_name << "end:" << endl;
	 function_name = "";


	 return value;
 }

 antlrcpp::Any Pass2Visitor::visitFunctionCall(mmcParser::FunctionCallContext *ctx)
 {
	 if(ctx->identifiers() != NULL)
	 {
		 int input_count = ctx->identifiers()->expression().size();

		 vector<vector<string>> params = function_param_map.find(ctx->function()->IDENTIFIER()->getText())->second;

		 int params_count = params.size();

		 int max = (params_count > input_count) ? input_count: params_count;
		 for(int i = 0; i < max; i++)
		 {
			 string variable_name = params[i][0];
			 string type_name     = params[i][1];
			 visit(ctx->identifiers()->expression(i));

			string type_indicator =
						  (type_name == "int")     ? "I"
						: (type_name == "bool")    ? "Z"
						: (type_name == "string")  ? "Ljava/lang/String;"
						:                         EXCEPTION("Invalid Type");

			// Emit a field put instruction.
			j_file << "\tputstatic\t" << program_name
				   << "/" << function_name <<  variable_name
				   << " " << type_indicator << endl;
		 }
	 }

	 j_file << "\tjsr " << ctx->function()->IDENTIFIER()->getText() << endl;
	 return NULL;
 }

antlrcpp::Any Pass2Visitor::visitNumber(mmcParser::NumberContext *ctx)
{
    // cout << "\tvisitNumber      " << ctx->getText() << endl;
    
    // Emit a load constant instruction.
    j_file << "\tldc\t" << ctx->getText() << endl;

    return visitChildren(ctx);
}

antlrcpp::Any Pass2Visitor::visitSignedNumber(mmcParser::SignedNumberContext *ctx)
{
    // cout << "\tvisitSignedNumber      " << ctx->getText() << endl;
    auto value = visitChildren(ctx);

    if (ctx->sign()->children[0]->getText() == "-")
    {
        string opcode = (ctx->type == Predefined::integer_type) ? "ineg"
                      :                                      "?neg";

        // Emit a negate instruction.
        j_file << "\t" << opcode << endl;
    }

    return value;
}

antlrcpp::Any Pass2Visitor::visitIfStatement(mmcParser::IfStatementContext *ctx)
{
    // cout << "\tvisitIfStatement      " << ctx->getText() << endl;

    int math_expression_size = ctx->mathExpr().size();
    int original_label       = label_num;
    int statement_size       = ctx->statementList().size();

    int current_label;

    bool has_else = (math_expression_size < statement_size) ? true : false;

    int last_label = label_num + math_expression_size;

    for(int i = 0; i < math_expression_size; i++)
    {
    	visit(ctx->mathExpr(i));
    }

    if(has_else)
    {
    	visitChildren(ctx->statementList(statement_size - 1));
    }

    j_file << "\tgoto " << "Label_" << last_label << endl;

    for(int i = 0; i < math_expression_size; i++)
	{
    	current_label = original_label++;
    	j_file << "Label_" << current_label << ":" << endl;
    	visitChildren(ctx->statementList(i));
		j_file << "\tgoto " << "Label_" << last_label << endl;
	}
    j_file << "Label_" << last_label << ":" << endl;
    label_num++;
    return NULL;
}

antlrcpp::Any Pass2Visitor::visitForStatement(mmcParser::ForStatementContext *ctx)
{
	// cout << "\tvisitForStatement " << ctx->getText() << endl;

	bool list_iterator = (ctx->variable() != NULL);

	if(list_iterator)
	{
		if(ctx->declaration().size() != 2)
		{
			EXCEPTION("Missing items in for iterator loop");
		}

		visit(ctx->declaration(0));

		string array = ctx->variable()->getText();
		int array_size = sizeTable.find(array)->second;

	// set int i, equal to 0
		j_file << "\tldc 0" <<endl;
		string type_idx;
		if(ctx->declaration(0)->children[0]->getText() == "int") //change this maybe
			type_idx = "I";
		else if(ctx->declaration(0)->children[0]->getText() == "bool")
			type_idx = "Z";
		else if(ctx->declaration(0)->children[0]->getText() == "string")
			type_idx = "Ljava/lang/String;";
		else
			type_idx = EXCEPTION("Invalid Type");

		string idx = ctx->declaration(0)->children[1]->getText();
		//getting idx
		j_file << "\tputstatic\t" << program_name
				   << "/" << function_name << idx
				   << " " << type_idx << endl;
	//declare iterator
		visit(ctx->declaration(1));

		int loop_start = label_num++;
		int loop_true = label_num++;
		int loop_exit = label_num;

		string type_iterator;
		if(ctx->declaration(1)->children[0]->getText() == "int")
			type_iterator = "I";
		else if(ctx->declaration(1)->children[0]->getText() == "bool")
			type_iterator = "Z";
		else if(ctx->declaration(1)->children[0]->getText() == "string")
			type_iterator = "Ljava/lang/String;";
		else
			type_iterator = EXCEPTION("Invalid Type");
	//create loop start label
		string iterator = ctx->declaration(1)->children[1]->getText();
		j_file << "Label_" << loop_start << ":" << endl;

		j_file << "\tgetstatic\t" << program_name
				   << "/" << function_name << idx
				   << " " << type_idx << endl;

		j_file << "\tldc " << array_size << endl;

		j_file << "\tif_icmplt Label_" << loop_true <<endl;

		j_file << "\tgoto Label_" << loop_exit << endl;

		j_file << "Label_" << loop_true << ":" << endl;


		string type_array =  (ctx->variable()->type == Predefined::integer_type) ? "[I"
						   : (ctx->variable()->type == Predefined::boolean_type) ? "[Z"
						   : (ctx->variable()->type == Predefined::char_type)    ? "[Ljava/lang/String;"
						   :                                     				   EXCEPTION("Invalid Type");

		string load =  (ctx->variable()->type == Predefined::integer_type) ? "iaload"
								   : (ctx->variable()->type == Predefined::boolean_type) ? "iaload"
								   : (ctx->variable()->type == Predefined::char_type)    ? "aaload"
								   :                                     				   "?load";

	//set iterator to value of array at index
		j_file << "\tgetstatic\t" << program_name
				   << "/" << function_name << array
				   << " " << type_array << endl;

		j_file << "\tgetstatic\t" << program_name
						   << "/" << function_name << idx
						   << " " << type_idx << endl;

		j_file << "\t" << load << endl
				<< "\tputstatic\t" << program_name
				<< "/" << function_name << iterator
				<< " " << type_iterator << endl;

		if(ctx->statementList() != NULL)
		{
			visit(ctx->statementList());
		}

		//i++
		j_file << "\tgetstatic\t" << program_name
				   << "/" << function_name << idx
				   << " " << type_idx << endl
				   << "\ticonst_1" << endl
				   << "\tiadd" << endl
				   << "\tputstatic\t" << program_name
				   << "/" << function_name << idx
				   << " " << type_idx << endl;

		j_file << "\tgoto Label_" << loop_start << endl;

		j_file << "Label_" << loop_exit << ":" << endl;

		label_num = loop_exit + 1;
	}
	else
	{		
		if(ctx->declaration().size() != 0)
		{			
			visit(ctx->declaration(0));
		}
		else if (ctx->definition() != NULL)
		{			
			visit(ctx->definition());
		}
		else if(
				(ctx->assignment().size() == 2 && ctx->expression() != NULL) ||
				(ctx->assignment().size() == 1 && ctx->expression() == NULL)
		)
		{
			visit(ctx->assignment(0));
		}
		else
		{
			EXCEPTION("Missing item in for loop");
		}		

		int loop_start = label_num++;
		int loop_true = label_num;
		int loop_exit = label_num + 1;		
		j_file << "Label_" << loop_start << ":" << endl;
		
        if(ctx->mathExpr() == NULL)
        {
        	EXCEPTION("Missing boolean condition");
        }

		visit(ctx->mathExpr());

        j_file << "\tgoto Label_" << loop_exit << endl;        

        j_file << "Label_" << loop_true << ":" << endl;

        if(ctx->expression() == NULL && ctx->assignment().size() == 0)
        {
        	EXCEPTION("Missing item in for loop");
        }

		if(ctx->statementList() != NULL)
		{
			visit(ctx->statementList());
		}
		

		if(ctx->expression() != NULL)
		{
			visit(ctx->expression());
		}
		else
		{
			int child = (ctx->assignment().size() == 1) ? 0 : 1;
			visit(ctx->assignment(child));

		}		
		j_file << "\tgoto Label_" << loop_start << endl;

		j_file << "Label_" << loop_exit << ":" << endl;

        label_num = loop_exit + 1;
	}
	return NULL;
}

antlrcpp::Any Pass2Visitor::visitBoolExpr(mmcParser::BoolExprContext *ctx)
{
    // cout << "\tvisitBoolExpr      " << ctx->getText() << endl;
    string boolean_flag = (ctx->BOOL()->getText() == "true") ? "1" : "0";
    // Emit a load constant instruction.
    j_file << "\tldc\t" << boolean_flag << endl;

    return visitChildren(ctx);
}

antlrcpp::Any Pass2Visitor::visitVariableExpr(mmcParser::VariableExprContext *ctx)
{
    // cout << "\tvisitVariableExpr      " << ctx->getText() << endl;
    string variable_name = ctx->variable()->IDENTIFIER()->toString();
    TypeSpec *type = ctx->type;

    string type_indicator = (type == Predefined::integer_type) ? "I"
                          : (type == Predefined::boolean_type) ? "Z"
						  : (type == Predefined::char_type)    ? "Ljava/lang/String;"
                          :                                      EXCEPTION("Invalid Type");

    // Emit a field get instruction.
    j_file << "\tgetstatic\t" << program_name
           << "/" << function_name << variable_name << " " << type_indicator << endl;

    return visitChildren(ctx);
}

antlrcpp::Any Pass2Visitor::visitAddSubExpr(mmcParser::AddSubExprContext *ctx)
{
    // cout << "\tvisitAddSubExpr      " << ctx->getText() << endl;
    auto value = visitChildren(ctx);
    if(ctx->expression().size() != 2)
	{
		EXCEPTION("Missing operand");
	}

    TypeSpec *type1 = ctx->expression(0)->type;
    TypeSpec *type2 = ctx->expression(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);

    string op = ctx->ADD_SUB_OP()->getText();
    string opcode;

    if (op == "+")
    {
        opcode = integer_mode ? "iadd"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }
    else
    {
        opcode = integer_mode ? "isub"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }

    // Emit an add or subtract instruction.
    j_file << "\t" << opcode << endl;

    return value;
}

antlrcpp::Any Pass2Visitor::visitMathExpr(mmcParser::MathExprContext *ctx)
{
    // cout << "\tvisitMathExpr      " << ctx->getText() << endl;
    auto value = visitChildren(ctx);

    if(ctx->expression().size() != 2)
    {
    	EXCEPTION("Missing operand");
    }
    TypeSpec *type1 = ctx->expression(0)->type;
    TypeSpec *type2 = ctx->expression(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);
    bool boolean_mode =    (type1 == Predefined::boolean_type)
                        && (type2 == Predefined::boolean_type);

    string op = ctx->MATH_COMP()->getText();
    string opcode;

    if (op == "==")
    {
        opcode = integer_mode ? "if_icmpeq"
               : boolean_mode ? "if_icmpeq"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }
    else if (op == "!=")
    {
        opcode = integer_mode ? "if_icmpne"
               : boolean_mode ? "if_icmpne"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }
    else if (op == "<")
    {
        opcode = integer_mode ? "if_icmplt"
               : boolean_mode ? "if_icmplt"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }
    else if (op == "<=")
    {
        opcode = integer_mode ? "if_icmple"
               : boolean_mode ? "if_icmple"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }
    else if (op == ">")
    {
        opcode = integer_mode ? "if_icmpgt"
               : boolean_mode ? "if_icmpgt"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }
    else // >=
    {
        opcode = integer_mode ? "if_icmpge"
               : boolean_mode ? "if_icmpge"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }

    // Emit an add or subtract instruction.
    j_file << "\t" << opcode << " Label_" << label_num++ << endl;

    return value;
}

antlrcpp::Any Pass2Visitor::visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx)
{
    // cout << "\tvisitMulDivModExpr      " << ctx->getText() << endl;
    auto value = visitChildren(ctx);
    if(ctx->expression().size() != 2)
	{
		EXCEPTION("Missing operand");
	}
    TypeSpec *type1 = ctx->expression(0)->type;
    TypeSpec *type2 = ctx->expression(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);

    string op = ctx->MUL_DIV_MOD_OP()->getText();
    string opcode;

    if (op == "*")
    {
        opcode = integer_mode ? "imul"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }
    else if (op == "/")
    {
        opcode = integer_mode ? "idiv"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }
    else
    {
        opcode = integer_mode ? "irem"
               :                EXCEPTION("Invalid Type, Unknown OP");
    }

    // Emit a multiply or divide instruction.
    j_file << "\t" << opcode << endl;

    return value;
}

 antlrcpp::Any Pass2Visitor::visitUnaryExpr(mmcParser::UnaryExprContext *ctx)
 {
	 // cout << "\tvisitUnaryExpr" << endl;
	 string child0 = ctx->unary()->children[0]->getText();
	 string child1 = ctx->unary()->children[1]->getText();

	string type_indicator =
	                  (ctx->unary()->type == Predefined::integer_type) ? "I"
	                : (ctx->unary()->type == Predefined::boolean_type) ? "Z"
	                :                                                    EXCEPTION("Invalid Type");
	 if(child0 == "++" || child0 == "--")
	 {
		 auto value = visitChildren(ctx);
		 j_file << "\tputstatic\t" << program_name << "/" << function_name << child1 << " " << type_indicator << endl;
		 j_file << "\tgetstatic\t" <<  program_name << "/" << function_name << child1 << " " << type_indicator << endl;

	 }
	 else
	 {
		 j_file << "\tgetstatic\t" <<  program_name << "/" << function_name << child0 << " " << type_indicator << endl;
		 auto value = visitChildren(ctx);
		 j_file << "\tputstatic\t" <<  program_name << "/" << function_name << child0 << " " << type_indicator << endl;

	 }

	 return NULL;

 }

 antlrcpp::Any Pass2Visitor::visitPreInc(mmcParser::PreIncContext *ctx)
 {
	 // cout << "\tvisitPreInc" << endl;
	 auto value = visitChildren(ctx);
	 j_file << "\ticonst_1" << endl;
	 bool integer_mode = (ctx->type == Predefined::integer_type);
	 string opcode = integer_mode ? "iadd"
	                :                EXCEPTION("Invalid Type, Unknown OP");
	 j_file << "\t" << opcode << endl;

	 return value;
 }

 antlrcpp::Any Pass2Visitor::visitPreDec(mmcParser::PreDecContext *ctx)
 {
	 // cout << "\tvisitPreDec" << endl;
	 auto value = visitChildren(ctx);
	 j_file << "\ticonst_1" << endl;
	 bool integer_mode = (ctx->type == Predefined::integer_type);
	 string opcode = integer_mode ? "isub"
					:                EXCEPTION("Invalid Type, Unknown OP");
	 j_file << "\t" << opcode << endl;
	 return value;
 }

 antlrcpp::Any Pass2Visitor::visitPostInc(mmcParser::PostIncContext *ctx)
 {
	 // cout << "\tvisitPostInc" << endl;
	 auto value = visitChildren(ctx);
	 j_file << "\ticonst_1" << endl;
	 bool integer_mode = (ctx->type == Predefined::integer_type);
	 string opcode = integer_mode ? "iadd"
					:                EXCEPTION("Invalid Type, Unknown OP");
	 j_file << "\t" << opcode << endl;
	 return value;
 }

 antlrcpp::Any Pass2Visitor::visitPostDec(mmcParser::PostDecContext *ctx)
 {
	 // cout << "\tvisitPostDec" << endl;
	 auto value = visitChildren(ctx);
	 j_file << "\ticonst_1" << endl;
	 bool integer_mode = (ctx->type == Predefined::integer_type);
	 string opcode = integer_mode ? "isub"
					:                EXCEPTION("Invalid Type, Unknown OP");
	 j_file << "\t" << opcode << endl;

	 return value;

 }

antlrcpp::Any Pass2Visitor::visitStr(mmcParser::StrContext *ctx)
{
	// cout << "\tvisitStr" << ctx->getText() << endl;
	string value = ctx->STRING()->getText();
	j_file << "\tldc\t" << value << endl;
	return visitChildren(ctx);
}

antlrcpp::Any Pass2Visitor::visitPrintfStatement(mmcParser::PrintfStatementContext *ctx)
{
	
    // cout << "\tvisitPrintfStatement" << ctx->getText() << endl;

    j_file << "\tgetstatic java/lang/System/out Ljava/io/PrintStream;" << endl;
    auto value = visit(ctx->str());

    if(ctx->identifiers() != NULL)
    {
    	int identifier_count = ctx->identifiers()->expression().size();


    	j_file << "\tldc\t" << identifier_count << endl;
    	j_file << "\tanewarray java/lang/Object" << endl;



    	for(int i = 0; i < identifier_count; i++)
    	{
    		j_file << "\tdup" << endl;
    		j_file << "\tldc\t" << i << endl;
    		visit(ctx->identifiers()->expression(i));
    		TypeSpec *type = ctx->identifiers()->expression(i)->type;
    		if(type == Predefined::integer_type || type == Predefined::boolean_type)
    		{
    			j_file << "\tinvokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;" << endl;
    		}
    		j_file << "\taastore" << endl;
    	}

    	j_file << "\tinvokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;" << endl;
    }

	j_file << "\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V" << endl;
	return value;
}

antlrcpp::Any Pass2Visitor::visitArrayDeclaration(mmcParser::ArrayDeclarationContext *ctx)
{
	// cout << "\tvisitArrayDeclaration" << ctx->getText() << endl;
	auto value = visitChildren(ctx);
	string type_indicator;
	if(ctx->typeID()->IDENTIFIER()->toString() == "int"){ //change this maybe
		j_file << "\tnewarray int" << endl;
		type_indicator = "[I";
	}
	else if(ctx->typeID()->IDENTIFIER()->toString() == "bool"){
		j_file << "\tnewarray bool" << endl;
		type_indicator = "[Z";
	}
	else if(ctx->typeID()->IDENTIFIER()->toString() == "string"){
		j_file << "\tanewarray java/lang/String" << endl;
		type_indicator = "[Ljava/lang/String;";
	}
	else{
		type_indicator = EXCEPTION("Invalid Type");
	}

	j_file << "\tputstatic\t" << program_name
			   << "/" << function_name << ctx->variableID()->IDENTIFIER()->toString()
			   << " " << type_indicator << endl;

	return value;
}

antlrcpp::Any Pass2Visitor::visitVariableDef(mmcParser::VariableDefContext *ctx)
{
	// cout << "\tvisitVariableDef" << ctx->getText() << endl;

	auto value = visit(ctx->expression());

	string type_indicator =
				  (ctx->expression()->type == Predefined::integer_type) ? "I"
				: (ctx->expression()->type == Predefined::boolean_type) ? "Z"
				: (ctx->expression()->type == Predefined::char_type)    ? "Ljava/lang/String;"
				:                                                   EXCEPTION("Invalid Type");

	// Emit a field put instruction.
	j_file << "\tputstatic\t" << program_name
		   << "/" << function_name << ctx->variableID()->IDENTIFIER()->toString()
		   << " " << type_indicator << endl;

	return value;
}

antlrcpp::Any Pass2Visitor::visitArrayDef(mmcParser::ArrayDefContext *ctx)
{
	// cout << "\tvisitArrayDef" << ctx->getText() << endl;
	visit(ctx->typeID());
	visit(ctx->variableID());
	visit(ctx->number());

	int nums =  ctx->identifiers()->expression().size();
	string type_indicator;
	string store;
	if(ctx->typeID()->IDENTIFIER()->toString() == "int"){
		j_file << "\tnewarray int" << endl;
		type_indicator = "[I";
		store = "iastore";
	}
	else if(ctx->typeID()->IDENTIFIER()->toString() == "bool"){
		j_file << "\tnewarray bool" << endl;
		type_indicator = "[Z";
		store = "iastore";
	}
	else if(ctx->typeID()->IDENTIFIER()->toString() == "string"){
		j_file << "\tanewarray java/lang/String" << endl;
		type_indicator = "[Ljava/lang/String;";
		store = "aastore";
	}
	else{
		type_indicator = EXCEPTION("Invalid Type");
	}

	string varID = ctx->variableID()->IDENTIFIER()->toString();
	j_file << "\tputstatic\t" << program_name
			   << "/" << function_name << varID
			   << " " << type_indicator << endl;

	if(stoi(ctx->number()->getText()) == nums) {
		for (int i = 0; i < nums; i++) {
			j_file << "\tgetstatic\t" << program_name << "/" << function_name <<  varID << " " << type_indicator << endl;
			j_file << "\tldc " << i << endl;
			visit(ctx->identifiers()->expression(i));
			j_file << "\t" << store <<endl;

		}
	}
	//more elements than array size ~ truncate (premature end)
	else if(stoi(ctx->number()->getText()) < nums) {
		for (int i = 0; i < stoi(ctx->number()->getText()); i++) {
			j_file << "\tgetstatic\t" << program_name << "/" << function_name <<  varID << " " << type_indicator << endl;
			j_file << "\tldc " << i << endl;
			visit(ctx->identifiers()->expression(i));
			j_file << "\t" << store <<endl;
		}
	}
	//less elements than array size
	else {
		int i;
		for (i = 0; i < nums; i++) {
			j_file << "\tgetstatic\t" << program_name << "/" << function_name << varID << " " << type_indicator << endl;
			j_file << "\tldc " << i << endl;
			visit(ctx->identifiers()->expression(i));
			j_file << "\t" << store <<endl;
		}
		//add zeros
		for(; i<stoi(ctx->number()->getText()); i++){
			j_file << "\tgetstatic\t" << program_name << "/" << function_name << varID << " " << type_indicator << endl;
			j_file << "\tldc " << i << endl;
			j_file << "\tldc 0" <<endl;
			j_file << "\t" << store <<endl;
		}
	}
	return NULL;
}

antlrcpp::Any Pass2Visitor::visitArrayExpr(mmcParser::ArrayExprContext *ctx)
{
	// cout << "\tvisitArrayExpr" << ctx->getText() << endl;
	string variable_name = ctx->variable()->IDENTIFIER()->getText();

    string type_indicator =
                  (ctx->type == Predefined::integer_type) ? "[I"
			    : (ctx->type == Predefined::char_type) ? "[Ljava/lang/String;"
                :                                                         EXCEPTION("Invalid Type");

    string load =
                   (ctx->type == Predefined::integer_type) ? "iaload"
 			    : (ctx->type == Predefined::char_type) ? "aaload"
                 :                                                         EXCEPTION("Invalid Type");
	j_file << "\tgetstatic " <<  program_name << "/" << function_name << variable_name << " " << type_indicator << endl;
	auto value = visit(ctx->expression());
	j_file << "\t" << load << endl;
	return value;
}

antlrcpp::Any Pass2Visitor::visitBitIndexAssignment(mmcParser::BitIndexAssignmentContext *ctx)
{
    // cout << "\tvisitBitIndexAssignment" << ctx->getText() << endl;
    string type_indicator =
                  (ctx->expression(1)->type == Predefined::integer_type) ? "I"
                :                                                         EXCEPTION("Invalid Type");

    string variable_name = ctx->variable()->IDENTIFIER()->getText();
    
    int label_set = label_num++;
    int label_clear = label_num++;
    int label_end   = label_num++;
    visit(ctx->expression(1));
    j_file << "\tldc 0" << endl;
    j_file << "\tif_icmpeq" << " Label_" << label_clear << endl;
    j_file << "\tgoto Label_" << label_set << endl;

    // set bit
    j_file << "Label_" << label_set << ":" << endl;
    j_file << "\tgetstatic\t" << program_name << "/" << function_name << variable_name << " " << type_indicator << endl;
    j_file << "\ticonst_1" << endl;
    auto value = visit(ctx->expression(0));
    j_file << "\tishl" << endl;
    j_file << "\tior"  << endl;
    j_file << "\tgoto Label_" << label_end << endl;
    // clear bit
    j_file << "Label_" << label_clear << ":" << endl;
    j_file << "\tgetstatic\t" << program_name << "/" << function_name << variable_name << " " << type_indicator << endl;
    j_file << "\ticonst_1" << endl;
    value = visit(ctx->expression(0));
    j_file << "\tishl" << endl;
    j_file << "\tineg"  << endl;
    j_file << "\ticonst_1" << endl;
    j_file << "\tisub" << endl;
    j_file << "\tiand" << endl;

    j_file << "Label_" << label_end << ":" << endl;
    j_file << "\tputstatic\t" << program_name << "/" << function_name << variable_name << " " << type_indicator << endl;
    return value;
}

antlrcpp::Any  Pass2Visitor::visitBitIndexExpr(mmcParser::BitIndexExprContext *ctx)
{
//    cout << "\tvisitBitIndexExpr" << ctx->getText() << endl;
    string variable_name = ctx->variable()->IDENTIFIER()->getText();
    string type_indicator =
                  (ctx->variable()->type == Predefined::integer_type) ? "I"
                :                                                         EXCEPTION("Invalid Type");

    j_file << "\tgetstatic\t" << program_name << "/" << function_name << variable_name << " " << type_indicator << endl;
    auto value = visit(ctx->expression());
    j_file << "\tishr" << endl;
    j_file << "\ticonst_1" << endl;
    j_file << "\tiand" << endl;
    
    return value;
}

antlrcpp::Any Pass2Visitor::visitVariableAssignment(mmcParser::VariableAssignmentContext *ctx)
{
	// cout << "\tvisitVariableAssignment" << ctx->getText() << endl;
	auto value = visit(ctx->expression());

	string type_indicator =
				  (ctx->expression()->type == Predefined::integer_type) ? "I"
				: (ctx->expression()->type == Predefined::boolean_type) ? "Z"
				: (ctx->expression()->type == Predefined::char_type)    ? "Ljava/lang/String;"
				:                                                         EXCEPTION("Invalid Type");

	// Emit a field put instruction.
	j_file << "\tputstatic\t" << program_name
		   << "/" << function_name <<  ctx->variable()->IDENTIFIER()->toString()
		   << " " << type_indicator << endl;

	return value;
}

antlrcpp::Any Pass2Visitor::visitArrayAssignment(mmcParser::ArrayAssignmentContext *ctx)
{
	// cout << "\tvisitArrayAssignment" << ctx->getText() << endl;
	string type_indicator =
				  (ctx->expression(0)->type == Predefined::integer_type) ? "[I"
				: (ctx->expression(0)->type == Predefined::boolean_type) ? "[Z"
				: (ctx->expression(0)->type == Predefined::char_type)    ? "[Ljava/lang/String;"
				:                                                         EXCEPTION("Invalid Type");

	string store =
				  (ctx->expression(0)->type == Predefined::integer_type) ? "iastore"
				: (ctx->expression(0)->type == Predefined::boolean_type) ? "iastore"
				: (ctx->expression(0)->type == Predefined::char_type)    ? "aastore"
				:                                                         EXCEPTION("Invalid Type");
	string varID = ctx->variable()->getText();

	j_file << "\tgetstatic\t" << program_name << "/" << function_name << varID << " " << type_indicator << endl;
	visit(ctx->expression(0));
	visit(ctx->expression(1));
	j_file << "\t" << store <<endl;

	return NULL;
}



