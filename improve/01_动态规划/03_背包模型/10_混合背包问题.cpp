// 有 N
//  种物品和一个容量是 V
//  的背包。

// 物品一共有三类：

// 第一类物品只能用1次（01背包）；
// 第二类物品可以用无限次（完全背包）；
// 第三类物品最多只能用 si
//  次（多重背包）；
// 每种体积是 vi
// ，价值是 wi
// 。

// 求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
// 输出最大价值。

// 输入格式
// 第一行两个整数，N，V
// ，用空格隔开，分别表示物品种数和背包容积。

// 接下来有 N
//  行，每行三个整数 vi,wi,si
// ，用空格隔开，分别表示第 i
//  种物品的体积、价值和数量。

// si=−1
//  表示第 i
//  种物品只能用1次；
// si=0
//  表示第 i
//  种物品可以用无限次；
// si>0
//  表示第 i
//  种物品可以使用 si
//  次；
// 输出格式
// 输出一个整数，表示最大价值。

// 数据范围
// 0<N,V≤1000

// 0<vi,wi≤1000

// −1≤si≤1000
// 输入样例
// 4 5
// 1 2 -1
// 2 4 1
// 3 4 0
// 4 5 2
// 输出样例：
// 8

// 如果s等于0，将s赋值为1000，表示有无穷个，如果s等于-1，s赋值为1，表示有1个，然后按照完全背包问题2来做，使用二进制优化即可
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, M = 10010;
int f[N], v[M], w[M];
int n, m, cnt = 1;

int main(){
    cin >> n >> m;
    while(n--){
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 0) c = 1000;
        else if(c == -1) c = 1;
        
        int t = 1;
        while(t <= c){
            v[cnt] = a * t;
            w[cnt] = b * t;
            cnt++;
            c -= t;
            t *= 2;
        }
        
        if(c){
            v[cnt] = a * c;
            w[cnt] = b * c;
            cnt++;
        }
    }
    
    n = cnt;
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            
    cout << f[m] << endl;
    
    return 0;
}

// 大佬的代码
// 分成两种情况，如果s == 0，就用完全背包来做，否则看成多重背包问题2来做，01背包是特殊的多重背包，所以可以统一来做，使用二进制优化
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int f[N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        if(s == 0){
            for(int j = v; j <= m; j++)
                f[j] = max(f[j], f[j - v] + w);
        }else{
            if(s == -1) s = 1;
            for(int k = 1; k <= s; k *= 2){
                for(int j = m; j >= k * v; j--)
                    f[j] = max(f[j], f[j - k * v] + k * w);
                s -= k;
            }
            if(s){
                for(int j = m; j >= s * v; j--)
                    f[j] = max(f[j], f[j - s * v] + s * w);
            }
        }
    }
    cout << f[m] << endl;
    
    return 0;
}