#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> operatorsMap;

int countEqual = 0;
int countPlus = 0;
int countMinus = 0;
int countMultiply = 0;
int countDivide = 0;
int countModulo = 0;
int countExponent = 0;
int countXOR = 0;
int countAND = 0;
int countOR = 0;
int countNOT = 0;

// char result[] = "C:\\Users\\HP'\\Desktop\\semester 5\\Embedded System\\embedded_project\\resultCombined.dot";
char result[] = "D:\\embedded_project\\resultCombined.dot";
ofstream fout(result);

void help(vector<string> &answerVariable, vector<string> &operands, string operatorArgument)
{
   if(operatorArgument == "+"){
        countPlus++;
        char plusChar = countPlus + '0';
        operatorsMap["+"][4] = plusChar;
        fout<<operatorsMap["+"]<<endl;
        fout<<operands[0]<<" -> plus"<<plusChar<<";"<<endl;
        fout<<operands[1]<<" -> plus"<<plusChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout << "plus" << plusChar << "-> " << answerVariable[0] << ";" << endl;
    }else if(operatorArgument == "-"){
        countMinus++;
        char minusChar = countMinus + '0';
        operatorsMap["-"][5] = minusChar;
        fout<<operatorsMap["-"]<<endl;
        fout<<operands[0]<<" -> minus"<<minusChar<<";"<<endl;
        fout<<operands[1]<<" -> minus"<<minusChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout<<"minus"<<minusChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "*"){
        countMultiply++;
        char multiplyChar = countMultiply + '0';
        operatorsMap["*"][8] = multiplyChar;
        fout<<operatorsMap["*"]<<endl;
        fout<<operands[0]<<" -> multiply"<<multiplyChar<<";"<<endl;
        fout<<operands[1]<<" -> multiply"<<multiplyChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout<<"multiply"<<multiplyChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "/"){
        countDivide++;
        char divideChar = countDivide + '0';
        operatorsMap["/"][6] = divideChar;
        fout<<operatorsMap["/"]<<endl;
        fout<<operands[0]<<" -> divide"<<divideChar<<";"<<endl;
        fout<<operands[1]<<" -> divide"<<divideChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout<<"divide"<<divideChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "%"){
        countModulo++;
        char moduloChar = countModulo + '0';
        operatorsMap["%"][6] = moduloChar;
        fout<<operatorsMap["%"]<<endl;
        fout<<operands[0]<<" -> modulo"<<moduloChar<<";"<<endl;
        fout<<operands[1]<<" -> modulo"<<moduloChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout<<"modulo"<<moduloChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "**"){
        countExponent++;
        char exponentChar = countExponent + '0';
        operatorsMap["**"][8] = exponentChar;
        fout<<operatorsMap["**"]<<endl;
        fout<<operands[0]<<" -> exponent"<<exponentChar<<";"<<endl;
        fout<<operands[1]<<" -> exponent"<<exponentChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout<<"exponent"<<exponentChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "^"){
        countXOR++;
        char xorChar = countXOR + '0';
        operatorsMap["^"][3] = xorChar;
        fout<<operatorsMap["^"]<<endl;
        fout<<operands[0]<<" -> xor"<<xorChar<<";"<<endl;
        fout<<operands[1]<<" -> xor"<<xorChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout<<"xor"<<xorChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }
    else if(operatorArgument == "&"){
        countAND++;
        char andChar = countAND + '0';
        operatorsMap["&"][3] = andChar;
        fout<<operatorsMap["&"]<<endl;
        fout<<operands[0]<<" -> and"<<andChar<<";"<<endl;
        fout<<operands[1]<<" -> and"<<andChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout<<"and"<<andChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }
    else if(operatorArgument == "|"){
        countOR++;
        char orChar = countOR + '0';
        operatorsMap["|"][2] = orChar;
        fout<<operatorsMap["|"]<<endl;
        fout<<operands[0]<<" -> or"<<orChar<<";"<<endl;
        fout<<operands[1]<<" -> or"<<orChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout<<"or"<<orChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }
    else if(operatorArgument == "~"){
        countNOT++;
        char notChar = countNOT + '0';
        operatorsMap["~"][3] = notChar;
        fout<<operatorsMap["~"]<<endl;
        fout<<operands[0]<<" -> not"<<notChar<<";"<<endl;
        fout<<operands[1]<<" -> not"<<notChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout<<"not"<<notChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }
}

