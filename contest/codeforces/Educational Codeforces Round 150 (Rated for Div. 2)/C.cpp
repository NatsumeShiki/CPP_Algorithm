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
int arr[N];
bool res[N];
// int a[N];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  res[0] = res[1] = true;
  int flag;
  if(arr[0] < arr[1]) flag = 0;
  else if(arr[0] > arr[1]) flag = 1;
  else flag = 2;

  int first = arr[0], last = arr[1];
  for(int i = 2; i < n; i++){
    // cout << flag << " " << last << endl;
    if(flag == 0){
      if(arr[i] >= last){
        res[i] = true;
        last = arr[i];
      }else{
        if(arr[i] <= first){
          // cout << first << endl;
          res[i] = true;
          last = arr[i];
          flag = 3;
        }
      }
    }else if(flag == 3){
      if(arr[i] >= last && arr[i] <= first){
        res[i] = true;
        last = arr[i];
      }
    }else if(flag == 1){
      if(arr[i] >= last && arr[i] <= first){
        res[i] = true;
        last = arr[i];
      }
    }else if(flag == 2){
      if(arr[i] == last){
        res[i] = true;
        last = arr[i];
      }else if(arr[i] < last){
        res[i] = true;
        last = arr[i];
        flag = 1;
      }else{
        flag = 0;
        res[i] = true;
        last = arr[i];
      }
    }
  }

  for(int i = 0; i < n; i++){
    cout << res[i];
    res[i] = 0;
  }
  cout << endl;

}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}