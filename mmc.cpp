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


void printAss2Visitor()
{
    cout << "                  X XXX XX XX XX XXXXX" << endl;
    cout << "         X XXXXXXX                    XX XX XXXX" << endl;
    cout << "     XXXX                                        X X" << endl;
    cout << "   XXX                                                  X" << endl;
    cout << "  X                                                      XXXX" << endl;
    cout << " X        +----------------------------------------+         XX" << endl;
    cout << "XX        |                                        |          X" << endl;
    cout << "X         |      Pass 2 Visitor                    |           XX" << endl;
    cout << "X         |                                        |            X" << endl;
    cout << "X         |                                        |            X" << endl;
    cout << "XX        +----------------------------------------+            X" << endl;
    cout << " XX                                                             X" << endl;
    cout << "  XXXXX    XXXX  X                       +                     X" << endl;
    cout << "       XXXXX    XX                       |                    X" << endl;
    cout << "                X                        |                   X" << endl;
    cout << "                X                        |" << endl;
    cout << "                 X                       |                 X" << endl;
    cout << "                 XX                      |               XX" << endl;
    cout << "                  XX                     |             X" << endl;
    cout << "                   XX                    |           XX" << endl;
    cout << "                     XX                  |       XXXX" << endl;
    cout << "                       X                 |  XX XXX" << endl;
    cout << "                           XXX X X  X  X |X" << endl;
    cout << "                                         |" << endl;
    cout << "                                         |" << endl;
    cout << "                                         |          +------>" << endl;
    cout << "                                         |          |" << endl;
    cout << "                                         |          |" << endl;
    cout << "                                         |          |" << endl;
    cout << "                                         +------------------->" << endl;
    cout << "                                                    |" << endl;
    cout << "                                                    |" << endl;
    cout << "                                                    +---------->" << endl;
    cout << "" << endl;
}

int main(int argc, const char *args[])
{
    ifstream ins;
    program_name = args[1];
    cout<<program_name<<endl;
    program_name = program_name.substr(0, program_name.find("."));
    ins.open(args[1]);

    ANTLRInputStream input(ins);
    mmcLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    mmcParser parser(&tokens);
    tree::ParseTree *tree = parser.root();

    Pass1Visitor *pass1 = new Pass1Visitor();
    pass1->visit(tree);

    printAss2Visitor();

    ostream& j_file = pass1->get_assembly_file();

    Pass2Visitor *pass2 = new Pass2Visitor(j_file);
    pass2->visit(tree);

    return 0;
}
