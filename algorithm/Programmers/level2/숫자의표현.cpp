#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int solution(int n) {
    int answer = 0;
    ll temp = 0;
    ll cnt = 0;
    for(ll i=n; i>0; i--){
        temp += i;
        if(temp<n)
            cnt++;
        else
        {
            if(temp == n)
                answer++;
            temp = 0;
            i = i+ cnt;
            cnt = 0;
        }   
    }
    return answer;
}