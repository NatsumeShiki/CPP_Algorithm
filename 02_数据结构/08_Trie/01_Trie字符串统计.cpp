// 维护一个字符串集合，支持两种操作：

// I x 向集合中插入一个字符串 x；
// Q x 询问一个字符串在集合中出现了多少次。
// 共有 N 个操作，输入的字符串总长度不超过 105，字符串仅包含小写英文字母。

// 输入格式
// 第一行包含整数 N，表示操作数。

// 接下来 N 行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。

// 输出格式
// 对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x 在集合中出现的次数。

// 每个结果占一行。

// 数据范围
// 1≤N≤2∗104
// 输入样例：
// 5
// I abc
// Q abc
// Q ab
// I ab
// Q ab
// 输出样例：
// 1
// 0
// 1

#include<iostream>
using namespace std;

const int N = 100010;
int son[N][26]; //这个数组使用了存储字符串的
int cnt[N]; // 这个数组是用来保存某个字符串出现的次数的
int idx; // 下标是0的点，既是根节点，也是空节点，每当son数组中要存储字符的时候，保存idx
char str[N];

void insert(string str){
  int p = 0;
  for(int i = 0; str[i]; i++){
    int u = str[i] - 'a'; // 将 a ~ z 映射为 0 ~ 25
    if(!son[p][u]) son[p][u] = ++idx; // 如果在第p排的第u个位置上没有存储，就把idx存储
    p = son[p][u]; // 让p继续向后走
  }
  cnt[p]++;
}

int query(string str){
  int p = 0;
  for(int i = 0; str[i]; i++){
    int u = str[i] - 'a';
    if(!son[p][u]) return 0; // 如果son[p][u]为空，说明不存在该字符串，返回0
    p = son[p][u];
  }
  return cnt[p]; // 所有的字符串都在cnt数组中存储，比如说存储了“abcdef”，没有存储“abcd”，你查找“abcd”是找不到的，每当存储一个字符串都会在末尾打个标记
                // 表示存了这么一个字符串
}

int main(){
  int n;
  cin >> n;
  while(n--){
    char op;
    cin >> op >> str;
    if(op == 'I') insert(str);
    else cout << query(str) << endl;
  }
  return 0;
}