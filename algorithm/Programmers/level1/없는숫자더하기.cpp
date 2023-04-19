#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    vector<int>v(10, 0);
    bool check = false;
    int answer = 0;
    for(int i=0; i<v.size(); i++)
        v[i] = i;
    for(int i=0; i<v.size(); i++)
    {
        check =false;
        for(int j=0; j<numbers.size(); j++)
        {
            if(v[i] == numbers[j])
            {
                check = true;
                break;
            }
            check = false;
        }
        if(check==false)
            answer += v[i];
    }
    return answer;
}