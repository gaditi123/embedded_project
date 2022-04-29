#include <bits/stdc++.h>

using namespace std;

// char result[] = "C:\\Users\\HP'\\Desktop\\semester 5\\Embedded System\\embedded_project\\result1.dot";
char result[] = "D:\\embedded_project\\result.dot";
ofstream fout(result);

int main(){

    vector<string> ignoreStatements = {"module", "reg", "initial", "$display", "end", "endmodule"};

    fout << "digraph result {" << endl;
    
    ifstream testFile;
    testFile.open("cfgTest.txt");

    if (testFile.is_open()) {
        string str, ifCondition, elseIfCondtion, elseCondition, previousCondition; 
        while (getline(testFile, str))
        {
            bool found = false;
            string word;
            istringstream ss(str);
            if(str.substr(0, 3) == "if("){
                previousCondition = "if";
                ifCondition = str.substr(3);
                ifCondition = ifCondition.substr(0, ifCondition.size()-1);
                ifCondition = ifCondition.substr(0, ifCondition.size()-1);
                fout<<"Start -> \""<< ifCondition << "\";"<<endl;
                getline(testFile, str);
                str = str.substr(0, str.size()-1);
                fout<<"\""<< ifCondition << "\" -> \""<<str<<"\" [ label=\" True \" ] ;"<<endl;
            }else if(str.substr(0, 9) == "}else if("){
                if(previousCondition == "else if"){
                    string currentElseIfCondtion = str.substr(9);
                    currentElseIfCondtion = currentElseIfCondtion.substr(0, currentElseIfCondtion.size()-1);
                    currentElseIfCondtion = currentElseIfCondtion.substr(0, currentElseIfCondtion.size()-1);
                    getline(testFile, str);
                    str = str.substr(0, str.size()-1);
                    fout<<"\""<< elseIfCondtion << "\" -> \""<<currentElseIfCondtion<<"\" [ label=\" False \" ] ;"<<endl;
                    fout<<"\""<< currentElseIfCondtion << "\" -> \""<<str<<"\" [ label=\" True \" ] ;"<<endl;
                    elseIfCondtion = currentElseIfCondtion;
                }else if(previousCondition == "if"){
                    elseIfCondtion = str.substr(9);
                    elseIfCondtion = elseIfCondtion.substr(0, elseIfCondtion.size()-1);
                    elseIfCondtion = elseIfCondtion.substr(0, elseIfCondtion.size()-1);
                    getline(testFile, str);
                    str = str.substr(0, str.size()-1);
                    fout<<"\""<< ifCondition << "\" -> \""<<elseIfCondtion<<"\" [ label=\" False \" ] ;"<<endl;
                    fout<<"\""<< elseIfCondtion << "\" -> \""<<str<<"\" [ label=\" True \" ] ;"<<endl;
                }
                previousCondition = "else if";
            }else if(str.substr(0, 6) == "}else{"){
                getline(testFile, str);
                str = str.substr(0, str.size()-1);
                fout<<"\""<< elseIfCondtion << "\" -> \""<<str<<"\" [ label=\" False \" ] ;"<<endl;
            }
        }    
    }

    fout<<"}"<<endl;
    testFile.close();

    return 0;
}