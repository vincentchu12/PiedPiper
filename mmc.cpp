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
unordered_map<string, int> sizeTable;


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

    // cout << "+--------------------+" << endl;
    // cout << "|                    |" << endl;
    // cout << "|   Pass 1 Visitor   |" << endl;
    // cout << "|                    |" << endl;
    // cout << "+--------------------+" << endl;

    Pass1Visitor *pass1 = new Pass1Visitor();
    pass1->visit(tree);

    // cout << "+--------------------+" << endl;
    // cout << "|                    |" << endl;
    // cout << "|   Pass 2 Visitor   |" << endl;
    // cout << "|                    |" << endl;
    // cout << "+--------------------+" << endl;

    ostream& j_file = pass1->get_assembly_file();

    Pass2Visitor *pass2 = new Pass2Visitor(j_file);
    pass2->visit(tree);
    return 0;
}
