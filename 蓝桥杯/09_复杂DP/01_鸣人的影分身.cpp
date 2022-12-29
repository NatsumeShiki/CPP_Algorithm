// 在火影忍者的世界里，令敌人捉摸不透是非常关键的。

// 我们的主角漩涡鸣人所拥有的一个招数——多重影分身之术——就是一个很好的例子。

// 影分身是由鸣人身体的查克拉能量制造的，使用的查克拉越多，制造出的影分身越强。

// 针对不同的作战情况，鸣人可以选择制造出各种强度的影分身，有的用来佯攻，有的用来发起致命一击。

// 那么问题来了，假设鸣人的查克拉能量为 M，他影分身的个数最多为 N，那么制造影分身时有多少种不同的分配方法？

// 注意：

// 影分身可以分配0点能量。
// 分配方案不考虑顺序，例如：M=7,N=3，那么 (2,2,3) 和 (2,3,2) 被视为同一种方案。
// 输入格式
// 第一行是测试数据的数目 t。

// 以下每行均包含二个整数 M 和 N，以空格分开。

// 输出格式
// 对输入的每组数据 M 和 N，用一行输出分配的方法数。

// 数据范围
// 0≤t≤20,
// 1≤M,N≤10
// 输入样例：
// 1
// 7 3
// 输出样例：
// 8

/*
自己写的代码
就是用a数组来保存每个位置的数，每次进入下一层dfs的时候能量最小值是上一次使用的能量，直到n个人都分配了，判断总和是否等于m，如果等于方案数加1
每个人的能量后面一个人都是大等于前面的，保证了不会有重复的方案
*/
#include<iostream>
using namespace std;

const int N = 20;
int a[N]; // 保存每个人分配的能量
int m, n, res; // res保存方案数

void dfs(int u, int last){
    if(u > n){ // 直到n个人都分配了能量
        int sum = 0;
        for(int i = 1; i <= n; i++) sum += a[i]; // 计算能量总和
        if(sum == m) res++; // 如果等于m，方案数加1
        return; // 返回
    }
    
    for(int i = last; i <= m; i++){ // 第u个人使用的能量必须大等于上一个人使用的能量
        a[u] = i;
        dfs(u + 1, i);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        res = 0;
        dfs(1, 0);
        cout << res << endl;
    }
    
    return 0;
}

// 如果dfs第三个是用来保存到这里是所用的能量，就不需要保存每个人使用的能量
#include<iostream>
using namespace std;

const int N = 20;
int m, n, res;

void dfs(int u, int last, int sum){
    if(u > n){
        if(sum == m) res++;
        return;
    }
    
    for(int i = last; i <= m; i++){
        dfs(u + 1, i, sum + i);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        res = 0;
        dfs(1, 0, 0);
        cout << res << endl;
    }
    
    return 0;
}

/*
大佬的代码，使用dp
Dp  
  状态表示f[i][j]
    集合：所有总和是i，且分成j个数的和的方案
    属性：数量
  状态计算：
    分成两部分，最小值是0和最小值不是0
    如果最小值是0，那么每个方案中必然有一个数是0，所以可以表示成f[i][j - 1]，意思是有i能量不变，但是一个人能量是0
    如果最小值不是0，那么这个方案中每个数减去1，得到f[i - j][j]，就表示这一种方案
*/
#include<iostream>
using namespace std;

const int N = 11;
int f[N][N];
int m, n;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        f[0][0] = 1; // 边界条件，能量是0，有0个人，方案是1
        for(int i = 0; i <= m; i++) // 能量从0开始计算
            for(int j = 1; j <= n; j++){
                f[i][j] = f[i][j - 1];
                if(i >= j) f[i][j] += f[i - j][j];
            }
                
        cout << f[m][n] << endl;
    }
    
    return 0;
}