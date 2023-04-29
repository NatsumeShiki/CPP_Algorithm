#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
typedef long long LL;
const int N = 2e5 + 10;
int n;
int cnt[30];
char s[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    cin >> s + 1;
    memset(cnt, 0, sizeof cnt);
    if(n % 2){
      puts("-1");
      continue;
    }

    for(int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
    // for(int i = 0; i < 30; i++) cout << cnt[i] << " ";
    // cout << endl;
    bool flag = false;
    for(int i = 0; i < 30; i++)
      if(cnt[i] > n / 2){
        // cout << cnt[i] << endl;
        flag = true;
        break;
      }

    if(flag){
      puts("-1");
      continue;
    }

    memset(cnt, 0, sizeof cnt);
    int res = 0, sum = 0;;
    for(int i = 1; i <= n / 2; i++)
      if(s[i] == s[n - i + 1])
        cnt[s[i] - 'a']++;
    int maxd = 0;
    for(int i = 0; i < 30; i++){
      maxd = max(maxd, cnt[i]);
      sum += cnt[i];
    }

    if(maxd >= (sum + 1) / 2) res = maxd;
    else res = (sum + 1) / 2;
    
    cout << res << endl;
  }
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