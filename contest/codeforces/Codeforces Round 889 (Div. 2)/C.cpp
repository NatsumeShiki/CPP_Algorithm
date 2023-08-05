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
int n, m, k, t;
int arr[N];
vector<int> alls;

void solve(){
  cin >> n;
  vector<PII> res;
  int maxv = -INF, minv = INF, minIndex = 0, maxIndex = 0;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    if(arr[i] > 0 && arr[i] > maxv){
      maxv = arr[i];
      maxIndex = i;
    }
    if(arr[i] < 0 && arr[i] < minv){
      minv = arr[i];
      minIndex = i;
    }
  }
  if(maxIndex){
    while(arr[maxIndex] <= 20) {
      arr[maxIndex] += arr[maxIndex];
      res.push_back({maxIndex, maxIndex});
    }
    // for(int i = 1; i <= 7; i++){
    //   arr[maxIndex] *= 2;
    //   res.push_back({maxIndex, maxIndex});
    // }
    arr[1] += arr[maxIndex];
    res.push_back({1, maxIndex});
    for(int i = 2; i <= n; i++){
      while(arr[i] < arr[i - 1]){
        arr[i] += arr[i - 1];
        res.push_back({i, i - 1});
      }
    }
  }else if(minIndex){
    while(arr[minIndex] >= -20) {
      arr[minIndex] += arr[minIndex];
      res.push_back({minIndex, minIndex});
    }
    // for(int i = 1; i <= 7; i++){
    //   arr[minIndex] *= 2;
    //   res.push_back({minIndex, minIndex});
    // }
    arr[n] += arr[minIndex];
    res.push_back({n, minIndex});
    for(int i = n - 1; i; i--){
      while(arr[i] > arr[i + 1]){
        arr[i] += arr[i + 1];
        res.push_back({i, i + 1});
      }
    }
  }else{
    cout << "0\n";
    return;
  }
  cout << res.size() << endl;
  for(auto [a, b] : res) cout << a << " " << b << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}