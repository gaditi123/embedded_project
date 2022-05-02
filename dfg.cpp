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

//output .dot file path
char result[] = "C:\\Users\\HP'\\Desktop\\semester 5\\Embedded System\\embedded_project\\resultDFG.dot";
//char result[] = "D:\\embedded_project\\resultDFG.dot";
ofstream fout(result);

//the help function is used to write the equation statements of verilog code to the Graphviz syntax style.
//it takes in the input of the 2 operands, the operator(operatorArgument) and the answerVariable into which the result of the equation is stored
//it has an if-else ladder for each operator called as operatorArgument
void help(vector<string> &answerVariable, vector<string> &operands, string operatorArgument){
    if(operatorArgument == "+"){
        countPlus++;
        char plusChar = countPlus + '0';
        operatorsMap["+"][4] = plusChar;

        //writing to the output .dot file to get the assignment statement graph
        fout<<operatorsMap["+"]<<endl; 
        fout<<operands[0]<<" -> plus"<<plusChar<<";"<<endl;
        fout<<operands[1]<<" -> plus"<<plusChar<<";"<<endl;
        fout << answerVariable[0] << " [fillcolor = lavender, style = filled];\n";
        fout << "plus" << plusChar << "-> " << answerVariable[0] << ";" << endl;
    }else if(operatorArgument == "-"){
        countMinus++;
        char minusChar = countMinus + '0';
        operatorsMap["-"][5] = minusChar;

        //writing to the output .dot file to get the assignment statement graph
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

int main(){

    //the following statements are ignored/not processed when reading the input verilog file since thet are of no use in making the DFG
    vector<string> ignoreStatements = {"module", "reg", "initial", "$display", "end", "endmodule", "wire", "input", "output"};

    //the different assignment and logical operators are being matched to ther UNICODE values to be wriiten to in Graphviz syntax. The color coding is done for all the operators and = sign to help in better visulisation
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

    fout << "digraph result {" << endl;
    
    //defining input verilog .txt file and storing it in an ifstream variable
    ifstream testFile;
    testFile.open("dfgTest4.txt");

    //defining the counter varianles for identifing various parts of the verilog code lines
    vector<string> variableNames;
    vector<int> variableValues;
    vector<string> answerVariable;
    vector<string> operands;
    vector<string> operators;


    if (testFile.is_open()) { //checking if the input file is found and if its opened
        string str; 
        while (getline(testFile, str))
        {
            bool found = false;
            //while parsing the input verilog file if the str retrived has any of the ignoreStatements then control shifts to the next line
            for(auto ignore : ignoreStatements){
                if (str.find(ignore) != string::npos) {
                    found = true;
                    break;
                }
            }
            if(!found){ //this block executes if the current line does not contain any keywords which are part of ignoreStatements
                string word;
                istringstream ss(str);

                int variableDetectionCounter = 0; //used to count the space separated word in assignment statemets
                int equationDetectionCounter = 0; //used to count the space separated word in equation statemets

                //The assignment statements such as datax = 11 ; are of length 11 and its determination of various parts are done in this if block 
                if(str.length() == 11){ 
                    variableDetectionCounter = 0;
                    countEqual++; //counting the number of assignment statements as those many = operatos we will have to output in the Graphviz .dot file
                    char equalChar = countEqual + '0'; //converting number of equal operatos from int to character
                    operatorsMap["="][5] = equalChar; //getting UNICODE vale of = opertor usning the map defined above
                    
                    //fout is used to write the Graphiv syntax to the external .dot file for visulising the DFG
                    fout<<operatorsMap["="]<<endl; //adding the code to output an = operator into the graph

                    //the while loop separetes a string into a list of space separated words and iterates over it
                    while (ss >> word) 
                    {
                        //variableDetectionCounter keeps track of different components of assignment statements
                       //variableDetectionCounter = 0 is to detect the variable name into which the value is getting stored. 
                       if(variableDetectionCounter == 0) 
                       {    
                           variableNames.push_back(word);
                           fout << word << " [fillcolor = lightcoral, style=filled]\n";
                           fout<<"equal"<<equalChar<<" -> "<< word <<";"<<endl;
                       }
                       //variableDetectionCounter = 1 is for the = operator. It is not necessary for us to record this since all assignment operators will have an equal symbol and no new information is gathered.

                       //variableDetectionCounter =2 is to detect the value which is assigned to the variable
                       else if(variableDetectionCounter == 2) {
                           word = word.substr(0, word.size() - 1); // to remove the semicolon in the end
                           variableValues.push_back(stoi(word));
                           fout << word << " [fillcolor = khaki, style=filled]\n";
                           fout<<word<<" -> "<< "equal" << equalChar<< ";"<<endl;
                       }
                       variableDetectionCounter++;
                    }
                }else{
                     //equationDetectionCounter keeps track of different components of equation statements
                    equationDetectionCounter = 0;
                    string operatorArgument;

                    //the while loop separetes a string into a list of space separated words and iterates over it
                    while (ss >> word) 
                    {
                        //equationDetectionCounter = 0 is used to detect the answer variable storing the result of the operation performed
                        if(equationDetectionCounter == 0){
                            answerVariable.push_back(word);
                        }
                        //equationDetectionCounter = 2 or 4 detecs the 2 operands present in the equation
                        else if(equationDetectionCounter == 2 or equationDetectionCounter == 4){
                            if(equationDetectionCounter == 4){
                                word = word.substr(0, word.size()-1);
                            }
                            operands.push_back(word);
                        }
                        //equationDetectionCounter = 3 detects the operand being used on the 2 operators
                        else if(equationDetectionCounter == 3){
                            operatorArgument = word;
                        }
                        equationDetectionCounter++;
                    }
                    //the help() fucntion is called to firstly convert the operator symbol to its UNOCODE representation and also form the nodes and edges representation of the equation statements 
                    help(answerVariable, operands, operatorArgument);

                    //clear the answerVariable and operands list 
                    answerVariable.clear();
                    operands.clear();
                }
                 
            }
        }    
    }

    //marking the end of the output file to which the graph visulation code in Graphviz syntax is being written
    fout<<"}"<<endl;
    //closing the file from which the verilog code input is being read
    testFile.close();

    return 0;
}