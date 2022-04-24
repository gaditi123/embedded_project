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
int countAND=0;
int countOR = 0;
int countNOT = 0;

char result[] = "C:\\Users\\HP'\\Desktop\\semester 5\\Embedded System\\embedded_project\\result.dot";
//char result[] = "D:\\embedded_project\\result.dot";
ofstream fout(result);

void help(vector<string> &answerVariable, vector<string> &operands, string operatorArgument){
    if(operatorArgument == "+"){
        countPlus++;
        char plusChar = countPlus + '0';
        operatorsMap["+"][4] = plusChar;
        fout<<operatorsMap["+"]<<endl;
        fout<<operands[0]<<" -> plus"<<plusChar<<";"<<endl;
        fout<<operands[1]<<" -> plus"<<plusChar<<";"<<endl;
        fout<<"plus"<<plusChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "-"){
        countMinus++;
        char minusChar = countMinus + '0';
        operatorsMap["-"][5] = minusChar;
        fout<<operatorsMap["-"]<<endl;
        fout<<operands[0]<<" -> minus"<<minusChar<<";"<<endl;
        fout<<operands[1]<<" -> minus"<<minusChar<<";"<<endl;
        fout<<"minus"<<minusChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "*"){
        countMultiply++;
        char multiplyChar = countMultiply + '0';
        operatorsMap["*"][8] = multiplyChar;
        fout<<operatorsMap["*"]<<endl;
        fout<<operands[0]<<" -> multiply"<<multiplyChar<<";"<<endl;
        fout<<operands[1]<<" -> multiply"<<multiplyChar<<";"<<endl;
        fout<<"multiply"<<multiplyChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "/"){
        countDivide++;
        char divideChar = countDivide + '0';
        operatorsMap["/"][6] = divideChar;
        fout<<operatorsMap["/"]<<endl;
        fout<<operands[0]<<" -> divide"<<divideChar<<";"<<endl;
        fout<<operands[1]<<" -> divide"<<divideChar<<";"<<endl;
        fout<<"divide"<<divideChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "%"){
        countModulo++;
        char moduloChar = countModulo + '0';
        operatorsMap["%"][6] = moduloChar;
        fout<<operatorsMap["%"]<<endl;
        fout<<operands[0]<<" -> modulo"<<moduloChar<<";"<<endl;
        fout<<operands[1]<<" -> modulo"<<moduloChar<<";"<<endl;
        fout<<"modulo"<<moduloChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "**"){
        countExponent++;
        char exponentChar = countExponent + '0';
        operatorsMap["**"][8] = exponentChar;
        fout<<operatorsMap["**"]<<endl;
        fout<<operands[0]<<" -> exponent"<<exponentChar<<";"<<endl;
        fout<<operands[1]<<" -> exponent"<<exponentChar<<";"<<endl;
        fout<<"exponent"<<exponentChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }else if(operatorArgument == "^"){
        countXOR++;
        char xorChar = countXOR + '0';
        operatorsMap["^"][3] = xorChar;
        fout<<operatorsMap["^"]<<endl;
        fout<<operands[0]<<" -> xor"<<xorChar<<";"<<endl;
        fout<<operands[1]<<" -> xor"<<xorChar<<";"<<endl;
        fout<<"xor"<<xorChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }
    else if(operatorArgument == "&"){
        countAND++;
        char andChar = countAND + '0';
        operatorsMap["&"][3] = andChar;
        fout<<operatorsMap["&"]<<endl;
        fout<<operands[0]<<" -> and"<<andChar<<";"<<endl;
        fout<<operands[1]<<" -> and"<<andChar<<";"<<endl;
        fout<<"and"<<andChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }
    else if(operatorArgument == "|"){
        countOR++;
        char orChar = countOR + '0';
        operatorsMap["|"][2] = orChar;
        fout<<operatorsMap["|"]<<endl;
        fout<<operands[0]<<" -> or"<<orChar<<";"<<endl;
        fout<<operands[1]<<" -> or"<<orChar<<";"<<endl;
        fout<<"or"<<orChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }
    else if(operatorArgument == "~"){
        countNOT++;
        char notChar = countNOT + '0';
        operatorsMap["~"][3] = notChar;
        fout<<operatorsMap["~"]<<endl;
        fout<<operands[0]<<" -> not"<<notChar<<";"<<endl;
        fout<<operands[1]<<" -> not"<<notChar<<";"<<endl;
        fout<<"not"<<notChar<<"-> "<<answerVariable[0]<<";"<<endl;
    }
}

int main(){

    vector<string> ignoreStatements = {"module", "reg", "initial", "$display", "end", "endmodule"};

    operatorsMap.insert({"=", "equali [label = <&#061;>]"});
    operatorsMap.insert({"+", "plusi [label = <&#043;>]"});
    operatorsMap.insert({"-", "minusi [label = <&#045;>]"});
    operatorsMap.insert({"*", "multiplyi [label = <&#042;>]"});
    operatorsMap.insert({"/", "dividei [label = <&#047;>]"});
    operatorsMap.insert({"%", "moduloi [label = <&#037;>]"});
    operatorsMap.insert({"**", "exponenti [label = <&#094;>]"});
    operatorsMap.insert({"&", "andi [label = <&#038;>]"});
    operatorsMap.insert({"|", "ori [label = <&#124;>]"});
    operatorsMap.insert({"~", "noti [label = <&#126;>]"});
    operatorsMap.insert({"^", "xori [label = <&#8853;>]"});

    fout << "digraph result {" << endl;
    
    ifstream testFile;
    testFile.open("test.txt");
    vector<string> variableNames;
    vector<int> variableValues;
    vector<string> answerVariable;
    vector<string> operands;
    vector<string> operators;

    if (testFile.is_open()) {
        string str; 
        while (getline(testFile, str))
        {
            bool found = false;
            for(auto ignore : ignoreStatements){
                if (str.find(ignore) != string::npos) {
                    found = true;
                    break;
                }
            }
            if(!found){
                string word;
                istringstream ss(str);

                int variableDetectionCounter = 0;
                int equationDetectionCounter = 0;

                if(str.length() == 12){
                    variableDetectionCounter = 0;
                    countEqual++;
                    char equalChar = countEqual + '0';
                    operatorsMap["="][5] = equalChar;
                    fout<<operatorsMap["="]<<endl;
                    while (ss >> word) 
                    {
                       if(variableDetectionCounter == 0) 
                       {    
                           variableNames.push_back(word);
                           fout<<"equal"<<equalChar<<" -> "<< word <<";"<<endl;
                       }
                       else if(variableDetectionCounter == 2) {
                           variableValues.push_back(stoi(word));
                           fout<<word<<" -> "<< "equal" << equalChar<< ";"<<endl;
                       }
                       variableDetectionCounter++;
                    }
                }else{
                    equationDetectionCounter = 0;
                    string operatorArgument;
                    while (ss >> word) 
                    {
                        if(equationDetectionCounter == 0){
                            answerVariable.push_back(word);
                        }else if(equationDetectionCounter == 2 or equationDetectionCounter == 4){
                            operands.push_back(word);
                        }else if(equationDetectionCounter == 3){
                            operatorArgument = word;
                        }
                        equationDetectionCounter++;
                    }
                    help(answerVariable, operands, operatorArgument);
                    answerVariable.clear();
                    operands.clear();
                }
                 
            }
        }    
    }

    fout<<"}"<<endl;
    testFile.close();

    return 0;
}