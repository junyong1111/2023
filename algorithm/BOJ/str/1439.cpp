#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    string str;
    cin >> str;

    int len = str.length();

    int len_zero = 0;
    bool zero = false;
    int len_one = 0;
    char ch = str[0];

    if(ch == '0'){
        len_zero ++;
        zero = true;
    }
        
    else{
        len_one++;
    }
        

    for(int i = 1 ; i< len; i++){
        if(str[i] != ch && zero == true){
            len_one ++;
            zero = false;
            ch = str[i];
        }
        else if(str[i] != ch && zero == false){
            len_zero++;
            zero = true;
            ch = str[i];
        }
    }

    if(len_one < len_zero){
        cout << len_one <<"\n";
        return 0;
    }
    cout << len_zero << "\n";

    return 0;
}