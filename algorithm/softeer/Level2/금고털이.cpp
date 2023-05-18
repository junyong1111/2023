#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

typedef struct bag
{
	ll weight;
	ll value;
}bag;

bool com(bag a, bag b)
{
	return a.value < b.value;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll answer = 0;
	ll weight = 0;
	ll n = 0;
	
	cin >> weight >> n ;
	
	ll per_weight = 0;
	ll per_value = 0;

	vector<bag>weights;
	bag b;
	for(ll i=0; i<n; i++)
	{
		cin >> b.weight >> b.value;
		weights.push_back(b);
	}
	
	sort(weights.rbegin(), weights.rend(), com);


	for(ll i=0; i<n; i++)
	{
		if(weight >= weights[i].weight) // can put in the bag
		{
			answer += weights[i].weight * weights[i].value;
			weight -= weights[i].weight;
		}
		else
		{
			answer += weight * weights[i].value;
			weight = 0;
			break;
		}
	}
	cout << answer << "\n";
	return 0;
}