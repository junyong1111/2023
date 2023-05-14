#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

typedef long long ll;

ll NumberOfOne(string str)
{
    ll count = 0;
    for(ll i =0; i<str.size(); i++){
        if(str[i] == '1')
            count++;
    }
    return count;
}

int solution(int n) {
    int answer = n;
    string res = bitset<20>(n).to_string(); // i는 비트 자리수, n은 변환할 10진수
    ll count =  NumberOfOne(res);
    while(1)
    {
        answer++;
        string temp_res = bitset<20>(answer).to_string();
        ll temp = NumberOfOne(temp_res);
        if(temp == count)
            return answer;
    }
}