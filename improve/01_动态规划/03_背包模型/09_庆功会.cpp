// 为了庆贺班级在校运动会上取得全校第一名成绩，班主任决定开一场庆功会，为此拨款购买奖品犒劳运动员。

// 期望拨款金额能购买最大价值的奖品，可以补充他们的精力和体力。

// 输入格式
// 第一行二个数n，m，其中n代表希望购买的奖品的种数，m表示拨款金额。

// 接下来n行，每行3个数，v、w、s，分别表示第I种奖品的价格、价值（价格与价值是不同的概念）和能购买的最大数量（买0件到s件均可）。

// 输出格式
// 一行：一个数，表示此次购买能获得的最大的价值（注意！不是价格）。

// 数据范围
// n≤500,m≤6000
// ,
// v≤100,w≤1000,s≤10
// 输入样例：
// 5 1000
// 80 20 4
// 40 50 9
// 30 50 7
// 40 30 6
// 20 20 1
// 输出样例：
// 1040

// 自己的代码 多重背包问题2添加了一层背景，其他没差
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 4500, M = 6010;
int v[N], w[N];
int f[N][M];

int main(){
    int n, m;
    cin >> n >> m;
    
    int cnt = 0;
    while(n--){
        int a, b, s;
        cin >> a >> b >> s;
        int t = 1;
        while(t <= s){
            cnt++;
            v[cnt] = t * a;
            w[cnt] = t * b;
            s -= t;
            t *= 2;
        }
        
        if(s){
            cnt++;
            v[cnt] = s * a;
            w[cnt] = s * b;
        }
    }
    
    n = cnt;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++){
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
        
    cout << f[n][m] << endl;
    
    return 0;
}

// 自己的代码 一维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 4500, M = 6010;
int f[M];
int v[N], w[N];

int main(){
    int n, m;
    cin >> n >> m;
    
    int cnt = 0;
    while(n--){
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while(k <= s){
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s){
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    n = cnt;
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            
    cout << f[m] << endl;
    
    return 0;
}

// 自己的代码 方法二：二维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 6010;
int f[N][M];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        for(int j = m; j >= 0; j--)
            for(int k = 0; k <= s && k * v <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v] + k * w);
    }
    
    cout << f[n][m] << endl;
    
    return 0;
}

// 自己的代码 方法二：一维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 6010;
int f[N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        for(int j = m; j >= 0; j--)
            for(int k = 0; k <= s && k * v <= j; k++)
                f[j] = max(f[j], f[j - k * v] + k * w);
    }
    cout << f[m] << endl;
    
    return 0;
}