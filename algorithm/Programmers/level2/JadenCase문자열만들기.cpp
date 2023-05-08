#include <string>
#include <vector>

using namespace std;

bool is_space(char ch){
    if (ch == 32)
        return true;
    return false;
}

int is_alpha(char ch){
    if(ch >= 'a' && ch <='z')
        return 1;
    if(ch >= 'A' && ch <= 'Z')
        return 2;
    return 0;
}

string solution(string s) {
    string answer = "";
    bool check_sapce = true;
    
    for(int i=0; i<s.size(); i++){
        if(is_space(s[i]) == true){
            check_sapce = true;
        } // 공백 문자
        else{
            if(is_alpha(s[i]) == 1 && check_sapce == true){ // 시작이면서 소문자
                s[i] = s[i] - 32; // 대문자로 변경
            }
            else if(is_alpha(s[i]) == 2 && check_sapce == false){ // 시작과 숫자가 아닌 모든 대문자
                s[i] = s[i] + 32;
            }
                check_sapce = false;
        }        
    }
    answer = s;
    return answer;
}