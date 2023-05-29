#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

void make_triangle(vector<vector<ll> >&triangle, ll n)
{
    ll start = 1;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<start; j++)
            cin >> triangle[i][j];
        start++;
    }
}

void print_triangle(vector<vector<ll> >&triangle, ll n)
{
    ll start = 1;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<start; j++)
            cout <<  triangle[i][j];
        cout << "\n";
        start++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    ll n = 0;    
    cin >> n;

    vector<vector<ll> >triangle(n, vector<ll>(n, 0));
    vector<vector<ll> >dp(n, vector<ll>(n, 0));

    make_triangle(triangle, n);
    // print_triangle(triangle, n);

    dp[0][0] = triangle[0][0];
    for(ll i=1; i<n; i++){
        for(ll j=0; j<=i; j++){
            if(j==0)
                dp[i][j] = max(dp[i][j], dp[i-1][j] + triangle[i][j]);
            else
                dp[i][j] = max(dp[i-1][j]+ triangle[i][j] , dp[i-1][j-1]+ triangle[i][j]);
        }
    } 
    
    ll max = dp[0][0];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(max < dp[i][j])
                max = dp[i][j];
        }
    }
    cout << max << "\n";
    return 0;
}