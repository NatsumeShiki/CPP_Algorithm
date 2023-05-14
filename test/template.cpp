#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
#include<unordered_map>
// #include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 1e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
unordered_map<int, int> pos;
int pre[N], in[N], post[N];
int cnt;

void build(int il, int ir, int pl, int pr){
    int root = pre[pl];
    int k = pos[root];

    if(il < k) build(il, k - 1, pl + 1, pr + 1 + (k - 1 - il));
    if(k < ir) build(k + 1, ir, pl + 1 + (k - 1 - il) + 1, pr);

    post[cnt++] = root;
}

void solve(){
//   int T;
//   cin >> T;
//   while(T--) {
//   }

    string a, b;
    while(cin >> a >> b){
        int n = a.size();
        cnt = 0;
        for(int i = 0; i < n; i++) pre[i] = a[i] - 'A';
        for(int i = 0; i < n; i++) {
            in[i] = b[i] - 'A';
            pos[in[i]] = i;
        }

        build(0, n - 1, 0, n - 1);

        for(int i = 0; i < cnt; i++) printf("%c", post[i] + 'A');
        puts("");
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

  return 0;
}