string mainFunctionHelper(string str)
{

    // vector<string> ignoreStatements = {"module", "reg", "initial", "$display", "end", "endmodule"};

    operatorsMap.insert({"=", "equali [label = <&#061;> ,fillcolor=greenyellow, style=filled]"});
    operatorsMap.insert({"+", "plusi [label = <&#043;> ,fillcolor=lightblue, style=filled]"});
    operatorsMap.insert({"-", "minusi [label = <&#045;> ,fillcolor=lightblue, style=filled]"});
    operatorsMap.insert({"*", "multiplyi [label = <&#042;> ,fillcolor=lightblue, style=filled]"});
    operatorsMap.insert({"/", "dividei [label = <&#047;> ,fillcolor=lightblue, style=filled]"});
    operatorsMap.insert({"%", "moduloi [label = <&#037;> ,fillcolor=lightblue, style=filled]"});
    operatorsMap.insert({"**", "exponenti [label = <&#094;> ,fillcolor=lightblue, style=filled]"});
    operatorsMap.insert({"&", "andi [label = <&#038;> ,fillcolor=lightblue, style=filled]"});
    operatorsMap.insert({"|", "ori [label = <&#124;> ,fillcolor=lightblue, style=filled]"});
    operatorsMap.insert({"~", "noti [label = <&#126;> ,fillcolor=lightvlue, style=filled]"});
    operatorsMap.insert({"^", "xori [label = <&#8853;> ,fillcolor=lightblue, style=filled]"});

    vector<string> variableNames;
    vector<int> variableValues;
    vector<string> answerVariable;
    vector<string> operands;
    vector<string> operators;

    string word;
    istringstream ss(str);

    int variableDetectionCounter = 0;
    int equationDetectionCounter = 0;

    if (str.length() == 11)
    {
        variableDetectionCounter = 0;
        countEqual++;
        char equalChar = countEqual + '0';
        operatorsMap["="][5] = equalChar;
        fout << operatorsMap["="] << endl;
        while (ss >> word)
        {
            if (variableDetectionCounter == 0)
            {
                variableNames.push_back(word);
                fout << word << " [fillcolor = lightcoral, style=filled]";
                fout << "equal" << equalChar << " -> " << word << ";" << endl;
            }
            else if (variableDetectionCounter == 2)
            {
                word = word.substr(0, word.size() - 1);
                variableValues.push_back(stoi(word));
                fout << word << " [fillcolor = khaki, style=filled]";
                fout << word << " -> " << "equal" << equalChar << ";" << endl;
                return word;
            }
            variableDetectionCounter++;
        }
    }
    else
    {
        equationDetectionCounter = 0;
        string operatorArgument;
        string returnWord;
        while (ss >> word)
        {
            if (equationDetectionCounter == 0)
            {
                answerVariable.push_back(word);
            }
            else if (equationDetectionCounter == 2 or equationDetectionCounter == 4)
            {
                if (equationDetectionCounter == 4)
                {
                    word = word.substr(0, word.size() - 1);
                }
                operands.push_back(word);
                if (equationDetectionCounter == 2)
                    returnWord = word;
            }
            else if (equationDetectionCounter == 3)
            {
                operatorArgument = word;
            }
            equationDetectionCounter++;
        }
        help(answerVariable, operands, operatorArgument);
        answerVariable.clear();
        operands.clear();

        return returnWord;
    }
    return "10";
}

