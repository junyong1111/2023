// 백준 단계별로 풀기 일반수학1 진법변환 (2745)
#include <iostream>
#define CHARTOINT 55

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    string value;
    ll base = 0;

    cin >> value >> base;
    ll sum = 0;
    for(ll i=0; i<value.size(); i++){
        sum = sum * base;
        if(value[i] >= '0'  && value[i] <= '9')
            sum += (value[i] - '0');
        else
            sum += (value[i] - CHARTOINT);
    }
    cout << sum << "\n";
    return 0;
}