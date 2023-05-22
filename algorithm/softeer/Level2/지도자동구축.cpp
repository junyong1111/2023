#include<iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll MAC(int n)
{
	if(n==0)
		return 4;
	else
	{
		ll pre = MAC(n-1);
		ll node = sqrt(pre);
		ll two = (pre-node)*2;
		ll one = (pre-node)-node;
		ll point = pre+two+one+1;
		return point;
	}
}



int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	cout << MAC(n) << "\n";
	
	return 0;
}