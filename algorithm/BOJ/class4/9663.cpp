#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int total;
int		is_possible(vector<int> &b, int idx);
void	nqueen(vector<int> &board, int n, int idx);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;

    vector<int>board(n, 0);
    
	int	i = 0;
	while (i < n)
	{
		board[0] = i;
		nqueen(board, n, 0);
		i++;
	}
	cout << total << "\n";
    return 0;
}

int		is_possible(vector<int> &b, int idx)
{
	int	k;

	k = 0;
	while (k < idx)
	{
		if (b[idx] == b[k] || (abs(b[idx] - b[k]) == idx - k))
		{
			return (0);
			/*
			1. 이전 index값과 겹치는 경우 -> 같은 행에 이미 퀸이 놓아져 있음 ->불가능 반환
			2. 현재 보드에 들어가 있는 값과 순차적으로 탐색하는 값의 차이와 그 index 와 탐색하는 값에 차이가 같은 경우 
			-> X자 모양으로 퀸이 겹쳐 있음 -> 불가능 반환
			*/
		}
			
		
		k ++;
	}
	return (1);
}

void	nqueen(vector<int> &board, int n, int idx)
{
	int	i;

	i = 0;
	if (is_possible(board, idx))
	{
		if (idx == n-1)
			total++;
		else if (idx < n-1)
		{
			while (i < n)
			{
				board[idx +1] = i;
				nqueen(board, n, idx +1);
				i++;
			}
		}
	}
}
