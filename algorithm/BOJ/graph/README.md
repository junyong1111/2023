## BOJ Graph

## 1. 바이러스 Silver3

### [https://www.acmicpc.net/problem/2606](https://www.acmicpc.net/problem/2606)

 [2606번: 바이러스

첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하인 양의 정수이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍

www.acmicpc.net](https://www.acmicpc.net/problem/2606)

### 문제

신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

### 입력

첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하인 양의 정수이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

### 출력

1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

### 문제해결

그래프 탐색을 이용하는 가장 기본적인 문제이다. 그래프를 구성하고 DFS 또는 BFS를 이용하면 쉽게 정답을 찾을 수 있는 문제이다.

1.  양방향 그래프 구성

-   주어진 조건에 맞게 2개의 노드를 입력으로 받아 양방향 그래프를 구성해준다.

```
for(ll i=0; i<networks; i++){
        cin >> nodeA >> nodeB;
        graph[nodeA].push_back(nodeB);
        graph[nodeB].push_back(nodeA);
    }
    // 양방향 그래프 구성
```

2.  1번 컴퓨터부터 전염 시작

-   문제에서는 시작 노드를 1번으로 고정하였기 때문에 1번 노드 방문을 체크하고 스택에 1번 컴퓨터를 넣어준다.

```
 visit[1] = 1;
    s.push(1);
    // 1번 컴퓨터부터 전염 시작
```

3.  DFS 탐색 시작

-   그래프 탐색을 하면서 전염되지 않은 컴퓨터가 있다면 전염하고 virus를 1개 증가시켜주고 탐색이 끝나면 최종 virus 갯수를 반환해준다.

```
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
```

주의해야 할 점은 1번 컴퓨터는 이미 감염이 된것이므로 virus 갯수에서 제외시켜줘야 한다.

```
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
```

2. DFS와BFS(1260) Silver2

### [https://www.acmicpc.net/problem/1260](https://www.acmicpc.net/problem/1260 "백준(1260) DFS와 BFS")

 [1260번: DFS와 BFS

첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사

www.acmicpc.net](https://www.acmicpc.net/problem/1260)

### 문제

그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 **정점 번호가 작은 것을 먼저 방문**하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

### 입력

첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

### 출력

첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

### 문제해결

그래프 순회 알고리즘의 기본인 DFS와 BFS를 구현하는 문제이며 개념만 알고 있다면 어렵지 않게 해결할 수 있는 문제이다. 다만 주어진 조건에서 방문할 수 있는 정점이 여러 개인 경우에는 **정점 번호가 작은 것을 먼저 방문하는 부분을 주의**해야 한다.

1.  그래프 구성

-   주어진 조건에 맞게 그래프 구성
    
    ```
    for(ll i=0; i<edges; i++){
          cin >> nodeA >> nodeB;
          graph[nodeA].push_back(nodeB);
          graph[nodeB].push_back(nodeA);
      }
      // 양방향 그래프 구성
    ```
    

2.  각각의 그래프 정렬

-   조건에서 원하는 정점 번호가 작은 것을 방문하기 위하여 각각의 정점들으 오름차순으로 정렬
    
    ```
    for(ll i=1; i<=vertices; i++)
          sort(graph[i].begin(), graph[i].end());
    ```
    

[##_Image|kage@dSEXQg/btsofQNUS0i/9i8AEVMmYMks8IgdYo57Uk/img.png|CDM|1.3|{"originWidth":1056,"originHeight":568,"style":"alignCenter","width":473,"height":254,"filename":"스크린샷 2023-07-20 오전 12.33.08.png"}_##]

3.  DFS 순회 시작

```
// DFS 탐색 시작
    visit[start_node] = 1;
    stack<ll>s;
    s.push(start_node);
    DFS(graph, visit, s);
```

```
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
```

4.  visit 벡터 초기화 및 개행문자 추가

-   DFS에서 사용했던 visit 벡터 초기화와 정답출력을 위해 개행 문자 추가

```
for(ll i=1; i<=vertices; i++)
        visit[i] = 0;
    cout << "\n";
```

5.  BFS 순회 시작

```
// BFS 탐색 시작 
    visit[start_node] = 1;
    queue<ll>q;
    q.push(start_node);
    BFS(graph, visit, q);
```

```
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
```

### 전체 코드

```
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
```

[##_Image|kage@OaD76/btsogf0ZxSe/Du0lLlYM0tmLbWWWbBvtqK/img.png|CDM|1.3|{"originWidth":1848,"originHeight":134,"style":"alignCenter","filename":"스크린샷 2023-07-20 오전 12.27.56.png"}_##]