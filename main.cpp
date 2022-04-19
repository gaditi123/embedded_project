#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<string> ignoreStatements = {"module", "reg", "initial", "$display", "end", "endmodule"};

    ifstream testFile;
    testFile.open("test.txt");
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
                istringstream ss(str);
                string word;
                int count = 0;
                if(str.length() == 12){
                    while (ss >> word) 
                    {
                        cout << word << "\n";
                    }
                }else{
                    while (ss >> word) 
                    {
                        cout << "assignment " << word << "\n";
                    }
                }
            }
        }    
    }
    testFile.close();
    return 0;
}