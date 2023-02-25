#include <iostream>
#include <vector>
#include <algorithm>
#define MAX(a,b) (a) > (b) ? (a) : (b)

using namespace std;


int dynamic(vector<int> &dp, vector<int>&v)
{
    int max = 1;
    int key = v[0];
    for(int i = 1; i < v.size(); i++){
        int temp = 1;
        if (key < v[i]){
            for(int j = i -2; j>=0; j--){
                if(v[i] > v[j]){
                    temp = MAX(dp[j], temp);
                }
            }
            dp[i]=  MAX(dp[i-1]+ 1, temp + 1);
            key = v[i];
        }
        else{
            for(int j = i - 2; j >= 0; j--){
                if (v[i] > v[j]){
                    temp = MAX(temp, dp[j] + 1);
                }
            }
            dp[i]= temp ;
            key = v[i];
        }
        if (max < dp[i])
            max = dp[i];
    }
    return max;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    
    int n = 0;
    cin >> n;

    vector<int>v(n, 0);
    vector<int>dp(n, 1);

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cin >> *it;

    int answer = dynamic(dp,v);
    cout << answer << "\n";
    return 0;
}