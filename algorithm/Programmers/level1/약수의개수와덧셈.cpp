#include <string>
#include <vector>

using namespace std;

int count(int n)
{
    int answer = 0;
    for(int i=1; i<=n; i++)
    {
        if(n%i ==0)
            answer++;
    }
    return answer;
}

int solution(int left, int right) {
    int answer = 0;
    int cnt = 0;
    
    for(int i=left; i<= right; i++)
    {
        cnt = count(i);
        if(cnt % 2==0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}