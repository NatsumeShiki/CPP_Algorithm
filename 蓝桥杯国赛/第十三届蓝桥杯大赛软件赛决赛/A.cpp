#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

typedef long long LL;
LL res; 



void solve(){
	dfs(0, 1, 0);
	cout << res << endl;
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
