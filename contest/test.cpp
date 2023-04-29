#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
int n;


void solve(){
string s;
    cin >> s;
    int t;
    cin >> t;
    while(t--){
        int st, ed;
        string first, last;
        cin >> st >> ed >> first >> last;
        st--, ed--;
        string str = s.substr(st, ed - st + 1);
        if(ed + 1 <= s.size()) s = s.substr(0, st) + s.substr(ed + 1);
        else s = s.substr(0, st);
        // cout <<s << endl;
        string target = first + last;
        // cout << target << endl;
        int len = target.size();
        bool flag = false;
        cout << len << endl;
        // cout << s.size() - len << endl;
        for(int i = 0; i + len <= s.size(); i++){
            if(s.substr(i, len) == target){
              cout << s.substr(i, len) << endl;
                if(i < s.size()) s = s.substr(0, i + first.size()) + str + s.substr(i + first.size());
                else s = s.substr(0, i + first.size()) + str;
                flag = true;
                break;
            }
        }
        if(!flag) s = s + str;
    }
    cout << s << endl;
}
// he,allcornetrrwecaneacheveryGreatWintheworldAcross

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