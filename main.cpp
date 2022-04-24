#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<string> ignoreStatements = {"module", "reg", "initial", "$display", "end", "endmodule"};

    char result[] = "C:\\Users\\HP'\\Desktop\\semester 5\\Embedded System\\embedded_project\\result.dot";
    ofstream fout(result);
    fout << "digraph result {" << endl;
    fout<<"equal1 [label = <&#061;>]"<<endl;
    fout<<"equal2 [label = <&#061;>]"<<endl;
    fout<<"plus [label = <&#043;>]"<<endl;
    fout<<"minus [label = <&#045;>]"<<endl;
    fout<<"multiply [label = <&#042;>]"<<endl;
    fout<<"divide [label = <&#047;>]"<<endl;
    fout<<"modulo [label = <&#037;>]"<<endl;
    fout<<"raisedTo [label = <&#094;>]"<<endl;
    
    
    ifstream testFile;
    testFile.open("test.txt");
    vector<string> variableNames;
    vector<int> variableValues;
    vector<string> answerVariable;
    vector<string> operands;
    vector<string> operators;
    int equationNumber = 0;

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
                string data, equal, operand1, operand2, semiColon;
                istringstream ss(str);
                string word;

                int variableDetectionCounter = 0;
                int equationDetectionCounter = 0;
                

                if(str.length() == 12){
                    variableDetectionCounter = 0;
                    while (ss >> word) 
                    {
                       // cout << word << "\n";
                       if(variableDetectionCounter==0) 
                       {    
                           variableNames.push_back(word);
                           //fout << "equal1 -> " << word << ";"<<endl;
                       }
                       else if(variableDetectionCounter==2) {
                           variableValues.push_back(stoi(word));
                           //fout << word << "-> equal1;"<<endl;
                       }
                       variableDetectionCounter++;
                    }
                }else{
                    equationDetectionCounter = 0;
                   // cout <<"equation number:"<< equationNumber << "\n";
                    vector<string> tempOperands;
                    while (ss >> word) 
                    {
                        cout << word << "\n";

                        if(equationDetectionCounter == 0)
                            answerVariable.push_back(word);
                        
                        else if(equationDetectionCounter == 2 or equationDetectionCounter==4)
                            operands.push_back(word);
                            
                        else if(equationDetectionCounter==3)
                            operators.push_back(word);

                        equationDetectionCounter++;
                        
                    }
                }
                 
            }
        }    
    }

    cout << "\n\n results\n";
    vector<string> equalOperatorNames{"equal1", "equal2"};
    for (int i = 0; i < answerVariable.size();i++){
        cout << answerVariable[i]<<"\n";
        cout << operators[i] << "\n";
        fout << equalOperatorNames[i] << " -> " << answerVariable[i] << ";" << endl;
        fout << operators[i] << " -> " << equalOperatorNames[i] << ";" << endl;
    }
    cout << "operands\n";
    for (int i = 0; i < operands.size();i++){
        cout << operands[i]<<"\n";
    }
    fout<<"}"<<endl;
        testFile.close();
    return 0;
}