#include<iostream>
#include <vector>

using namespace std;

typedef long long ll;

typedef struct speed
{
	ll distance;
	ll velocity;
}speed;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	cin >> n >> m;

	vector<speed>limit;
	vector<speed>test;
	speed s;
	ll max_speed = 0;
	ll sum_distance = 0;
	for(ll i=0; i<n; i++){
		cin >> s.distance >> s.velocity;
		sum_distance+= s.distance; // 총 테스트 거리 측정
		limit.push_back(s);
	}
	for(ll i=0; i<m; i++){
		cin >> s.distance >> s.velocity;
		test.push_back(s);
	}

	ll limit_idx = 0;
	ll test_idx = 0;

	while(sum_distance){ //남은 주행거리가 있는 경우 반복 진행
		
		while(test[test_idx].distance>0){ // 현재 테스트 주행거리가 있는 경우
		s.distance = limit[limit_idx].distance;
		s.velocity = limit[limit_idx].velocity;
		// 제한 속도 저장
		if(test[test_idx].velocity - s.velocity > max_speed){ // 최대 초과 속도 갱신
			max_speed = test[test_idx].velocity - s.velocity;
		}
		test[test_idx].distance  -= s.distance;

		if(test[test_idx].distance<0) // 음수면 테스트 주행 끝
		{
			sum_distance -=  (s.distance + test[test_idx].distance);
			limit[limit_idx].distance -= (s.distance + test[test_idx].distance);
		}
		else
		{
			sum_distance -=  s.distance;
			limit_idx++;
		}
			
		} //while문
	
		test_idx++;
	}
	cout << max_speed << "\n";
	
	return 0;
}