#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll factorial(ll n)
{
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll n =0;
    cin >> n;

    cout << factorial(n) << "\n";
    return 0;
}