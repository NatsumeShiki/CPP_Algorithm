// “飞行员兄弟”这个游戏，需要玩家顺利的打开一个拥有 16 个把手的冰箱。

// 已知每个把手可以处于以下两种状态之一：打开或关闭。

// 只有当所有把手都打开时，冰箱才会打开。

// 把手可以表示为一个 4×4 的矩阵，您可以改变任何一个位置 [i,j] 上把手的状态。

// 但是，这也会使得第 i 行和第 j 列上的所有把手的状态也随着改变。

// 请你求出打开冰箱所需的切换把手的次数最小值是多少。

// 输入格式
// 输入一共包含四行，每行包含四个把手的初始状态。

// 符号 + 表示把手处于闭合状态，而符号 - 表示把手处于打开状态。

// 至少一个手柄的初始状态是关闭的。

// 输出格式
// 第一行输出一个整数 N，表示所需的最小切换把手次数。

// 接下来 N 行描述切换顺序，每行输出两个整数，代表被切换状态的把手的行号和列号，数字之间用空格隔开。

// 注意：如果存在多种打开冰箱的方式，则按照优先级整体从上到下，同行从左到右打开。

// 数据范围
// 1≤i,j≤4
// 输入样例：
// -+--
// ----
// ----
// -+--
// 输出样例：
// 6
// 1 1
// 1 3
// 1 4
// 4 1
// 4 3
// 4 4

// 我的做法
// 思想呢就是枚举所有的方案，每个格子够有两种状态，一种有16个格子，2^16=65536，随后枚举所有方案，直到找到一种需要步数最少的方案，而且题目说要按照字典序从小
// 到达，其实从0-65535这样子就已经是按字典序从小到大了
#include<iostream>
#include<cstring>
using namespace std;

const int N = 5;
char g[N][N], backup[N][N];

void turn(int x, int y){
    for(int i = 0; i < 4; i++)
        backup[x][i] = backup[x][i] == '+' ? '-' : '+';
    for(int i = 0; i < 4; i++)
        if(i != x)
            backup[i][y] = backup[i][y] == '+' ? '-' : '+';
}

int main(){
    for(int i = 0; i < 4; i++) cin >> g[i];
    int res = 16, min = 65535; // res是记录所需要的最小步数，而min是记录最小步数的方案
    for(int op = 0; op < 65536; op++){
        memcpy(backup, g, sizeof g); // 把g拷贝到backup上，后续的操作都在backup上进行
        int cnt = 0; // cnt是记录当前这种方案所需要的步数
        for(int i = 0; i < 16; i++){ // 枚举这一种方案的所有格子
            if(op >> i & 1){ // 如果二进制的op在第i位是1，就turn
                turn(i / 4, i % 4); // 比如说要turn的格子是第7位，7/4=1,7%4=3，所以在二阶数组中就表示第2行的第四个
                cnt++; // 需要的步数自增
            }
        }
        bool flag = false; // 记录是否还有格子是处于+状态的
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(backup[i][j] == '+'){ // 如果有
                    flag = true; // 就把flag置为true，退出循环
                    break;
                }
        if(!flag){ // 只有在所有格子都是-的情况下才能进行下面操作
            if(cnt < res){ // 如果所需要的步数是小于res的，就把它设置为最优方案
                res = cnt, min = op; 
            }
            
        }
    }
    cout << res << endl; // 输出所需步数
    for(int i = 0; i < 16; i++) // 将对应步数的格子输出坐标
        if(min >> i & 1) cout << i / 4 + 1 << " " << i % 4 + 1 << endl;
    return 0;
}

// 大佬的写法，思想都是一样的，但是发现我的方法时间需要2000毫秒，而大佬写得要12000毫秒，有点自信了
#include<cstring>
#include<iostream>
#include<vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 5;
char g[N][N], backup[N][N];

int get(int x, int y){
    return x * 4 + y;
}

void turn_one(int x, int y){
    if(g[x][y] == '+') g[x][y] = '-';
    else g[x][y] = '+';
}

void turn_all(int x, int y){
    for(int i = 0; i < 4; i++){
        turn_one(x, i), turn_one(i, y);
    }
    turn_one(x, y);
}

int main(){
    for(int i = 0; i < 4; i++) cin >> g[i];
    
    vector<PII> res;
    for(int op = 0; op < 1 << 16; op++){
        vector<PII> temp;
        memcpy(backup, g, sizeof g);
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(op >> get(i, j) & 1){
                    temp.push_back({i, j});
                    turn_all(i, j);
                }
        
        bool has_closed = false;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(g[i][j] == '+')
                    has_closed = true;
            
        if(has_closed == false)
            if(res.empty() || res.size() > temp.size())
                res = temp;
                
        memcpy(g, backup, sizeof g);
    }
    
    cout << res.size() << endl;
    for(auto op : res) 
        cout << op.x + 1 << " " << op.y + 1 << endl;
    
    return 0;
}