#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a){
        answer = answer + (n/a)*b;
        if(n%a ==0){
            n = (n/a)*b;
        }
        else{
            int remain = n%a;
            n = (n/a)*b + remain;
        }
    }
    return answer;
}