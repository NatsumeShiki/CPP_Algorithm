#include<bits/stdc++.h>
using namespace std;

#define int long long
string s;
int n, m, k;
const int N = 1010;
int cnt[N * 2];
int a[N], b[N];

void solve(){
    memset(cnt, 0, sizeof cnt);
    cin >> n >> m >> k;
    int res = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        res = max(res, cnt[a[i]]);
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        cnt[b[i]]++;
        res = max(res, cnt[b[i]]);
    }
    cout << max(k, n + m - res) <<endl;
}

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int T = 1;
    cin >> T;
    while(T--){
        solve();
//        cout << 1 << endl;
    }

    return 0;
}
