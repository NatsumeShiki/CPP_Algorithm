#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
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

const int N = 110, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int s[N];

void solve(){
  cin >> n >> k;
  m = k - 1;
  memset(arr, 0, sizeof arr);
  memset(s, 0, sizeof s);
  for(int i = 1; i <= n; i++){
    s[i] = s[i - 1];
    if((i + m) / k > s[i]){
      arr[i] = 1;
      s[i] ++;
    }
  }
  memset(s, 0, sizeof s);
  // if(arr[n] == 1) s[n] = 1;
  arr[n] = 1;
  s[n] = 1;
  for(int i = n - 1; i >= 1; i--){
    s[i] = s[i + 1];
    if(arr[i] == 1) s[i]++;
    if((n - i + 1 + m) / k > s[i]){
      arr[i] = 1;
      s[i] ++;
    }
  }

  int res = 0;
  for(int i = 1; i <= n; i++){
    if(arr[i] == 1)
      res++;

    // cout << arr[i] << " ";
  }
  // cout << endl;

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
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}