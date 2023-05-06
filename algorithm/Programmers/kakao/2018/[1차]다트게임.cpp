#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <vector>

using namespace std;

// 점수 0 ~ 10

// 보너스 S,D,T
// 각 점수를 보너스 만큼 제곱 S = 1, D = 2, T = 3

// *, #
// 스타상 : 해당 점수와 바로 전에 얻은 점수 2배
// 이전 값이 없는 경우 : 그 값만 2배
// 중복 된 경우 : 중첩된 스타상 4배
// 아차상과의 중복 : 아차상의 점수는 -2배
// 아차상 : 당첨 시 해당 점수 마이너스

vector<int> sep_bonus(string dartResult){
    vector<int>bonus;
    
    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i] == 'S'){
            bonus.push_back(1);
        }
        else if(dartResult[i] == 'D')
            bonus.push_back(2);
        else if(dartResult[i] == 'T')
            bonus.push_back(3);
    }
    return bonus;
}

vector<int> sep_socre(string dartResult){
    vector<int>bonus = sep_bonus(dartResult);
    vector<char>opt(3);
    vector<int>scores;
    int idx = 0;
    int score = 0;
    int count = 0;
    
    for(int i=0; i<dartResult.size(); i++){
        score = 0;
        idx = 0;
        if(dartResult[i+idx]>= '0' && dartResult[i+idx] <='9'){
            while(dartResult[i+idx]>= '0' && dartResult[i+idx] <='9'){
                score *= 10;
                score += dartResult[i+idx] -48;
                idx++;
            }
            int temp = pow(score, bonus[count++]);
            scores.push_back(temp);
        }
        if(dartResult[i+idx] == '*')
            opt[count-1] = '*';
        else if(dartResult[i+idx] == '#')
            opt[count-1] = '#';
        i = i + idx;
    }
    
    
    for(int i=0; i<opt.size(); i++){       
        if(i==0 && opt[i] == '*'){
            // 시작 하자마자 2배 찬스인 경우 그 값만 2배
            scores[i] = scores[i]*2; 
        }
        else if(opt[i] == '*'){ // 스타상의 경우
            scores[i] = scores[i] *2; 
            scores[i-1] = scores[i-1] *2;
        }
        else if(opt[i] == '#'){ //아차상의 경우 그 값만 -
            scores[i] = scores[i] * -1;
        }
    }
    return scores;
}

void print(vector<int>&V){
    for(auto v: V)
        cout << v << " ";
    cout << "\n";
}

int solution(string dartResult) {
    int answer = 0;
    vector<int>scores = sep_socre(dartResult);
    // print(scores);
    for(auto score : scores){
        answer += score;
    }
    return answer;
}