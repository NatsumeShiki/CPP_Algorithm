#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
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

const int N = 1010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int cnt1[N], cnt2[N];

void solve(){
  string s;
  cin >> s;
  int sum = 0;
  int flag = 1;
  n = s.size();
  for(int i = 0; i < n;){
    int a = 0, b = 0;
    if(i < n && s[i] >= '0' && s[i] <= '9'){
      while(i < n && s[i] >= '0' && s[i] <= '9'){
        a = a * 10 + s[i] - '0';
        i++;
      }
    }
    // else a = 1;

    // cout << a << " a\n";
    // cout << s[i] << endl;
    if(i < n && s[i] == 'd'){
      i++;
      while(i < n && s[i] >= '0' && s[i] <= '9'){
        b = b * 10 + s[i] - '0';
        i++;
      }
      if(a == 0) a = 1;
      if(flag == 1) cnt1[b] += a; 
      else cnt2[b] += a;
    }else{
      // cout << a << " " << sum << endl; 
      sum += a * flag;
      if(s[i] == '+') flag = 1;
      else flag = -1;
      i++;
      continue;
    }

    // cout << b << "  b\n";

    if(i < n && (s[i] == '+' || s[i] == '-')){
      // sum += flag * a;
      if(s[i] == '+') flag = 1;
      else flag = -1;
      i++;
    }
  }
  // cout << sum << endl;
  for(int i = 1; i <= 1000; i++)
    if(cnt1[i] + cnt2[i] != 0){
      cout << i << " " << cnt1[i] + cnt2[i] << endl;
    }

  int res1 = sum, res2 = sum;
  for(int i = 1; i <= 1000; i++){
      // if(i == 23) cout << cnt1[i] << " " << cnt2[i] << endl;
      res1 += cnt1[i] - cnt2[i] * i;
      res2 += cnt1[i] * i - cnt2[i];
  }

  cout << res1 << " " << res2 << endl;

}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}