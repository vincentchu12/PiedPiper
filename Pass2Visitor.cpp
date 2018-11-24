#include <iostream>
#include <string>

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


antlrcpp::Any Pass2Visitor::visitRoot(mmcParser::RootContext *ctx)
{
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

antlrcpp::Any Pass2Visitor::visitDeclaration(mmcParser::DeclarationContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitDefinition(mmcParser::DefinitionContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitFunctionDeclaration(mmcParser::FunctionDeclarationContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitFunctionDefinition(mmcParser::FunctionDefinitionContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitFunctionCall(mmcParser::FunctionCallContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitParameters(mmcParser::ParametersContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitIdentifiers(mmcParser::IdentifiersContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitTypeID(mmcParser::TypeIDContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitVariable(mmcParser::VariableContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitStatement(mmcParser::StatementContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitDeclarationStatement(mmcParser::DeclarationStatementContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitDefinitionStatement(mmcParser::DefinitionStatementContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitExpressionStatement(mmcParser::ExpressionStatementContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitIfStatement(mmcParser::IfStatementContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitForStatement(mmcParser::ForStatementContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitUnaryStatement(mmcParser::UnaryStatementContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitStatementList(mmcParser::StatementListContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitAssignmentStatement(mmcParser::AssignmentStatementContext *ctx)
{
    auto value = visit(ctx->assignment()->expression());

    string type_indicator =
                  (ctx->assignment()->expression()->type == Predefined::integer_type) ? "I"
                : (ctx->assignment()->expression()->type == Predefined::boolean_type) ? "Z"
                :                                                      "?";

    // Emit a field put instruction.
    j_file << "\tputstatic\t" << program_name
           << "/" << ctx->assignment()->variable()->IDENTIFIER()->toString()
           << " " << type_indicator << endl;

    return value;
}

antlrcpp::Any Pass2Visitor::visitVariableExpr(mmcParser::VariableExprContext *ctx)
{
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

antlrcpp::Any Pass2Visitor::visitBitExpr(mmcParser::BitExprContext *ctx)
{
    auto value = visitChildren(ctx);

    TypeSpec *type1 = ctx->expression(0)->type;
    TypeSpec *type2 = ctx->expression(1)->type;

    bool integer_mode =    (type1 == Predefined::integer_type)
                        && (type2 == Predefined::integer_type);

    string op = ctx->BIT_OP()->getText();
    string opcode;

    if (op == "&")
    {
        opcode = integer_mode ? "iand"
               :                "????";
    }
    else if (op == "|")
    {
        opcode = integer_mode ? "ior"
               :                "????";
    }
    else
    {
        opcode = integer_mode ? "ixor"
               :                "????";
    }

    // Emit a multiply or divide instruction.
    j_file << "\t" << opcode << endl;

    return value;
}

antlrcpp::Any Pass2Visitor::visitAddSubExpr(mmcParser::AddSubExprContext *ctx)
{
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

antlrcpp::Any Pass2Visitor::visitArrayExpr(mmcParser::ArrayExprContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitMathExpr(mmcParser::MathExprContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitNumberExpr(mmcParser::NumberExprContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitLogicExpr(mmcParser::LogicExprContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitMulDivModExpr(mmcParser::MulDivModExprContext *ctx)
{
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
        opcode = integer_mode ? "idpv"
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

antlrcpp::Any Pass2Visitor::visitFuncCallExpr(mmcParser::FuncCallExprContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitParenExpr(mmcParser::ParenExprContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitPreInc(mmcParser::PreIncContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitPreDec(mmcParser::PreDecContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitPostInc(mmcParser::PostIncContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitPostDec(mmcParser::PostDecContext *ctx)
{

}

antlrcpp::Any Pass2Visitor::visitAssignment(mmcParser::AssignmentContext *ctx)
{

}

