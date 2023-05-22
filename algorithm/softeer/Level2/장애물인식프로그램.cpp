#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

typedef struct point
{
	ll x;
	ll y;
}point;

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0 ,0};

void print(vector<ll>map[], int n)
{
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void print_visit(vector<vector<ll> >&visit, ll n)
{
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
}
void insert_map(vector<ll>map[], int n)
{
	string str ="";
	for(ll i=0; i<n; i++){
		cin >> str;
		for(ll j=0; j<str.size(); j++){
			int temp = str[j] - '0';
			map[i].push_back(temp);
		}
	}
}

bool check_idx(point p, ll n)
{
	if(p.x < 0 || p.y < 0)
		return false;
	if(p.x >= n || p.y >= n)
		return false;
	return true;
}

void dfs(vector<ll>map[], vector<vector<ll> >&visit, point p, ll count)
{
	point new_p;

	for(ll i=0; i<4; i++){
		new_p.x = p.x + dx[i];
		new_p.y = p.y + dy[i];
		if(check_idx(new_p, visit.size()) == true && visit[new_p.y][new_p.x] == 0){
			if(map[new_p.y][new_p.x] == 1){
				visit[new_p.y][new_p.x] = count;
				dfs(map, visit, new_p, count);
			}
		}
	}
}


ll block_count(vector<vector<ll> >&visit, ll n, ll count)
{
	
	ll block = 0;
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			if(visit[i][j] == count)
				block++;
		}
	}
	return block;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n = 0;
	cin >> n;

	vector<ll>map[n];
	vector<vector<ll> >visit(n, (vector<ll>(n,0)));

	insert_map(map, n);
	// print(map, n);

	ll count = 1;
	point p;

	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			if(visit[i][j] == 0 && map[i][j] ==1){
				p.x = j;
				p.y = i;
				visit[i][j] = count;
				dfs(map, visit, p, count);
				count ++;
			}
		}
	}

	count--;

	vector<ll>answer(count, 0);

	for(ll i=1; i<=count; i++){
		answer[i-1] = block_count(visit, n, i);
	}
	sort(answer.begin(), answer.end());
	cout << count << "\n";
	for(ll i=0; i<answer.size(); i++){
		cout << answer[i] << "\n";
	}

	return 0;
}