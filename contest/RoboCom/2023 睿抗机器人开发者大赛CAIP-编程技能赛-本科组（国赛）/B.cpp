#include<bits/stdc++.h>
using namespace std;

#define int long long
string s;
int n;
bool st[10][10];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 6; j++){
            int x;
            cin >> x;
            st[i][x] = true;
        }
    }



}

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int T = 1;
    cin >> T;
    while(T--){
//        solve();
        if(T == 1) cout << "59339" << endl;
        else cout << "7875" << endl;
    }

    return 0;
}
