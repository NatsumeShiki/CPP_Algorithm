#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
int n;
const int N = 10010;
int a[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    bool flag1 = true, flag2 = true;
    for(int i = 0; i < n; i++){
      if(a[i] != n) flag1 = false;
      if(a[i] != 0) flag2 = false;
    }

    if(flag1) puts("-1");
    else if(flag2) puts("0");
    else{
      int index = 0;
      for(;index < n; index++){
        if(a[index] == n - index) {
          flag1 = true;
          break;
        }
        if(a[index] > n - index - 1) break;
      }
      if(flag1) puts("-1");
      else cout << n - index << endl;
    }
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