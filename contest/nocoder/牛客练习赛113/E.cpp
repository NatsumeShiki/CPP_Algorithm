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

void solve(){
  cin >> n >> m;
  int minv = n - 1, maxv = (n - 1) * n / 2;
  if(m < minv || m > maxv) {
    puts("-1");
    return;
  }

  int i = 2, t = 1, cnt = n - 1, now = 1;
  arr[1] = 1;
  for(; i <= n; i++, t = !t, cnt--){
    int x = now;
    if(t == 1) x += cnt;
    else x -= cnt;

    cout << x << " " << m << " " << cnt << endl;
    int last = n - i + 1;
    if(n * (n + 1) / 2 < m){
  
    }
    if(m > cnt){
      arr[x] = i;
      m -= cnt;
      now = x;
    }else{
      break;
    }
    
  }

  cout << i << " " << now << endl;
  if(arr[now + 1] == 0){
    for(now++; i <= n; i++, now++) arr[now] = i;
  }else{
    for(now--; i <= n; i++, now--) arr[now] = i;
  }

  for(int i = 1; i <= n; i++) cout << arr[i] << " ";
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