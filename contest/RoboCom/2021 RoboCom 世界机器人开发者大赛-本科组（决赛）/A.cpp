#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<string, int> PSI;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;

void solve(){
  cin >> n >> m;
  int x = 0, y = 0, sum = 0;
  cout << 0 << " " << 0 << endl;
  for(int i = 0, j = 0; i < n; i++, j = !j){
    int t;
    cin >> t;
    if(j == 0) {
      int gap = abs(y - t);
      // sum += gap;
      if(sum + gap >= m){
        int k = m - sum;
        if(t > y) y += k;
        else y -= k; 
        cout << x << " " << y << endl;
        sum = sum + gap - m;
      }else sum += gap;
      y = t;
    } else {
      int gap = abs(x - t);
      if(sum + gap >= m){
        int k = m - sum;
        if(t > x) x += k;
        else x -= k;
        cout << x << " " << y << endl;
        sum = sum + gap - m;
      }else sum += gap;
      x = t;
    }
  }

  int gap = abs(x) + abs(y);
  if(sum + gap > m){
    if(x != 0){
      if(x > 0) x -= m - sum;
      else x += m - sum;
    }else if(y != 0){
      if(y > 0) y -= m - sum; 
      else y += m - sum;
    }
    cout << x << " " << y << endl;
  }
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