#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen("input.txt", "r" ,stdin);

	int n = 0;
	int routers = 0;

	cin >> n >> routers;
	vector<int>houses(n, 0);
	vector<int>dis;

	for(int i=0; i<n; i++)
		cin >> houses[i];
	
	// 이분탐색을 위해 배열 정렬
	sort(houses.begin(), houses.end());

	// 라우터가 2개뿐이라면 처음과 끝이 항상 정답
	if(routers == 2){
		cout << houses[n-1] - houses[0] << "\n";
		return 0;
	}

	for(int i=1; i<n; i++){
		dis.push_back(houses[i] - houses[0]);
	}

	int left = 1;
	int right = dis[dis.size()-1];
	int answer = 0;
	while(left <= right)
	{
		int mid = (left+right) /2;
		int pre_router = 0;

		int remain_routers = routers -1;
		
		for(vector<int>::iterator it = dis.begin(); it != dis.end(); it++){
			if((*it -pre_router) >= mid){ //해당 장소에 라우터를 놓을 수 있음
				pre_router = *it;
				remain_routers--;
			}
		}

		if(remain_routers > 0) //만약 설치해야할 라우터가 남아있다면 간격이 너무 길다는 뜻임 즉 거리를 줄여야 함 
		{
			right = mid - 1;
		}
		else // 만약 설치해야할 라우터가 부족하다면 간격이 너무 짧다는 의미이므로 간격을 조금 더 증가해야 함
		{
			answer = mid;
			left = mid +1;
		}
	}
	cout << answer << "\n";
	return 0;
}