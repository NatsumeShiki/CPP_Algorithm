#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PIII, int> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
map<int, int> mp;

void solve(){
  // cout << 200 << endl;
  // for(int i = 0; i < 200; i++) cout << 1 << " ";
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  int res = 0;
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      int len = (j - i + 1 + 1) / 2;
      // cout << len << endl;
      mp.clear();
      for(int k = i; k <= j; k++){
        mp[arr[k]]++;
        if(mp[arr[k]] >= len){
          res++;
          break;
        }
      }
    }
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
  while(T--){
    solve();
  }

  return 0;
}