#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 3010;
int a[N], b[N], g[N];
vector<int> f[N][N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(f[i - 1][j].size() > f[i][j - 1].size()) f[i][j] = f[i - 1][j];
            else f[i][j] = f[i][j - 1];
            
            if(a[i] == b[j] && f[i][j].size() < f[i - 1][j - 1].size() + 1) f[i][j] = f[i - 1][j - 1], f[i][j].push_back(a[i]);
            
        }

    vector<int> res = f[n][n];
    int ans = 0;
    for(int i = 0; i < res.size(); i++){
        g[i] = 1;
        for(int j = 0; j < i; j++)
            if(res[j] < res[i])
                g[i] = max(g[i], g[j] + 1);
        ans = max(ans, g[i]);
    }
    cout << ans << endl;
    
    return 0;
}