#include <string>
#include <vector>

using namespace std;

string dec_to_bi(int size, int n)
{
    string bi;
    for(int i=0; i<size; i++)
        bi += '0';
    int idx = size-1;
    while(n){
        bi[idx--] = (n%2) + '0';
        n = n/2;
    }
    return bi;
}

string concat(string a, string b)
{
    int size = a.size();
    string con_string ="";
    for(int i=0; i<size; i++){
        if(a[i] == '1' || b[i] =='1')
            con_string += '#';
        else
            con_string += ' ';
    }
    return con_string;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<string> answer;
    
    for(int i=0; i<arr1.size(); i++){
        answer.push_back(concat(dec_to_bi(n, arr1[i]), dec_to_bi(n, arr2[i])));
    }

    return answer;
}