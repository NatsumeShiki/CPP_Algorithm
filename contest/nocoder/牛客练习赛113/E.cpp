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
  
  if(m < n - 1 || m > n * (n - 1) / 2) {
    puts("-1");
    return;
  }

  int cnt = 1;
  while(m > n - cnt && m - n + cnt >= n - cnt - 1){
    m -= n - cnt;
    cnt++;
    cout << m << " " << cnt << endl;
  }

  cout << cnt << endl;
  for(int i = 1, j = 1; j <= cnt; i++, j += 2)
    arr[i] = j;
  for(int i = n, j = 2; j <= cnt; i--, j += 2)
    arr[i] = j;
    

  for(int i = 1; i <= n; i++) cout << arr[i] << " ";
  puts("");

  if(cnt % 2 == 1){
    for(int i = (cnt + 1) / 2 + 1, j = cnt + 1; j <= n; i++, j++)
      arr[i] = j;

for(int i = 1; i <= n; i++) cout << arr[i] << " ";
  puts("");

      int a = n - cnt / 2;
      m -= n - cnt;
      int b = a - m;
      cout << a << " " << b << " " << m << endl;
      // swap(arr[a], arr[b]);
      reverse(arr + b, arr + a + 1);
  }else{
    for(int i = n - cnt / 2, j = cnt + 1; j <= n; i--, j++)
      arr[i] = j;
      int a = cnt / 2 + 1;
      m -= n - cnt;
      int b = a + m;
      cout << a << " " << b << endl;
      // swap(arr[a], arr[b]);
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