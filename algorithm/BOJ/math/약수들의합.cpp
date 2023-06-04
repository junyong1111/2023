// 백준 단계별로 풀기 약수들의 합(9606)
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> sum(ll n) //약수들을 계산해서 반환해주는 vector
{
	vector<ll>s;

	for(ll i=1; i<n; i++){
		if(n%i==0){
			s.push_back(i);
		}
	}
	return s;
}

int main()
{
	// freopen("input.txt", "r" ,stdin);

	ll n;
	cin >> n;
	while(n != -1)
	{
		vector<ll>s = sum(n);
		ll temp = 0;
		for(ll i=0; i<s.size(); i++){ //약수들의 합 계산
			temp+= s[i];
		}
		if(n== temp){ // 약수들의 합으로 표현이 가능하면
			cout << n << " = ";
			for(ll i=0; i<s.size(); i++){
				if(i!=s.size()-1)
					cout << s[i] << " + ";
				else
					cout << s[i] << "\n";
			}
		}
		else{ //표현이 불가능하면
			cout << n << " is NOT perfect.\n";
		}
		cin >> n;
	}
	return 0;
}
