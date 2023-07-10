#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PIII, int> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
char arr[M];
int fir[5], last[5];
int res = -INF;

int getNum(char c){
  if(c == 'A') return 1;
  if(c == 'B') return 10;
  if(c == 'C') return 100;
  if(c == 'D') return 1000;
  return 10000;
}

void get(){
  int cnt = 0;
  char maxv = 'A';
  for(int i = n - 1; i >= 0; i--){
    if(arr[i] < maxv){
      cnt -= getNum(arr[i]); 
    }else{
      cnt += getNum(arr[i]);
      maxv = arr[i];
    }
  }

  res = max(res, cnt);

  // cout << res << endl;
}

void solve(){
  cin >> arr;
  n = strlen(arr);
  res = -1e16;
  memset(fir, 0x3f, sizeof fir);
  memset(last, -1, sizeof last);
  for(int i = 0; i < n; i++){
    int x = arr[i] - 'A';
    fir[x] = min(fir[x], i);
    last[x] = max(last[x], i);
  }

  for(int i = 0; i < 5; i++){
    int x = fir[i];
    if(x < 0 || x >= n) continue;
    char c = arr[x];
    for(int j = 0; j < 5; j++){
      char ch = j + 'A';
      arr[x] = ch;
      get();
      arr[x] = ch;
      get();
      arr[x] = c;
    }
  }

  for(int i = 0; i < 5; i++){
    int x = last[i];
    if(x < 0 || x >= n) continue;
    char c = arr[x];
    for(int j = 0; j < 5; j++){
      char ch = j + 'A';
      arr[x] = ch;
      get();
      arr[x] = ch;
      get();
      arr[x] = c;
    }
  }

  cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  // for(int i = 0; i < 2e5; i++) printf("D");
  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}