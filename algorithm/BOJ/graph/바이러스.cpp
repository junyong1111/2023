#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

ll DFS(vector<ll>grpah[], vector<ll> &visit, stack<ll> &s);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll computers = 0;
    ll networks = 0;
    ll nodeA, nodeB;

    cin >> computers >> networks;

    vector<ll>graph[computers+1];
    stack<ll>s;
    vector<ll> visit(computers, 0);
    for(ll i=0; i<networks; i++){
        cin >> nodeA >> nodeB;
        graph[nodeA].push_back(nodeB);
        graph[nodeB].push_back(nodeA);
    }
    // 양방향 그래프 구성

    visit[1] = 1;
    s.push(1);
    // 1번 컴퓨터부터 전염 시작

    cout << DFS(graph, visit, s) << "\n";
    // DFS탐색 시작

    return 0;
}

ll DFS(vector<ll>grpah[], vector<ll> &visit, stack<ll> &s)
{
    ll virus = 0;
    while(!s.empty()){
        ll temp = s.top();
        s.pop();
        for(ll i=0; i<grpah[temp].size(); i++){
            if(visit[grpah[temp][i]] == 0){
                visit[grpah[temp][i]] = 1;
                s.push(grpah[temp][i]);
                virus++;
                // 최초 방문이라면 방문 체크 후 바이러스 감염 카운트 증가
            }
        }
    }
    return virus;
}