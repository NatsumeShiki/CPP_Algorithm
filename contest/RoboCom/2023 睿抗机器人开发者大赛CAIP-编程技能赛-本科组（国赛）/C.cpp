#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
string s;
int n, m, k;
const int N = 1010, M = 10010, K = 1e6 + 10;
int ti[N];
int query[K];
int cnt[M];

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> ti[i];
    for(int i = 1; i <= k; i++) cin >> query[i];

    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    for(int i = 1; i <= min(m, k); i++) {
        heap.push({ti[query[i]], {i, i}});
        cnt[i]++;
//        cout << i << " " << ti[query[i]] <<endl;

    }
    int index = min(m, k) + 1;
//    cout << index << endl;

    int t = 0;
    for(int i = 1; i <= 1e6; i++){
            vector<PII> ve;
        while(heap.size()){
            auto [a, b] = heap.top();
            if(a - i > 0) break;
            heap.pop();
            ve.push_back({b.second, a});
//            cout << i << " " << b.second << " ";
            if(t == 0) cout << b.first << ":" << a, t++;
            else cout << " " << b.first << ":" << a;
//            if(index <= k){
//                heap.push({a + ti[query[index]], {index, b.second}});
////                cout << b.second << endl;
//                cnt[b.second]++;
//                index++;
//            }
        }
        sort(ve.begin(), ve.end());
        for(auto [a, b] : ve){
            if(index > k) break;
//            cout << a << " " << b <<endl;
            heap.push({b + ti[query[index]], {index, a}});
            cnt[a]++;
            index++;
        }
    }
    cout << endl;
    for(int i = 1; i <= m; i++) {
        if(i != m) cout << cnt[i] << " ";
        else cout << cnt[i] <<endl;
    }
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
