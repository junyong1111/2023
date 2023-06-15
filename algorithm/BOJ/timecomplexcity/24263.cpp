// 단계별로 풀기_시간복잡도 : 알고리즘 수업 - 알고리즘의 수행 시간 2
#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll n = 0;
    cin >> n;

    if (n==0)
        cout << 0 << "\n";
    else 
        cout << n << "\n";
    cout << 1 << "\n";
    return 0;
}