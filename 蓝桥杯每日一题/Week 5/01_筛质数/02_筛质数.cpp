// 给定一个正整数 n
// ，请你求出 1∼n
//  中质数的个数。

// 输入格式
// 共一行，包含整数 n
// 。

// 输出格式
// 共一行，包含一个整数，表示 1∼n
//  中质数的个数。

// 数据范围
// 1≤n≤106
// 输入样例：
// 8
// 输出样例：
// 4

// 方法一
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;
int a[N];
bool st[N];

int main(){
    int cnt = 0;
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(!st[i]) cnt++;
        for(int j = 1; j * i <= n; j++) st[j * i] = true;
    }
    
    cout << cnt << endl;
    
    
    return 0;
}


// 方法二
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;
int a[N];
int cnt;
int res[N];
bool st[N];
int n;

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(!st[i]) res[cnt++] = i, st[i] = true;
        for(int j = i + i; j <= n; j += i) st[j] = true;
    }
    cout << cnt << endl;
    
    return 0;
}

// 方法三
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;
int a[N];
int cnt;
int res[N];
bool st[N];
int n;

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(!st[i]) {
            res[cnt++] = i, st[i] = true;
            for(int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
    cout << cnt << endl;
    
    return 0;
}

// 方法4
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;
int a[N];
int cnt;
int res[N];
bool st[N];
int n;

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(!st[i]) res[cnt++] = i, st[i] = true;
        for(int j = 0; res[j] <= n / i; j++){
            st[res[j] * i] = true;
            if(i % res[j] == 0) break;
        }
    }
    cout << cnt << endl;
    
    return 0;
}