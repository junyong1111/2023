## Binary Search(이진 탐색)

데이터의 크기가 너무 큰 경우 일반적인 완전 탐색으로는 시간초과를 피하기 힘들다. 이 때 이진 탐색을 이용하면 logn의 시간만으로도 데이터에 해당 값을 탐색할 수 있다.
--# 이진 탐색을 진행하기 위해서는 탐색을 하고자하는 배열의 값이 무조건 정렬이 선행되어야 한다.


### 1. 공유기 설치 (백준 2110)

## 문제 설명

도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.

도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.

C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.

### **해결방법**

해당 문제는 이분 탐색을 이용하여 해결할 수 있는 문제이다. 이분탐색을 위해서는 해당 배열이 정렬이 되어야 하므로 가장 먼저 배열을 정렬하고 시작한다.

먼저. 공유기가 2개만 들어온 경우에는 처음과 끝에 설치해야 인접한 두 공유기 사이의 거리가 최대가 될 수 있다. 이후 공유기가 3개 이상이 들어온 경우부터는 정렬된 왼쪽 집부터 시작해서 공유기를 설치해가며 최대 거리를 확인해야 한다. 

**배열 정렬**

```cpp
sort(houses.begein(), houses.end());
```

**만약 라우터의 개수가 2개라면 처음과 끝이 정답**

```cpp
if(routers == 2)
{
	cout << houses[n-1] - houses[0] << "\n";
	return 0;
}
```

**시작 집 위치부터 끝 집 위치까지의 거리들을 계산**

```cpp
for(int i=1; i<n; i++){
		dis.push_back(houses[i] - houses[0]);
	}
```

**이분 탐색 시작**

- 집 위치

| 1 | 2 | 4 | 8 | 9 |
| --- | --- | --- | --- | --- |
- 처음집부터 각각의 집과의 거리

| 1 | 3 | 7 | 8 |
| --- | --- | --- | --- |

만약 라우터가 3개라면 3개의 라우터는 모두 설치가 되어야 한다. 지정한 거리안에서 모든 라우터가 설치가 가능한지 확인해야 함 이 거리를 이분탐색으로 찾는 과정이 필요

- Left = 1
- Right = 8
- Mid = (1+8) / 2 ⇒ 4

```cpp
int left = 0;
int right = dis[dis.size()-1];
```

이분탐색을 하면서 만약 공유기 설치가 가능하면 그 집의 좌표를 갱신하고 설치 가능한 라우터의 개수를 하나 빼줌

```cpp
int mid = (left+right) /2;
		int pre_router = 0;

		int remain_routers = routers -1;
		
		for(vector<int>::iterator it = dis.begin(); it != dis.end(); it++){
			if((*it -pre_router) >= mid){ //해당 장소에 라우터를 놓을 수 있음
				pre_router = *it;
				remain_routers--;
			}
		}
```

위 반복문이 끝나면 x의 거리 간격만큼 공유기를 설치했을 때 설치한 공유기의 개수가 나온다 이 때 공유기의 개수에 따라 이분탐색에서 왼쪽 또는 오른쪽으로 탐색한다.

- 만약 라우터의 개수가 남은 경우

라우터의 개수가 남아 있다는 의미는 설치한 공유기 거리가 너무 길어 라우터가 남았다는 의미이므로 거리를 더 줄여함 따라서

```cpp
right = mid - 1;
```

- 만약 라우터의 개수가 부족하거나 딱 맞는경우

라우터의 개수가 부족하거나 딱 맞는 경우에는 설치한 라우터 거리가 일치하거나 너무 짧다는 의미이다. 따라서 거리를 조금 더 늘려야 한다. 또한 왼쪽부터 탐색을 진행하기 때문에 answer에는 항상 max값이 들어간다.

```cpp
else // 만약 설치해야할 라우터가 부족하다면 간격이 너무 짧다는 의미이므로 간격을 조금 더 증가해야 함
		{
			answer = mid;
			left = mid +1;
		}
```

**전체 코드**

```cpp
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
```