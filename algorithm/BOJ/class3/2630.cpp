#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int white;
int blue;

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
// 4각형 확인

typedef struct point
{
	int x;
	int y;
}point;

void set_point(point *p, int x, int y)
{
	*p->x = x;
	*p->y = y;
}

void print_map(vector<vector<int> >&map)
{
	for(int i =0 ; i< map.size(); i++){
		for(int j = 0; j< map.size(); j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void bfs(vector<vector<int> >&map, queue<point>q)
{
	if(!q.empty())
	{
		point n_p;
		set_point(&n_p, q.front().x, q.front().y);
		q.pop();
		
		int compare = map[n_p.y][n_p.x];
		for(int i = 0 ; i < 3; i++){
			
		}

		
	}
}
void find(vector<vector<int> >&map, int n, point p)
{
	if(n == 1){
		// if(map[])
	}
	else
	{

		
		

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r" ,stdin);

	int n = 0;
	cin >> n;

	vector<vector<int> >map(n, vector<int>(n, 0));
	for(int i =0 ; i< n; i++){
		for(int j= 0; j<n; j++){
			cin >> map[i][j];
		}
	}

	point p;
	set_point(&p, 0, 0);

	find(map,n, p);
	// print_map(map);
	
	return 0;
}
