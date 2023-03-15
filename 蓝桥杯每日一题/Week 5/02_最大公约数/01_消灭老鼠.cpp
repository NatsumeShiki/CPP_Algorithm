// 约翰的农场可以看作一个二维平面。

// 农场中有 n
//  个老鼠，在毁坏着农田。

// 第 i
//  个老鼠的位置坐标为 (xi,yi)
// 。

// 不同老鼠可能位于同一位置。

// 在 (x0,y0)
//  处，装有一个双向发射的激光枪，该位置没有老鼠。

// 激光枪每次发射都可以将穿过点 (x0,y0)
//  的某一条直线上的所有老鼠都消灭掉。

// 请问，为了消灭所有老鼠，至少需要激光枪发射几次。

// 输入格式
// 第一行包含三个整数 n,x0,y0
// ，表示共有 n
//  只老鼠，激光枪的位置为 (x0,y0)
// 。

// 接下来 n
//  行，每行包含两个整数 xi,yi
// ，表示第 i
//  只老鼠的位置为 (xi,yi)
// 。

// 输出格式
// 一个整数，表示激光枪的最少发射次数。

// 数据范围
// 前 5
//  个测试点满足 1≤n≤5
// 。
// 所有测试点满足 1≤n≤1000
// ，−104≤xi,yi≤104
// 。

// 输入样例1：
// 4 0 0
// 1 1
// 2 2
// 2 0
// -1 -1
// 输出样例1：
// 2
// 输入样例2：
// 2 1 2
// 1 1
// 1 0
// 输出样例2：
// 1

#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;

typedef pair<int, int> PII;
const int N = 1010;
PII res[N];
int n, x, y;
int cnt;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a -= x, b -= y;
        int t = gcd(a, b);
        a /= t, b /= t;
        bool flag = true;
        for(int i = 0; i < cnt; i++){
            if(res[i].first == a && res[i].second == b){
                flag = false;
                break;
            }
        }
        if(flag) res[cnt++] = {a, b};
    }
    cout << cnt << endl;
    
    
    return 0;
}

// 大佬的代码
#include<iostream>
#include<set>
using namespace std;

typedef pair<int, int> PII;
int n, x, y;
set<PII> S;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    cin >> n >> x >> y;
    while(n--){
        int a, b;
        cin >> a >> b;
        a -= x, b -= y;
        int g = gcd(a, b);
        a /= g, b /= g;
        if(!S.count({a, b})) S.insert({a, b});
    }
    cout << S.size() << endl;
    
    return 0;
}