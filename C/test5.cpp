#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 620, INF = 0x3f3f3f3f;
int w[N][N], dist[N][N];
int sx, sy, ex, ey;
int n, m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool st[N];

void bfs(){
    memset(dist, 0x3f, sizeof dist);
    queue<PII> q;
    q.push({ex, ey});
    dist[ex][ey] = w[ex][ey];
    
    while(q.size()){
        PII t = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int a = t.x + dx[i],  b = t.y + dy[i];
            if(a <= 0 || a > n || b <= 0 || b >= m) continue;
            if(dist[t.x][t.y] > w[a][b]) {
                dist[t.x][t.y] = w[a][b];
                q.push({a, b});
            }else if(dist[a][b] == INF) {
                dist[t.x][t.y] = w[a][b];
                q.push({a, b});
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &w[i][j]);
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    bfs();
    
    printf("%d\n", dist[sx][sy]);
    
    return 0;
}