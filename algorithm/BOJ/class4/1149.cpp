#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 3
#define MIN_SZIE 2100000000

using namespace std;

int min_sz;

void init(vector<vector<int> >&map, int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < SIZE; j++)
			cin >> map[i][j];
}

void print_map(vector<vector<int> >&map, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void print_rgb(vector<int>&map)
{
	for(int i =0; i<map.size(); i++)
		cout << map[i] << " ";
	cout << "\n";
}


bool is_possible(vector<int>&rgb, int i, int idx)
{
	if(rgb[idx-1] == i)
		return false;
	return true;
}

void rgb_puzzle(vector<vector<int> >&rgb_map, vector<int>&rgb, int idx, int sum)
{
	if (idx == rgb.size())
	{
		if(min_sz > sum){
			min_sz = sum;
		}
		return ;
	}

	for(int i = 0; i< 3; i++){
		if(is_possible(rgb, i, idx) == true)
		{
			if(sum + rgb_map[idx][i] < min_sz)
			{
				sum = sum + rgb_map[idx][i];
				rgb[idx] = i;
				rgb_puzzle(rgb_map, rgb, idx + 1, sum);
				sum = sum - rgb_map[idx][i];
			}
		}
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt", "r", stdin);

	int n = 0;
	cin >> n;

	vector<vector<int> >rgb_map(n, vector<int>(SIZE, 0));
	init(rgb_map, n);
	// print_map(rgb_map, n);
	
	min_sz = MIN_SZIE;
	for(int i = 0; i < 3; i++)
	{
		vector<int>rgb(n, -1);
		int sum = rgb_map[0][i];
		rgb[0] = i;
		rgb_puzzle(rgb_map, rgb, 1, sum);
	}

	cout << min_sz << "\n";
	
	return 0;
}
