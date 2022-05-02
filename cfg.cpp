#include <bits/stdc++.h>

using namespace std;

//output .dot file path
// char result[] = "C:\\Users\\HP'\\Desktop\\semester 5\\Embedded System\\embedded_project\\resultCFG.dot";
char result[] = "D:\\embedded_project\\resultCFG.dot";
ofstream fout(result);

int main()
{
    //the following statements are ignored/not processed when reading the input verilog file since thet are of no use in making the CFG
    vector<string> ignoreStatements = {"module", "reg", "initial", "$display", "end", "endmodule"};

    fout << "digraph result {" << endl;

    //defining input verilog .txt file and storing it in an ifstream variable
    ifstream testFile;
    testFile.open("cfgTest1.txt");

    //checking if the input file is found and if its opened
    if (testFile.is_open())
    {
        string str, ifCondition, elseIfCondition, elseCondition, previousCondition;
        while (getline(testFile, str))
        {
            string word;
            istringstream ss(str);
            // We check if the current line is an 'if' condition
            if (str.substr(0, 3) == "if(")
            {
                previousCondition = "if";

                // Gets the condition on which the 'if' condition is being evaluated
                ifCondition = str.substr(3);
                ifCondition = ifCondition.substr(0, ifCondition.size() - 1);
                ifCondition = ifCondition.substr(0, ifCondition.size() - 1);
                fout << "Start -> \"" << ifCondition << "\";" << endl;

                // Ignore 'begin' keyword
                getline(testFile, str);
                // Get the operation performed if the 'if' condition is satisfied
                getline(testFile, str);
                str = str.substr(0, str.size() - 1);

                // writing to the output .dot file (Creating a node for the condition on which the 'if' condition is being evaluated)
                fout << "\"" << ifCondition << "\" [shape = box fillcolor = lavender, style = filled ] ;\n";
                // writing to the output .dot file (Creating a node connecting the condition on which the 'if' condition is being evaluated and the operation if the condition is true)
                fout << "\"" << ifCondition << "\" -> \"" << str << "\" [ label=\" True \" ] ;" << endl;
                // Ignore 'end' keyword
                getline(testFile, str);
            }
            else if (str.substr(0, 9) == "}else if(")
            {
                // If the last condition was else-if then we connect new node to the condition stored in 'else-if' condition block
                if (previousCondition == "else if")
                {
                    // Get the current condition being evaluated for 'else-if' condition
                    string currentElseIfCondition = str.substr(9);
                    currentElseIfCondition = currentElseIfCondition.substr(0, currentElseIfCondition.size() - 1);
                    currentElseIfCondition = currentElseIfCondition.substr(0, currentElseIfCondition.size() - 1);
                    // Ignore 'begin' keyword
                    getline(testFile, str);
                    // Get the operation being performed if the 'else-if' condition is satisfied
                    getline(testFile, str);
                    str = str.substr(0, str.size() - 1);
                    // Create new node for current else-if condition and the operation performed if it is true
                    // Link the node to the previous else-if condition
                    fout << "\"" << elseIfCondition << "\" [shape = box, fillcolor = lavender, style = filled] ;\n";
                    fout << "\"" << elseIfCondition << "\" -> \"" << currentElseIfCondition << "\" [ label=\" False \" ] ;" << endl;
                    fout << "\"" << currentElseIfCondition << "\" [shape = box, fillcolor = lavender, style = filled] ;\n";
                    fout << "\"" << currentElseIfCondition << "\" -> \"" << str << "\" [ label=\" True \" ] ;" << endl;
                    elseIfCondition = currentElseIfCondition;
                    // Ignore 'end' keyword
                    getline(testFile, str);
                }
                else if (previousCondition == "if")
                {
                     // Get the current condition being evaluated for 'else-if' condition
                    elseIfCondition = str.substr(9);
                    elseIfCondition = elseIfCondition.substr(0, elseIfCondition.size() - 1);
                    elseIfCondition = elseIfCondition.substr(0, elseIfCondition.size() - 1);
                    // Ignore 'begin' keyword
                    getline(testFile, str);
                    // Get the operation being performed if the 'else-if' condition is satisfied
                    getline(testFile, str);
                    str = str.substr(0, str.size() - 1);
                    // Create new node for current else-if condition and the operation performed if it is true
                    // Link the node to the 'if' condition node
                    fout << "\"" << ifCondition << "\" [shape = box, fillcolor = lavender, style = filled ] ;\n";
                    fout << "\"" << ifCondition << "\" -> \"" << elseIfCondition << "\" [ label=\" False \" ] ;" << endl;
                    fout << "\"" << elseIfCondition << "\" [shape = box, fillcolor = lavender, style = filled ] ;\n";
                    fout << "\"" << elseIfCondition << "\" -> \"" << str << "\" [ label=\" True \" ] ;" << endl;
                    // Ignore 'end' keyword
                    getline(testFile, str);
                }
                previousCondition = "else if";
            }
            else if (str.substr(0, 6) == "}else{")
            {
                // Ignore 'begin' keyword
                getline(testFile, str);
                // Get the operation being performed if all the 'if and else-if' conditions are not satisfied
                getline(testFile, str);
                str = str.substr(0, str.size() - 1);
                // Link to 'else-if' node if the previous condition was an 'else-if' condition
                if(previousCondition == "else if"){
                    fout << "\"" << elseIfCondition << "\" -> \"" << str << "\" [ label=\" False \" ] ;" << endl;
                }else{
                    // Link to 'if' node if the previous condition was an 'if' condition
                    fout << "\"" << ifCondition << "\" -> \"" << str << "\" [ label=\" False \" ] ;" << endl;
                }
                // Ignore 'end' keyword
                getline(testFile, str);
            }
        }
    }

    //marking the end of the output file to which the graph visulation code in Graphviz syntax is being written
    fout << "}" << endl;
    //closing the file from which the verilog code input is being read
    testFile.close();

    return 0;
}