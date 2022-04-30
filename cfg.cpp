#include <bits/stdc++.h>

using namespace std;

char result[] = "C:\\Users\\HP'\\Desktop\\semester 5\\Embedded System\\embedded_project\\resultCFG.dot";
// char result[] = "D:\\embedded_project\\resultCFG.dot";
ofstream fout(result);

int main()
{

    vector<string> ignoreStatements = {"module", "reg", "initial", "$display", "end", "endmodule"};

    fout << "digraph result {" << endl;

    ifstream testFile;
    testFile.open("cfgTest.txt");

    if (testFile.is_open())
    {
        string str, ifCondition, elseIfCondition, elseCondition, previousCondition;
        while (getline(testFile, str))
        {
            bool found = false;
            string word;
            istringstream ss(str);
            if (str.substr(0, 3) == "if(")
            {
                previousCondition = "if";
                ifCondition = str.substr(3);
                ifCondition = ifCondition.substr(0, ifCondition.size() - 1);
                ifCondition = ifCondition.substr(0, ifCondition.size() - 1);
                fout << "Start -> \"" << ifCondition << "\";" << endl;
                getline(testFile, str);
                str = str.substr(0, str.size() - 1);
                fout << "\"" << ifCondition << "\" [shape = box fillcolor = tan, style = filled ] ;\n";
                fout << "\"" << ifCondition << "\" -> \"" << str << "\" [ label=\" True \" ] ;" << endl;
            }
            else if (str.substr(0, 9) == "}else if(")
            {
                if (previousCondition == "else if")
                {
                    string currentElseIfCondition = str.substr(9);
                    currentElseIfCondition = currentElseIfCondition.substr(0, currentElseIfCondition.size() - 1);
                    currentElseIfCondition = currentElseIfCondition.substr(0, currentElseIfCondition.size() - 1);
                    getline(testFile, str);
                    str = str.substr(0, str.size() - 1);
                    fout << "\"" << elseIfCondition << "\" [shape = box, fillcolor = tan, style = filled] ;\n";
                    fout << "\"" << elseIfCondition << "\" -> \"" << currentElseIfCondition << "\" [ label=\" False \" ] ;" << endl;
                    fout << "\"" << currentElseIfCondition << "\" [shape = box, fillcolor = tan, style = filled] ;\n";
                    fout << "\"" << currentElseIfCondition << "\" -> \"" << str << "\" [ label=\" True \" ] ;" << endl;
                    elseIfCondition = currentElseIfCondition;
                }
                else if (previousCondition == "if")
                {
                    elseIfCondition = str.substr(9);
                    elseIfCondition = elseIfCondition.substr(0, elseIfCondition.size() - 1);
                    elseIfCondition = elseIfCondition.substr(0, elseIfCondition.size() - 1);
                    getline(testFile, str);
                    str = str.substr(0, str.size() - 1);
                    fout << "\"" << ifCondition << "\" [shape = box, fillcolor = tan, style = filled ] ;\n";
                    fout << "\"" << ifCondition << "\" -> \"" << elseIfCondition << "\" [ label=\" False \" ] ;" << endl;
                    fout << "\"" << elseIfCondition << "\" [shape = box, fillcolor = tan, style = filled ] ;\n";
                    fout << "\"" << elseIfCondition << "\" -> \"" << str << "\" [ label=\" True \" ] ;" << endl;
                }
                previousCondition = "else if";
            }
            else if (str.substr(0, 6) == "}else{")
            {
                getline(testFile, str);
                str = str.substr(0, str.size() - 1);
                fout << "\"" << elseIfCondition << "\" -> \"" << str << "\" [ label=\" False \" ] ;" << endl;
            }
        }
    }

    fout << "}" << endl;
    testFile.close();

    return 0;
}