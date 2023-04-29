#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;

const int N = 2e5 + 10;
int n, k;
int a[N];
int gap[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> k;
    int cnt = 0;
    int i1 = 0, i2 = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      gap[i] = (a[i] - i) % k;
      if(gap[i]) {
        cnt++;
        if(!i1) i1 = i;
        else if(!i2) i2 = i;
      }
    }
    if(cnt > 2){
      puts("-1");
      continue;
    }else if(cnt == 0) {
      puts("0");
      continue;
    }

    swap(a[i1], a[i2]);
    cnt = 0;
    for(int i = 1; i <= n; i++){
      gap[i] = (a[i] - i) % k;
      if(gap[i]) cnt++;
    }
    if(cnt > 2) puts("-1");
    else puts("1");
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