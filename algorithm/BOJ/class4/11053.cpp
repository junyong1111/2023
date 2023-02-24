#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int dynamic(vector<vector<int> > &dp, vector<int>&v)
{
    int max = 0;
    for(int i = 0; i < v.size() -1 ; i++){
        int key = v[i];
        for(int j= i + 1; j < v.size(); j++){
            if (key < v[j]){
                dp[i][j] =  dp[i][j-1] + 1;
                key = v[j];
            }
            else
            {
                key = v[j];
                for(int k = j-1; k >= 0; k--){
                    if (key > v[k]){
                        dp[i][j] = dp[i][k] + 1;
                        break;
                    }
                }
            }
            if (max < dp[i][j]){
                max = dp[i][j];
            }
        }
    }
    return max;
}
/*

20
31 84 18 62 35 77 23 53 60 94 3 77 60 51 42 18 83 85 63 51
answer 7 
*/


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n = 0;
    cin >> n;

    vector<int>v(n, 0);
    vector<vector<int> >dp(n, vector<int>(n, 1));

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cin >> *it;

    int answer = dynamic(dp,v);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    cout << answer << "\n";
    return 0;
}