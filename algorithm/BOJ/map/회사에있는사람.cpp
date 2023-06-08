#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

bool com(pair<string, ll> &p1, pair<string, ll>&p2)
{
    return p1.first > p2.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);
    
    ll number = 0;
    cin >> number;

    map<string ,ll>m;
    string str1;
    string str2;

    for(ll i=0; i<number; i++){
        cin >> str1 >> str2;

        if(str2 == "enter"){
            m.insert(make_pair(str1, 1));
        }
        else{
            m.erase(str1);
        }
    }
    vector<pair<string, ll> >v(m.begin(), m.end());
    sort(v.begin(), v.end(), com);

    for(ll i=0; i<v.size(); i++){
        cout << v[i].first << "\n";
    }

    return 0;
}