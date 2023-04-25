#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
 const int N = 210;
 int second[N], value[N];
 int n, t;

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> second[i];
    for(int i = 1; i <= n; i++) cin >> value[i];

    int res = 0, index = -1;
    for(int i = 1; i <= n; i++){
      if(t - (i - 1) >= second[i]){
        if(value[i] > res){
            res = value[i];
            index = i;
          }
      }
    }
    cout << index << endl;
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