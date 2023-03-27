#include<iostream>
#include<queue>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 110;
int g[N][N];
bool st[N][N];
PII last[N][N];
int n;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int step;

void bfs(int x, int y){
    queue<PII> q;
    q.push({x, y});
    while(q.size()){
        int cnt = q.size();
        while(cnt--){
            PII t = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int a = t.x + dx[i], b = t.y + dy[i];
                if(a < 0 || a >= n || b < 0 || b >= n) continue;
                if(g[a][b] == 1) continue;
                if(st[a][b]) continue;
                st[a][b] = true;
                last[a][b] = {t.x, t.y};
            }
        }
    }
}

void back(int x, int y){
    PII t = last[x][y];
    if(t.x != -1 && t.y != -1)
        back(t.x, t.y);
    printf("%d %d\n", x, y);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n;i ++)
        for(int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    last[0][0] = {-1, -1};    
    bfs(0, 0);
    
    back(n - 1, n - 1);
    
    return 0;
}