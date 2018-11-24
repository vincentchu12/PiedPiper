#include <iostream>
#include <fstream>
#include "string.h"


#include "antlr4-runtime.h"
#include "mmcLexer.h"
#include "mmcParser.h"
#include "Pass1Visitor.h"
#include "Pass2Visitor.h"

using namespace std;
using namespace antlrcpp;
using namespace antlr4;

string program_name;

int main(int argc, const char *args[])
{
    ifstream ins;
    program_name = args[1];
    program_name = program_name.substr(0, program_name.find("."));
    ins.open(args[1]);

    ANTLRInputStream input(ins);
    mmcLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    mmcParser parser(&tokens);
    tree::ParseTree *tree = parser.root();

    Pass1Visitor *pass1 = new Pass1Visitor();
    pass1->visit(tree);


   // ostream& j_file = pass1->get_assembly_file();

   // Pass2Visitor *pass2 = new Pass2Visitor(j_file);
   // pass2->visit(tree);

//    delete tree;
    return 0;
}
