#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
#include<unordered_map>
using namespace std;

struct edge{
  double mid, len;
  bool operator < (const edge &t)const{
    if(mid != t.mid) return mid < t.mid;
    return len  > t.len;
  }
};
const int N = 1e5 + 10;
edge edges[N];
int n, m;      

void solve(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    double l, r;
    cin >> l >> r;
    edges[i] = {(l + r) / 2, (r - l) / 2};
  }

  sort(edges, edges + n);

  while(m--){
    double start, end;
    cin >> start >> end;

    int l = 0, r = n - 1;
    while(l < r){
      int mid = l + r >> 1;
      if(edges[mid].mid < start) l = mid + 1;
      else r = mid;
    }

    int ll = l, rr;
    r = n - 1;
    while(l < r){
      int mid = l + r + 1 >> 1;
      if(edges[mid].mid <= end) l = mid ;
      else r = mid - 1;
    }

    rr = l;

    l = ll, r = rr;
    while(l < r){
      int mid = l + r >> 1;
      if(edges[mid].len > end - start) l = mid + 1;
      else r = mid;
    }

    ll = l, r = rr;
    while(l < r){
      int mid = l + r + 1 >> 1;
      if(edges[mid].len <= end - start) l = mid;
      else r = mid - 1;
    }

    rr = l;
    cout << rr - ll + 1 << endl;
  }

}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}