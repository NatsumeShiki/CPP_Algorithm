#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t, h;
PII item[M];
bool flag[M];

bool find(int a, int b){
  int l = 0, r = m - 1;
  while(l < r){
    int mid = l + r >> 1;
    if(item[mid].x < a) l = mid + 1;
    else r = mid;
  }
  // cout << l << endl;
  if(item[l].x != a) return false;
  int st = l;
  l = 0, r = m - 1;
  while(l < r){
    int mid = l + r + 1 >> 1;
    if(item[mid].x <= a) l = mid;
    else r = mid - 1;
    // cout << mid << endl;
  }
  l = st;
  while(l < r){
    int mid = l + r >> 1;
    if(item[mid].y < b) l = mid + 1;
    else r = mid;
  }
  // cout << l << endl;
  if(item[l].y != b) return false;
  if(flag[l]) return false;
  flag[l] = true;
  return true;
}

void solve(){
  cin >> n >> m >> h >> k;
  string s;
  cin >> s;
  for(int i = 0; i < m; i++) cin >> item[i].x >> item[i].y;
  sort(item, item + m);
  // for(int i = 0; i < m; i++) cout << item[i].x << " " << item[i].y << endl;
  // cout << find(1, 0) << endl;
  // exit(0);
  int x = 0, y = 0;
  bool flag = true;
  for(int i = 0; i < n; i++){
    char c = s[i];
    h--;
    if(c == 'R') x++;
    else if(c == 'L') x--;
    else if(c == 'U') y++;
    else if(c == 'D') y--;
  // cout << x << " " << y << endl;
    if(h < 0){
      flag = false;
      break;
    }
    if(h < k && find(x, y)) h = k;
    // cout << h << endl;
  }

  if(flag) puts("Yes");
  else puts("No");
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}