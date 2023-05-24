#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;



int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll M, N, K;
	cin >> M >> N >> K;

	if(N<M){
		cout << "normal" << "\n";
		return 0;
	}
	
	vector<ll>m(M,0);
	vector<ll>n(K,0);
	
	for(ll i=0; i<M; i++)
		cin >> m[i];
	for(ll i=0; i<N; i++)
		cin >> n[i];
	
	for(ll i=0; i<=N-M; i++){
		ll j = 0;
		if(n[i] == m[0]){
			for(j=1; j<M; j++){
				if(n[i+j] != m[j]){
					break;
				}
			}
			if(j == M){
				cout << "secret" << "\n";
				return 0;
			}
		}
	}
	cout << "normal" << "\n";
	
	return 0;
}