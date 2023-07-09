#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 110, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
string s[N];
string str[N];
int price[N];

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n ;i++){
    cin >> s[i];
  }
  for(int i = 1; i <= m; i++){
    cin >> str[i];
  }
  for(int i = 0; i <= m; i++){
    cin >> price[i];
    // cout << price[i] << endl;
  }

  int res = 0;
  for(int i = 0; i < n; i++){
    bool flag = false;
    for(int j = 1; j <= m; j++){
      if(s[i] == str[j]) {
        res += price[j];
        flag = true;
        break;
      }
    }
    if(!flag) res += price[0];
  }

  cout << res << endl;


}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}