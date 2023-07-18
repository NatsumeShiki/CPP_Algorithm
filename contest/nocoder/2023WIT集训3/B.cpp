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
bool st[N];
int cnt;

void solve(){
  n = 1000;
  for(int i = 2; i <= n; i++){
    if(!st[i]) arr[cnt++] = i;
    for(int j = 0; arr[j] <= n / i; j++){
      st[arr[j] * i] = true;
      if(i % arr[j] == 0) break;
    }
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

    solve();
    // cout << cnt << endl;
  int T = 1;
  cin >> T;
  while(T--){
    int x;
    cin >> x;
    int res = 0;
    // for(int i = 0; i < cnt && x <= arr[i]; i++){
    //   res++;
    // }
    cout << upper_bound(arr, arr + cnt, x) - arr << endl;
  }

  return 0;
}