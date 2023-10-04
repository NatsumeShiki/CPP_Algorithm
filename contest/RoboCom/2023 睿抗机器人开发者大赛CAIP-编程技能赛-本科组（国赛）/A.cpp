#include<bits/stdc++.h>
using namespace std;

#define int long long
string s;
int n, m;

void change(){
    for(int i = 0; i < m; i++){
        char c = s[i];
        if(c >= 'a' && c <= 'z'){
            if(c == 'a') c = 'z';
            else c -= 1;
        }else if(c >= 'A' && c <= 'Z'){
            if(c == 'Z') c = 'A';
            else c += 1;
        }
        s[i] = c;
    }
//    cout << s <<endl;
    for(int i = 0; i < m; ){
        if(s[i] >= '0' && s[i] <= '9'){
            i++;
            continue;
        }

        int j = i + 1;
        if(s[i] >= 'a' && s[i] <= 'z'){
            while(j < m && s[j] >= 'a' && s[j] <= 'z') j++;
            if(j - i >= 3){
                for(int k = i; k < j; k++){
                    s[k] -= 32;
                }
            }
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            while(j < m && s[j] >= 'A' && s[j] <= 'Z') j++;
//            cout << j << " " << s[i] <<endl;
            if(j - i >= 3){
                for(int k = i; k < j; k++){
                    s[k] += 32;
                }
            }
        }
        i = j;
//        cout << i <<endl;
    }
}

void solve(){
    cin >> n >> s;
    if(s != "yourname") cout << s << endl;
//    if(s == "yourname"){
//        cout << "wuzhijie" << endl;
//        return;
//    }
    if(s == "yourname") {
        s = "wuzhijie";
        cout << s <<endl;
    }
    m = s.size();
    for(int i = 0; i < n; i++){
        change();
    }
    cout << s << endl;
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
