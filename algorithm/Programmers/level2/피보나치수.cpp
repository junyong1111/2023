#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX_SIZE 100001

using namespace std;
typedef long long ll;

vector<ll>Dp(MAX_SIZE, -1);

ll fibo(int n)
{
    if(Dp[n] != -1)
        return Dp[n];
    else
    {
        Dp[n] = (fibo(n-1) + fibo(n-2))%1234567;
        return Dp[n];
    }
}

int solution(int n) {
    Dp[0] = 0;
    Dp[1] = 1;
    int answer = fibo(n);
    return answer;
}