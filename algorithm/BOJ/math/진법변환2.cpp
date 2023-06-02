// 백준 단계별로 풀기 일반수학1 진법변환2 (11005)
#include <iostream>
#include <string>
#define CHARTOINT 55

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r" ,stdin);

    ll value;
    ll base = 0;
    cin >> value >> base;

    if(value == 0){
        cout << "0" << "\n";
        return 0;
    } //0 예외처리
    
    string sum = "";
    string answer = "";
    while(value){
        ll temp = value % base;
        if (temp == 0){
            sum += '1';
        }
        else if(temp >= 1 && temp <= 9) // 10진수까지 처리
            sum += temp + '0';
        else
            sum += temp + CHARTOINT; // 10진수보다 큰 수 처리
        value = value/base;
    }
    cout << " answer is " << sum << "\n";

    ll idx = 0;
    for(ll i=0; i<sum.size(); i++){
        if(sum[i] == '1'){
            idx = i;
            break;
        }
    }
    for(ll i=idx; i<sum.size(); i++){
        cout << sum[i]; 
    }
    cout << "\n";
    return 0;
}