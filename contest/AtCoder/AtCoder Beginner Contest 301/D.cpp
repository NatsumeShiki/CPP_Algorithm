#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
#define int long long

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 70, M = 1e6 + 10, INF = 0x3f3f3f3f;
// int n, m, k, t;
char a[N], b[N];
LL n;

void solve(){
    cin >> a >> n;
    int len1 = strlen(a);
    reverse(a, a + len1);

    LL res = 0;
    for(int i = 0, x = 1; i < len1; i++, x *= 2)
      if(a[i] == '1')
        res += x;
    if(res >= n){
      puts("-1");
      return;
    }

    int len2 = 0;
    LL x = n;
    while(x){
      if(x % 2) b[len2] = 1;
      len2++;
      x /= 2;
    }
    while(b[len2] == '0') len2--;
    // cout << len1 << " " << len2 << endl;

    res = 0;
    for(int i = 0, x = 1; i < len2; i++,x *= 2){
      if(a[i] == '?')
        res += x;
    }
    // cout << res << endl;

    for(int i = 0, x = 1; i < min(len1, len2) && res >= n; i++, x *= 2)
      res -= x;

    cout << res << endl;

}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}