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

void solve(){

}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endifcontest/template/A.cpp contest/template/B.cpp contest/template/C.cpp contest/template/D.cpp contest/template/E.cpp contest/template/F.cpp contest/template/G.cpp contest/template/H.cpp contest/template/in.txt contest/template/out.txt
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}