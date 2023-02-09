// 给定一个具有 N
//  个顶点的凸多边形，将顶点从 1
//  至 N
//  标号，每个顶点的权值都是一个正整数。

// 将这个凸多边形划分成 N−2
//  个互不相交的三角形，对于每个三角形，其三个顶点的权值相乘都可得到一个权值乘积，试求所有三角形的顶点权值乘积之和至少为多少。

// 输入格式
// 第一行包含整数 N
// ，表示顶点数量。

// 第二行包含 N
//  个整数，依次为顶点 1
//  至顶点 N
//  的权值。

// 输出格式
// 输出仅一行，为所有三角形的顶点权值乘积之和的最小值。

// 数据范围
// N≤50
// ,
// 数据保证所有顶点的权值都小于109
// 输入样例：
// 5
// 121 122 123 245 231
// 输出样例：
// 12214884

/*
动态规划
  状态表示f[l, r]
    集合：所有将(l, l + 1) (l + 1, l + 2) ... (r - 1, r) (r, l) 这个多边形划分成三角形的方案
    属性：Min
  状态计算
    f[l, r] = min(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r])
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 55, M = 35; // M表示高精度计算的结果不会超过35位
int w[N];
LL f[N][N][M]; // 最终的结果是f[1][n]这个数组倒过来去掉前导零输出的结果
int n;

void add(LL a[], LL b[]){ // 高精度加法
    static LL c[M];
    memset(c, 0, sizeof c);
    for(int i = 0, t = 0; i < M; i++){
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}

void mul(LL a[], LL b){ // 高精度乘法
    static LL c[M];
    memset(c, 0, sizeof c);
    LL t = 0;
    for(int i = 0; i < M; i++){
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}

int cmp(LL a[], LL b[]){ // 高精度比较
    for(int i = M - 1; i >= 0; i--) 
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
        
    return 0;
}

void print(LL a[]){ // 输出高精度
    int k = M - 1; 
    while(k && !a[k]) k--; // 去掉前导零
    while(k >= 0) cout << a[k--]; // 输出结果
    cout << endl;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    
    LL temp[M]; // 拷贝数组
    for(int len = 3; len <= n; len++) // 长度
        for(int l = 1; l + len - 1 <= n; l++){ // 左端点
            int r = l + len - 1; // 右端点
            f[l][r][M - 1] = 1; // 将最高位设置为1表示最大值
            for(int k = l + 1; k < r; k++){ // 枚举分割点在哪里
                memset(temp, 0, sizeof temp); // 将temp重置为0
                temp[0] = w[l]; // 因为权值不会超过1e9，所以可以直接把它赋值在下标为0的位置上，在下面mul会把它分解
                mul(temp, w[k]);
                mul(temp, w[r]);
                add(temp, f[l][k]);
                add(temp, f[k][r]);
                if(cmp(f[l][r], temp) > 0) memcpy(f[l][r], temp, sizeof temp); // 取较小值
            }
        }
        
    print(f[1][n]); 
    
    return 0;
}