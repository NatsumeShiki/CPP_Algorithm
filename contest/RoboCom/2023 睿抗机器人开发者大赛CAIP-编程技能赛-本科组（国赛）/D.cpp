#include<bits/stdc++.h>
using namespace std;

#define int long long
string s;
int n, m;
const int N = 1010, M = 1e6 + 10;;
int g[N][N];
int cnt[M];
int h[N];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(i == 0 || g[i - 1][j] != g[i][j]) cnt[g[i][j]]++;
//            cout << g[i][j] << " " << cnt[g[i][j]] << endl;
        }

    int t = 0;
    while(true){
        map<int, int> mp;
        int index = 0x3f3f3f3f;
        for(int i = 0; i < m; i++){
            int t = h[i];
            if(t >= n) continue;
//            cout << t << " " << i << " " << g[t][i] <<endl;
            mp[g[t][i]]++;
            if(mp[g[t][i]] == cnt[g[t][i]]){
//                    cout << g[t][i] <<endl;
                index = min(index, g[t][i]);
            }
        }

        if(index == 0x3f3f3f3f){
            bool flag = true;
            for(int i = 0; i < n; i++){
                if(h[i] < n) flag = false;
            }
            if(!flag) cout << " Impossible";
            break;
        }

//        for(int i = 0; i < m; i++) cout << h[i] << " ";
//        cout <<endl;

        for(int i = 0; i < n; i++){
            int t = h[i];
            while(h[i] <= n && g[h[i]][i] == index) h[i]++;
        }
        if(t == 0) cout << index, t++;
        else cout << " " << index;
    }
    cout << endl;
}

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int T = 1;
//    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
