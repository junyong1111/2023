#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int>Value;
    
    for(int i=0; i<s.size(); i++){
        string str ="";
        int idx = 0;
        if(s[i+idx] != ' '){
            while(s[i+idx] != ' '){
                str += s[i+idx++];
            }
            Value.push_back(stoi(str));
        }
        
        i = i+idx;
    }
    sort(Value.begin(), Value.end());
    answer += to_string(Value[0]);
    answer += " ";
    answer += to_string(Value[Value.size()-1]);

    return answer;
}