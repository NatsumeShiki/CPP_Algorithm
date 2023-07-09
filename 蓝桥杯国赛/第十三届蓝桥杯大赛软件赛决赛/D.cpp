#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

typedef long long LL;
LL n, a, b;
const int N = 20;
int s[N];
LL res = 0;

void dfs(int u, LL ans){
	if(u == n){
		res = max(res, ans);
		return;
	}
	
	int k = 9 - s[u];
	if(a >= k){
		a -= k;
		dfs(u + 1, ans * 10 + 9);
		a += k;
	}else{
		int temp = a;
		a = 0;
		dfs(u + 1, ans * 10 + s[u] + temp);
		a = temp;
	}
	
	k = s[u] + 1;
	if(b >= k){
		b -= k;
		dfs(u + 1, ans * 10 + 9);
		b += k;
	}
}

void solve(){
	cin >> n >> a >> b;
	int start;
	for(start = 19; n; start--){
		s[start] = n % 10;
		n /= 10;
	}
	
	n = 19 - start;
//	cout << n << endl;
	for(int i = 0; start <= 19; i++)
		s[i] = s[++start];
		
	dfs(0, 0);
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
