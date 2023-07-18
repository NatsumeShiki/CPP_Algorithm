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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int s[N];

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> arr[i];
  for(int i = 3; i <= n; i++) {
    s[i] = s[i - 1];
    if(arr[i - 2] >= arr[i - 1] && arr[i - 1] >= arr[i]){
      s[i]++;
    }
  }


  while(m--){
    int l, r;
    cin >> l >> r;
    if(r - l + 1 <= 2){
      cout << r - l + 1 << endl;
      continue;
    }else{
      cout << r - l + 1 - (s[r] - s[l + 1]) << endl;
    }
    
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}