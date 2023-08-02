#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define FOR(n) for(int i = 0; i < n; i++) 
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

const int N = 510, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
map<string, vector<PII>> mp;
map<string, PII> mp2;
string g[N][N];

bool cmp(string s1, string s2){
  for(int i = 0; i < min(s1.size(), s2.size()); i++)
    if(s1[i] != s2[i])
      return s1[i] > s2[i];
  return s1.size() > s2.size();
}

void solve(){
  cin >> n >> m >> k;
  for(int i = 0; i < k; i++){
    string s;
    int x, y;
    cin >> s >> x >> y;
    if(mp.count(s)) mp[s].push_back({x, y});
    else {
      vector<PII> v;
      v.push_back({x, y});
      mp[s] = v;
    }
    if(g[x][y] != ""){
      string str = g[x][y];
      if(cmp(s, str)) {
        g[x][y] = s;
        mp2[s] = {x, y};
      }
    }else{
      g[x][y] = s;
      mp2[s] = {x, y};
    }
  }

  // for(auto [a, b] : mp){
  //   cout << a << endl;
  //   for(auto [c, d] : b) cout << c << " " << d << endl;
  //   cout << endl;
  // }

  cin >> k;
  while(k--){
    string s;
    char op;
    cin >> s >> op;
    if(mp[s].empty()){
      puts("unexisted empire.");
      continue;
    }
    auto [x, y] = mp2[s];
    // cout <<x << " " << y << endl;
    if(op == 'W') x--;
    else if(op == 'S') x++;
    else if(op == 'A') y--;
    else y++;
    // cout <<x << " " << y << endl;
    if(x < 1 || x > n || y < 1 || y > m) {
      puts("out of bounds!");
      continue;
    }
    if(g[x][y] == ""){
      puts("vanquish!");
      mp[s].push_back({x, y});
      mp2[s] = {x, y};
      g[x][y] = s;
    }else{
      if(g[x][y] == s){
        puts("peaceful.");
        mp2[s] = {x, y};
      }else{
        string str = g[x][y];
        if(mp[s].size() > mp[str].size()){
          for(auto [a, b] : mp[str]){
            mp[s].push_back({a, b});
            g[a][b] = s;
          }
          cout << s << " wins!" << endl;
          mp2[s] = {x, y};
          mp[str].clear();
        }else if(mp[s].size() == mp[str].size() && cmp(s, str)){
          for(auto [a, b] : mp[str]){
            mp[s].push_back({a, b});
            g[a][b] = s;
          }
          cout << s << " wins!" << endl;
          mp2[s] = {x, y};
          mp[str].clear();
        }
        else{
          for(auto [a, b] : mp[s]){
            mp[str].push_back({a, b});
            g[a][b] = str;
          }
          mp[s].clear();
          cout << str << " wins!" << endl;
        }
      }
    }

  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif


  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}