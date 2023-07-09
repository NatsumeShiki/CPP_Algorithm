
#include <bits/stdc++.h>
using namespace std;
int n, m;
char g[510][510];
string s = "snuke";
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool st[510][510];
bool ok;
void dfs(int x, int y, char last){
    if(x == n && y == m){
        ok = true;
        return;
    }
    // cout << x << ' ' << y << endl;
    for(int i = 0; i < 4; i ++ ){
        int X = x + dx[i], Y = y + dy[i];
        if(X <= 0 || X > n || Y <= 0 || Y > m) continue;
        if(st[X][Y]) continue;
        char c = g[X][Y];
        st[X][Y] = true;
        int pos = s.find(last);
        if(x == 5 && y == 5) cout << c << " "<< s.find(c) << " " << pos + 1 << endl;
        if(((int)s.find(c) == pos + 1) || (last == 'e' && c == 's')) 
        {
            cout << x << ' ' << y << " " << s[pos] << " " << c << endl;
            dfs(X, Y, c);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) scanf("%s", g[i] + 1);
    dfs(1, 1, g[1][1]);
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;

// #define x first
// #define y second
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// typedef long long LL;
// typedef pair<int, int> PII;
// typedef pair<int, PII> PIII;
// typedef pair<int, PIII> PIIII;
// struct edge{
//   int a, b, c;
//   bool operator < (const edge &t) const{
//     return c < t.c;
//   }
// };

// int lowbit(int x) { return x & -x; }

// const int N = 510, M = 1e6 + 10, INF = 0x3f3f3f3f;
// int n, m, k, t;
// char g[N][N];
// int dist[N][N];
// string s = "snuke";

// bool bfs(int x, int y){
//   if(g[x][y] != 's') return false;

//   queue<PII> q;
//   q.push({x, y});
//   dist[x][y] = 0;

//   while(q.size()){
//     auto t = q.front();
//     q.pop();

//     if(t.x == n - 1 && t.y == m - 1) return true;

//     for(int i = 0; i < 4; i++){
//       int a = t.x + dx[i], b = t.y + dy[i];
//       if(a < 0 || a >= n || b < 0 || b >= m) continue;
//       if(dist[a][b]) continue;

//       char ch1 = g[t.x][t.y], ch2 = g[a][b];
//       int index = 0;
//       for(; index < 5; index++) if(ch1 == s[index]) break;
//       if(index == 5 || index == 4) index = 0;
//       else index++;
//       if(ch2 == s[index]){
//         dist[a][b] = dist[x][y] + 1;
//         q.push({a, b});
//       }
//     }
//   }

//   return false;
// }

// void solve(){
//   scanf("%d%d", &n, &m);
//   for(int i = 0; i < n; i++) scanf("%s", g[i]);

//   if(bfs(0, 0)) puts("Yes");
//   else puts("No");

// }

// signed main(){
//   #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   // ios::sync_with_stdio(false);
//   // cin.tie(0);
//   #endif

//   int T = 1;
//   while(T--){
//     solve();
//   }

//   return 0;
// }