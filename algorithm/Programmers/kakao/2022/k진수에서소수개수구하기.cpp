#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string n_to_k(int n, int k){
    string tmp ="";
    string str ="";
    while(n){
        tmp += (n%k) + '0';
        n = n/k;
    }
    for(int i=tmp.size()-1; i>=0; i--)
        str += tmp[i];
    return str;
}

int is_prime(long long n){
    if(n<=1)
        return 0;
    for(long long i=2; i*i<=n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    int idx = 0;
    long long temp = 0;
    string str = n_to_k(n, k); 
    for(int i=0; i<str.size(); i++){
        temp = 0;
        idx = 0;
        while(str[i+idx] != '0' && (i+idx) <str.size()){ //0이 나올 때 까지
            temp = temp *10;
            temp += str[i+idx++] - '0';
        }
        if(is_prime(temp) ==1)
            answer ++;
        i = i+idx;
    }
    return answer;
}