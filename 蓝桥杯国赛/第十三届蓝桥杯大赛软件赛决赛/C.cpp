#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

//#define int long long
typedef long long LL;
const int N = 2e5 + 10;
LL n, m;
LL a[N], b[N]; 

bool check(LL mid){
	LL sum = 0;
	for(int i = 1; i <= n; i++){
		LL k = mid - a[i];
		if(k < 0) k = 0;
		sum += k;
		
		if(k > b[i]) return false;
	}
	
	if(sum > m) return false;
	return true;
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n ;i++) cin >> a[i]; 
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	LL l = 0, r = 1e6;
	while(l < r){
		LL mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	
	cout << l << endl;
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
