#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct supo{
    vector<int>pattern;
    int correct;
    int rank;
}supo;

void setsupo(vector<supo> &Supo)
{
    vector<int>p1;
    for(int i=1; i<=5; i++)
        p1.push_back(i);
    Supo[0].pattern = p1;
    Supo[0].correct = 0;
    Supo[0].rank = 1;
    
    vector<int>p2;
    for(int i=1; i<=5; i++){
        if(i != 2){
            p2.push_back(2);
            p2.push_back(i);
        }
    }
    Supo[1].pattern = p2;
    Supo[1].correct = 0;
    Supo[1].rank = 2;
    
    vector<int>p3;
    p3.push_back(3);
    p3.push_back(3);
    for(int i=1; i<=5; i++){
        if(i != 3){
            p3.push_back(i);
            p3.push_back(i);
        }
    }
    Supo[2].pattern = p3;
    Supo[2].correct = 0;
    Supo[2].rank = 3;
}

bool com(supo s1, supo s2)
{
    return(s1.correct > s2.correct);
}

vector<int> solution(vector<int> answers) {
    vector<supo>Supo(3);
    vector<int> answer;
    setsupo(Supo);
    
   for(int i=0; i<Supo.size(); i++){
       for(int j=0; j<answers.size(); j++){
           if(i== 0 && Supo[i].pattern[j%5] == answers[j])
               Supo[i].correct++;
            else if(i== 1 && Supo[i].pattern[j%8] == answers[j])
                Supo[i].correct++;
            else if(i== 2 && Supo[i].pattern[j%10] == answers[j])
                Supo[i].correct++;
       }
   }
    sort(Supo.begin(), Supo.end(), com);
    int max = Supo[0].correct;
    if(max ==0){
        answer.push_back(0);
        return answer;
    }
    for(int i=0; i<Supo.size(); i++){
        if(Supo[i].correct == max)
            answer.push_back(Supo[i].rank);
    }
    return answer;
}