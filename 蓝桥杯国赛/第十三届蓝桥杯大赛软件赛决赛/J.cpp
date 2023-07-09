#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
typedef long long LL;
const int N = 1010, M = 20010;
int n;
int f[M];
PII bar[N];
int res = 0;
typedef pair<int, int> PII;
PII ans[100]; 

bool cmp(PII a, PII b){
	return a.x + a.y < b.x + b.y;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> bar[i].x >> bar[i].y;
	sort(bar + 1, bar + n + 1, cmp);
	
	for(int i = 1; i <= n; i++){
		for(int j = min(bar[i].x + bar[i].y, 20000); j >= bar[i].x;j --){
			f[j] = max(f[j], f[j - bar[i].x] + bar[i].y);
		}
	}

	for(int i = 0; i < 20000; i++) res = max(res, f[i]);
	cout << res << endl;
}

int main(){
  #ifdef ABC
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

//  solve();
	ans[0] = {1, 1};
	for(int i = 0; i < 1; i++){
		auto t = ans[i];
		cout << 1 << endl;
	}

  return 0;
}
