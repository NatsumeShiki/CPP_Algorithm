#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define FOR(n) for(int i = 0; i < n; i++) 
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 3010, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N][N];
vector<int> alls;
PII last[N][N];

bool cmp(PII a, PII b, int x, int y){
  int d1 = max(x - a.x, y - a.y);
  int d2 = max(x - b.x, y - b.y);
  // if(x == 4 && y == 3){
  //   cout << d1 << " " << d2 << endl;
  //   cout << a.x << " " << a.y << endl;
  //   cout << b.x << " " << b.y << endl;

  // }
  return d1 <= d2;
}

void solve(){
  cin >> n >> m >> k;
  while(k--){
    int a ,b;
    cin >> a >> b;
    arr[a][b]++;
  }
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
      arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
    }

  int res = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
      int l = 0, r = min(i, j);
      while(l < r){
        int mid = l + r + 1 >> 1;
        if(arr[i][j] - arr[i - mid][j] - arr[i][j - mid] + arr[i - mid][j - mid] == 0) l = mid;
        else r = mid - 1;
      }
      res += l;
    }
  cout << res << endl;
  // for(int i = 0; i <= n; i++) arr[i][0]++;
  // for(int i = 0; i <= m; i++) arr[0][i]++;
  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j <= m; j++){
  //     if(arr[i][j] > 0){
  //       last[i][j] = {i, j};
  //     }else{
  //       // if(i == 4 && j == 3){
  //       //   cout << cmp(last[i - 1][j], last[i][j - 1], i, j) << endl;
  //       // }
  //       if(cmp(last[i - 1][j], last[i][j - 1], i, j)){
  //         last[i][j] = last[i - 1][j];
  //       }else {
  //         last[i][j] = last[i][j - 1];
  //       }
  //     }
  //     // cout << i << " " << j << " " << last[i][j].x << " " << last[i][j].y << endl;
  //   }
  // }

  // int res = 0;
  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j <= m; j++){
  //     // if(arr[i][j]) continue;
  //     int d1 = i - last[i][j].x;
  //       int d2 = j - last[i][j].y;
  //     if(last[i][j].x == 0 && last[i][j].y == 0) {
  //       res += min(i, j);
  //     }else if(last[i][j].x == i){
  //       res += j - last[i][j].y;
  //     }else if(last[i][j].y == j){
  //       res += i - last[i][j].x;
  //     }else{
        

  //       // cout << d1 << " " << d2 << endl;
  //       res += min(d1, d2);
  //     }
  //     // cout << i << " " << j << " " << last[i][j].x << " " << last[i][j].y << " " << d1 << " " << d2 << " " << res << endl;

  //   }
  // }
  // cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}