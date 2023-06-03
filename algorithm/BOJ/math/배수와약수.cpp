// 백준 단계별로 풀기 약수(5086)
#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	//freopen("input.txt", "r" ,stdin);

	ll n,m ;
	cin >> n >> m;
	while(n != 0 and m!=0)
	{
		if(m%n==0){ //약수
			cout << "factor" << "\n";
		}
		else if(n%m==0){//배수
			cout << "multiple" << "\n";
		}
		else{ //둘 다 아님
			cout << "neither" << "\n";
		}
		cin >> n >> m;
	}
	return 0;
}