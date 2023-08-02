#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
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

const int N = 110, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
int cnt[N][N];
int p[N];

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> p[i];
    cin >> k;
    while(k--){
      int x;
      cin >> x;
      cnt[i][x]++;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      if(p[i] < p[j]) continue;
      bool flag = true;
      int cnt1 = 0, cnt2 = 0;
      for(int k = 1; k <= m; k++){
        if(cnt[j][k] == 0 && cnt[i][k] == 1){
          flag = false;
          break;
        }
        if(cnt[j][k] == 1) cnt1++;
        if(cnt[i][k] == 1) cnt2++;
      }
      if(!flag) continue;
      if(p[i] > p[j] || cnt1 > cnt2){
        puts("Yes");
        return;
      }
    }
  }
  puts("No");
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}