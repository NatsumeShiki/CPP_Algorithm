#include<bits/stdc++.h>
using namespace std;

// #define int long long
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

int read(){
   int s=0;
   char ch=getchar();
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s;
}

int lowbit(int x) { return x & -x; }

const int N = 6010, M = 1e7 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N][N];

void solve(){
  n = read();
  int res = 0;
  for(int i = 1; i <= n; i++){
    bool flag = false;
    for(int j = 1; j <= n; j++){
      arr[i][j] = read();
      if(i > j) {
        arr[j - n][i + n] = 1;
      }
      if(arr[i][j]) flag = false;
    }
    if(flag) res++;
  }

  int ans = 0;
  for(int i = 1; i <= n; i++){
    bool flag = false;
    for(int j = 1; j <= n; j++){
      if(arr[j][i]) flag = false;
    }
    if(flag) ans++;
  }

  
  printf("%d\n", min(ans, res));
}

signed main(){
  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}