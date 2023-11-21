#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<string, int> PSI;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
vector<int> alls;
int primes[M], cnt;
bool st[M];
vector<int> ans;
bool vis[M];

void init(int n){
  st[1] = true;
  for(int i = 2; i <= n; i++){
    if(!st[i]) primes[cnt++] = i;
    for(int j = 0; i * primes[j] <= n; j++){
      st[primes[j] * i] = true;
      if(i % primes[j] == 0) break;
    }
  }
}

// bool dfs(int u){
// 	if(u == n){
// 		if(st[abs(ans[0] - ans[u - 1])]) return false;
// 		for(auto u: ans) cout << u << ' ';
// //		cout << ans.size() << endl;
		
// 		cout << endl;
// 		return true;
// 	}
// 	for(int i = 1; i <= n; i ++ ){
// 		if(!vis[i] && (ans.size() == 0 || !st[abs(i - ans[u - 1])])){
// 			ans.push_back(i);
// 			vis[i] = true;
// 			if(dfs(u + 1)) return true;
// 			ans.pop_back();
// 			vis[i] = false;
// 		}
// 	}
// 	return false;
// }

bool dfs(int u){
  if(u == n){
    if(st[abs(ans.back() - ans[0])]) return false;;
    for(auto a : ans) cout << a << " ";
    cout << endl;
    return true;
  }

  for(int i = 1; i <= n; i++){
    if(!vis[i] && (ans.empty() || !st[abs(ans.back() - i)])){
      vis[i] = true;
      ans.push_back(i);
      if(dfs(u + 1)) return true;
      vis[i] = false;
      ans.pop_back();
    }
  }
  return false;
}

void solve(){
  ans.clear();
  memset(vis, 0, sizeof vis);
  cin >> n;
  // if(n <= 4) {
  //   cout << "-1\n";
  //   return;
  // }else if(n <= 10){
  //   for(int i = 1; i <= n; i += 2) cout << i << " ";
  //   for(int i = 2; i <= n; i += 2) cout << i << " ";
  //   cout << endl;
  //   return;
  // } 
  if(n <= 15){
		if(!dfs(0)) cout << "-1" << endl;
		// return; 
	}else{
    // deque<int> res;
    // res.push_back(n);
    // for(int i = n - 2; i >= 6; i--){
    //   if(i & 1) res.push_front(i);
    //   else res.push_back(i);
    //   if(i == n - 4){
    //     if(i & 1) res.push_front(n - 1);
    //     else res.push_back(n - 1);
    //   }
    // }
    // cout << "4 1 3 5 2";
    // for(auto a : res) cout << " " << a;
    vector<int> res;
    if(n % 2){
      for(int i = 1; i <= n; i += 2) {
        res.push_back(i);
        if(i == 5) res.push_back(2);
        if(i == n - 6) res.push_back(n - 1);
      }
      for(int i = n - 3; i >= 4; i -= 2) res.push_back(i);
    }else{
      for(int i = 2; i <= n; i += 2) {
        res.push_back(i);
        if(i == 4) res.push_back(1);
        if(i == 6) res.push_back(3);
        if(i == n - 6) res.push_back(n - 1);
      }
      for(int i = n - 3; i >= 5; i -= 2) res.push_back(i);
    }
    for(int a : res) cout << a << " ";
    cout << endl;
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  init(1e6);
  // for(int i = 16; i <= 30; i++) cout << i << endl;
  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}