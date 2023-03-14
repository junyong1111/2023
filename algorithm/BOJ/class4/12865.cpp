#include <iostream>
#include <vector>
#define MAX(a,b) (a) > (b) ? (a) : (b)

using namespace std;

typedef struct weight_value
{
    int weight;
    int value;
}wv;

void print_bag(vector<vector<int> >&bag)
{
    for(int i = 0; i<= bag.size(); i++){
        for(int j = 0; j< bag[i].size(); j++){
            cout << bag[i][j] << " ";
        }
        cout << "\n";
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int n = 0;
    int k = 0;

    cin >> n >> k;
    vector<weight_value>info;
    weight_value v;
    for(int i = 0; i<n; i++){
        cin >> v.weight >> v.value;
        info.push_back(v);
    }
    vector<vector<int> >bag(n, vector<int>(k+1, 0));
    // 1번 물건에 대해서 미리 테이블값을 설정
    for(int w = 1; w<=k; w++){
        if(info[0].weight<=w){
            bag[0][w] = info[0].value;
        }
    }

    //1번 물건을 제외한 나머지부분 테이블 갱신
    for(int i =1; i<n; i++){
        for(int w=1; w<=k; w++){
            if(w-info[i].weight >=0){ //해당 테이블에 물건을 넣을 공간이 있다면
            // 자신을 넣기 전 최대가치 또는 자신을 넣을 공간을 제외한 공간 최대 가치 + 자신의 가치 중 더 큰걸 선택
                bag[i][w] = MAX(bag[i-1][w], bag[i-1][w-info[i].weight] + info[i].value);
            }
            else //넣을 공간이 없다면 자신을 넣기 전 최대 가치로 갱신
                bag[i][w] = bag[i-1][w];
        }
    }

    // print_bag(bag);
    // 테이블에 맨 마지막 위치에는 최대 가치 저장
    cout << bag[n-1][k] << "\n";

}