int main()
{

    vector<string> ignoreStatements = {"module", "reg", "initial", "$display", "end", "endmodule"};

    fout << "digraph result {" << endl;

    ifstream testFile;
    testFile.open("cfgdfgTest.txt");

    if (testFile.is_open())
    {
        string str;
        while (getline(testFile, str))
        {
            bool found = false;
            for (auto ignore : ignoreStatements)
            {
                if (str.find(ignore) != string::npos)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
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
                        getline(testFile, str);
                        cout << str << "\n";
                        string num = mainFunctionHelper(str);
                        str = str.substr(0, str.size() - 1);
                        fout << "\"" << ifCondition << "\" [shape = box fillcolor = tan, style = filled ] ;\n";
                        fout << "\"" << ifCondition << "\" -> \"" << num << "\" [ label=\" True \" ] ;" << endl;
                        getline(testFile, str);
                    }
                    else if (str.substr(0, 9) == "}else if(")
                    {
                        if (previousCondition == "else if")
                        {
                            string currentElseIfCondition = str.substr(9);
                            currentElseIfCondition = currentElseIfCondition.substr(0, currentElseIfCondition.size() - 1);
                            currentElseIfCondition = currentElseIfCondition.substr(0, currentElseIfCondition.size() - 1);
                            getline(testFile, str);
                            getline(testFile, str);
                            cout << str << "\n";
                            string num2 = mainFunctionHelper(str);
                            str = str.substr(0, str.size() - 1);
                            fout << "\"" << elseIfCondition << "\" [shape = box fillcolor = tan, style = filled ] ;\n";
                            fout << "\"" << elseIfCondition << "\" -> \"" << currentElseIfCondition << "\" [ label=\" False \" ] ;" << endl;
                            fout << "\"" << currentElseIfCondition << "\" [shape = box fillcolor = tan, style = filled ] ;\n";
                            fout << "\"" << currentElseIfCondition << "\" -> \"" << num2 << "\" [ label=\" True \" ] ;" << endl;
                            elseIfCondition = currentElseIfCondition;
                            getline(testFile, str);
                        }
                        else if (previousCondition == "if")
                        {
                            elseIfCondition = str.substr(9);
                            elseIfCondition = elseIfCondition.substr(0, elseIfCondition.size() - 1);
                            elseIfCondition = elseIfCondition.substr(0, elseIfCondition.size() - 1);
                            getline(testFile, str);
                            getline(testFile, str);
                            cout << str << "\n";
                            string num3 = mainFunctionHelper(str);
                            str = str.substr(0, str.size() - 1);
                            fout << "\"" << ifCondition << "\" [shape = box fillcolor = tan, style = filled ] ;\n";
                            fout << "\"" << ifCondition << "\" -> \"" << elseIfCondition << "\" [ label=\" False \" ] ;" << endl;
                            fout << "\"" << elseIfCondition << "\" [shape = box fillcolor = tan, style = filled ] ;\n";
                            fout << "\"" << elseIfCondition << "\" -> \"" << num3 << "\" [ label=\" True \" ] ;" << endl;
                            getline(testFile, str);
                        }
                        previousCondition = "else if";
                    }
                    else if (str.substr(0, 6) == "}else{")
                    {
                        getline(testFile, str);
                        getline(testFile, str);
                        string num4 = mainFunctionHelper(str);
                        str = str.substr(0, str.size() - 1);
                        if(previousCondition == "else if"){
                            fout << "\"" << elseIfCondition << "\" -> \"" << num4 << "\" [ label=\" False \" ] ;" << endl;
                        }else{
                            fout << "\"" << ifCondition << "\" -> \"" << num4 << "\" [ label=\" False \" ] ;" << endl;
                        }
                        getline(testFile, str);
                    }
                }
            }
        }
    }

    fout << "}" << endl;
    testFile.close();

    return 0;
}