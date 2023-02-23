#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    string str;
    cin >> str;
    int len = str.length();
    bool check = false;

    int i = 0;
    int sum = 0;
    
    while (i < len)
    {
        string temp = "";
        if (str[i] == '+' || str[i] == '-'){
            if (str[i] == '-')
                check = true;
            i++;
        }
        while (str[i] >= '0' && str[i] <= '9'){
            temp = temp + str[i];
            i++;
        }
        
        if (check == false){
            sum = sum + stoi(temp);
        }
        // 1+2-3+4+5
        else if(check == true && str[i] == '+'){
            string tmp = "";
            int t = 0;
            while(i < len && str[i] == '+')
            {  
                i++;
                if (tmp != "")
                    t = t + stoi(tmp);
                tmp = "";
                while (str[i] >= '0' && str[i] <= '9'){
                tmp = tmp + str[i];
                i++;
                }
            }
            
            sum = sum - (stoi(temp) + stoi(tmp) + t);
            check = false;
        }
        else
        {
            check =false;
            sum = sum - stoi(temp);
        }
    }
    cout << sum <<"\n";
    return 0;
}