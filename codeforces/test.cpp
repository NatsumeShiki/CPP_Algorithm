#include<iostream>
using namespace std;

const int N = 1010;
int a[N][N];
int n, k;

int change(int target){
  int res = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(a[i][j] == target && a[n - i + 1][n - j + 1] != target) res++;

  return res;
}

void solve(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) 
      cin >> a[i][j];

  int cnt = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
      if(a[i][j] != a[n - i + 1][n - j + 1]){
        a[n - i + 1][n - j + 1] = a[i][j];
        cnt++;
      }
    }

  if(cnt > k) puts("NO");
  else if(n % 2 == 0 && (k - cnt) % 2 == 1) puts("NO");
  else puts("YES");
}

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}