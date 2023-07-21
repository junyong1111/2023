#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

void DFS(vector<ll>graph[], vector<ll> &visit, stack<ll> &s);
void BFS(vector<ll>graph[], vector<ll> &visit, queue<ll> &q);
void print_graph(vector<ll>graph[], ll vertices)
{
    for(ll i=1; i<=vertices; i++){
        cout << i << "번 Vertex :  ";
        for(ll j=0; j<graph[i].size(); j++){
            cout << graph[i][j] << "-->";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    ll vertices = 0;
    ll edges = 0;
    ll start_node = 0;
    ll nodeA, nodeB;

    cin >> vertices >> edges >> start_node;

    vector<ll>graph[vertices+1];
    vector<ll> visit(vertices+1, 0);

    for(ll i=0; i<edges; i++){
        cin >> nodeA >> nodeB;
        graph[nodeA].push_back(nodeB);
        graph[nodeB].push_back(nodeA);
    }
    // 양방향 그래프 구성

    // cout << "================정렬 전====================\n";
    // print_graph(graph, vertices);

    for(ll i=1; i<=vertices; i++)
        sort(graph[i].begin(), graph[i].end());
    // 방문 순서를 지키기 위해 정렬

    // cout << "================정렬 후====================\n";
    // print_graph(graph, vertices);

    // DFS 탐색 시작
    visit[start_node] = 1;
    stack<ll>s;
    s.push(start_node);
    DFS(graph, visit, s);

    for(ll i=1; i<=vertices; i++)
        visit[i] = 0;
    cout << "\n";

    // BFS 탐색 시작 
    visit[start_node] = 1;
    queue<ll>q;
    q.push(start_node);
    BFS(graph, visit, q);
}

void DFS(vector<ll>graph[], vector<ll> &visit, stack<ll> &s)
{
    if(!s.empty()){
        ll temp = s.top();
        s.pop();
        cout << temp << " ";
        for(ll i=0; i<graph[temp].size(); i++){
            if(visit[graph[temp][i]] == 0){
                visit[graph[temp][i]] = 1;
                s.push(graph[temp][i]);
                DFS(graph, visit, s);
            }
        }
    }
}

void BFS(vector<ll>graph[], vector<ll> &visit, queue<ll> &q)
{
    if(!q.empty()){
        ll temp = q.front();
        q.pop();
        cout << temp << " ";
        for(ll i=0; i<graph[temp].size(); i++){
            if(visit[graph[temp][i]] == 0){
                visit[graph[temp][i]] = 1;
                q.push(graph[temp][i]);
            }
        }
        BFS(graph, visit, q);
    }
}