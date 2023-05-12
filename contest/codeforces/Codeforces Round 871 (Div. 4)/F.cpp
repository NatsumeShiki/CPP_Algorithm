#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
const int N = 210, M = 20010;
int n, m;
int h[N], e[M], ne[M], idx;
int dout[N];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void solve(){
  int T;
  cin >> T;
  while(T--){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(dout, 0, sizeof dout);
    idx = 0;
    while(m--){
      int a, b;
      scanf("%d%d", &a, &b);
      add(a, b);
      add(b, a);
      dout[a]++, dout[b]++;
    }

    int start = 0;
    for(int i = 1; i <= n; i++)
      if(dout[i] == 1){
        start = i;
        break;
      }

    int a = h[start], b = e[a];
    int y = dout[b] - 1, x = 0;
    for(int i = h[b]; ~i; i = ne[i]){
      int j = e[i];
      if(dout[j] != 1){
        x = dout[j];
        break;
      }
    }

    printf("%d %d\n", x, y);
  }
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}