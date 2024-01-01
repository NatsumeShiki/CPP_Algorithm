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

bool check(int maxIndex, int maxv, int minIndex, int minv){
  if(!maxIndex) return false;
  int minCnt = 0, maxCnt = 0;
  int cnt = 0;
  int x = arr[maxIndex];
  while(x + arr[minIndex] < 0){
    x *= 2;
    cnt++;
  }

  for(int i = 1; i <= n; i++){
    if(arr[i] > 0) maxCnt++;
    else if(arr[i] < 0) minCnt++;
  }

  return cnt + minCnt <= 11;
}

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
  
  int cnt = 31;
  cout << "31\n";
  if(check(maxIndex, maxv, minIndex, minv)){
    // cout << "First\n";
    // cout<< arr[maxIndex] << " " << arr[minIndex] << endl;
    while(arr[maxIndex] + arr[minIndex] < 0){
      res.push_back({maxIndex, maxIndex});
      arr[maxIndex] *= 2;
      cnt--;
    }
    for(int i = 1; i <= n; i++){
      if(arr[i] < 0){
        arr[i] += arr[maxIndex];
        res.push_back({i, maxIndex});
        cnt--;
      }
    }
    for(int i = 2; i <= n; i++){
      if(arr[i] < arr[i - 1]){
        arr[i] += arr[i - 1];
        res.push_back({i, i - 1});
        cnt--;
      }
    }
    while(cnt > 0){
      cnt--;
      res.push_back({n, n});
    }
  }else if(minIndex){
    while(arr[minIndex] + arr[maxIndex] > 0){
      res.push_back({minIndex, minIndex});
      arr[minIndex] *= 2;
      cnt--;
    }
    for(int i = 1; i <= n; i++){
      if(arr[i] > 0){
        arr[i] += arr[minIndex];
        res.push_back({i, minIndex});
        cnt--;
      }
    }
    for(int i = n - 1; i; i--){
      if(arr[i] > arr[i + 1]){
        arr[i] += arr[i + 1];
        res.push_back({i, i + 1});
        cnt--;
      }
    }
    while(cnt > 0){
      cnt--;
      res.push_back({1, 1});
    }
  }else{
    while(cnt--) res.push_back({1, 1});
  }
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