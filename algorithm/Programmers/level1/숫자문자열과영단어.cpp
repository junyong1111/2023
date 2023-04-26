#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int char_to_int(string str, int *answer, int idx)
{
    *answer = (*answer) * 10;  
    if(str[idx] == 'z'){
        *answer = (*answer) + 0;
        return 4;
    }
    else if(str[idx] == 'o'){
        *answer = (*answer) + 1;
        return 3;
    }
    else if(str[idx] == 't'){
        if(str[idx+1]== 'w'){
            *answer = (*answer) + 2;
            return 3;
        }
        else{
            *answer = (*answer) + 3;
            return 5;
        }
    }
    else if(str[idx] == 'f'){
        if(str[idx+1] == 'o'){
            *answer = (*answer) + 4;
            return 4;
        }
        else{
            *answer = (*answer) + 5;
            return 4;
        }
    }
    else if(str[idx] == 's'){
        if(str[idx+1] == 'i'){
            *answer = (*answer) + 6;
            return 3;
        }
        else{
            *answer = (*answer) + 7;
            return 5;
        }
    }
    else if(str[idx] == 'e'){
        *answer = (*answer) + 8;
        return 5;
    }
    else if(str[idx] == 'n'){
        *answer = (*answer) + 9;
        return 4;
    }
    else{
        *answer = (*answer) + str[idx] - '0';
        return 1;
    }
}

int solution(string s) {
    int answer = 0;
    int i = 0;
    while(i<s.size()){
        i = i + char_to_int(s, &answer, i);    
    }
    
    return answer;
}