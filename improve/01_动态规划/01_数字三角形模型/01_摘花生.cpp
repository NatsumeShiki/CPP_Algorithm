// Hello Kitty想摘点花生送给她喜欢的米老鼠。

// 她来到一片有网格状道路的矩形花生地(如下图)，从西北角进去，东南角出来。

// 地里每个道路的交叉点上都有种着一株花生苗，上面有若干颗花生，经过一株花生苗就能摘走该它上面所有的花生。

// Hello Kitty只能向东或向南走，不能向西或向北走。

// 问Hello Kitty最多能够摘到多少颗花生。

// 1.gif

// 输入格式
// 第一行是一个整数T，代表一共有多少组数据。

// 接下来是T组数据。

// 每组数据的第一行是两个整数，分别代表花生苗的行数R和列数 C。

// 每组数据的接下来R行数据，从北向南依次描述每行花生苗的情况。每行数据有C个整数，按从西向东的顺序描述了该行每株花生苗上的花生数目M。

// 输出格式
// 对每组输入数据，输出一行，内容为Hello Kitty能摘到得最多的花生颗数。

// 数据范围
// 1≤T≤100,
// 1≤R,C≤100,
// 0≤M≤1000
// 输入样例：
// 2
// 2 2
// 1 1
// 3 4
// 2 3
// 2 3 4
// 1 6 5
// 输出样例：
// 8
// 16

// 我自己的做法
/*
思路：
f[i][j] 表示走到i，j的时候花生颗数的最大值
因为还能往南或东走，所以f[i][j]可以是由北走过来或者西走过来，也就是用f[i-1][j]和f[i][j-1]二者的较大值加上i,j位置花生的颗数，就是f[i][j]
可以只使用一个数组，这个数组即从控制台读取i,j位置花生的颗数，也表示走到i,j时花生的最大值
然后f[r][c]就表示走到r,c时花生的最大值，输出即可
*/
#include<iostream>
using namespace std;

const int N = 110;
int f[N][N];
int n, r, c;

int main(){
    cin >> n; // n组数据
    while(n--){
        cin >> r >> c;
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++){
                cin >> f[i][j];
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + f[i][j];
            }

        cout << f[r][c] << endl;
    }
    
    return 0;
}

// 大佬的写法
/*
动态规划：
  状态表示f[i][j]:
    集合：所有从（1,1）走到（i,j）的路线
    属性：Max
  状态计算：
    最后一步是从上面走下来 f[i-1][j] + w[i][j]
    最后一步是从左边走过来 f[i][j-1] + w[i][j]
*/
#include<iostream>
using namespace std;

const int N = 110;
int n, m;
int w[N][N];
int f[N][N];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> w[i][j];
                
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];
        
        printf("%d\n", f[n][m]);
    }
    
    return 0;
}