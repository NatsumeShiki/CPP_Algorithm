#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
char s[N];

void solve(){
  scanf("%s", s);
  n = strlen(s);

  if(n % 2 == 1){
    LL x = 0, y = 0;
    for(int i = 0; i < n; i++)
      if(s[i] == '0') x++;
      else y++;

    char c = x > y ? '0' : '1';
    LL cnt = 0;
    for(int i = 0, j = 0; i < n; i++){
      if(s[i] == c){
         cnt += abs(i - j);
         j += 2;
      }
    }
    cout << cnt << endl;
  }else{
    LL cnt1 = 0;
    for(int i = 0, j = 0; i < n; i++){
      if(s[i] == '0'){
         cnt1 += abs(i - j);
         j += 2;
      }
    }

    LL cnt2 = 0;
    for(int i = 0, j = 0; i < n; i++){
      if(s[i] == '1'){
         cnt2 += abs(i - j);
         j += 2;
      }
    }
    cout << min(cnt1, cnt2) << endl;
  }
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