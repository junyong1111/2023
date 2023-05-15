#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

string binary_to_dec(int size)
{
    string str = bitset<30>(size).to_string();
    string temp = "";
    ll i =0;
    for(i=0; i<str.size(); i++){
        if(str[i] == '1')
            break;        
    }
    for(; i<str.size(); i++)
        temp += str[i];
    return temp;
}

void to_binary(string &s, ll *count, ll *iter)
{
    string str = "";
    for(ll i=0; i<s.size(); i++){
        if(s[i] == '0')
            *count = *(count) + 1;
        else
            str+= s[i];
    }
    s = binary_to_dec(str.size());
    *iter = *(iter) + 1;  
}

vector<int> solution(string s) {
    vector<int> answer;
    ll count = 0;
    ll iter = 0;
 
    while(s.size() != 1)
    {
        to_binary(s, &count, &iter);
    }
    answer.push_back(iter);
    answer.push_back(count);
    return answer;
}