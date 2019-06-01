#include<cstdio>
#include<queue>
#include<cstring>
#define INF 0xfffffff
using namespace std;

bool visited[102];
int graph[102][102];
int dis[102];

int main()
{
    int n,m;
    while(scanf("%d %d", &n, &m) && n && m) {
        memset(visited, false, sizeof(visited));
        memset(graph, 0, sizeof(graph));
        for(int i=0;i<102;++i) dis[i] = INF;
        int v1, v2, w;
        for(int i=0;i<m;++i){
            scanf("%d %d %d", &v1, &v2, &w);
            graph[v1][v2] = graph[v2][v1] = w;
        }
        
    }
    return 0;
}