// 维护一个集合，支持如下几种操作：

// I x，插入一个数 x；
// Q x，询问数 x 是否在集合中出现过；
// 现在要进行 N 次操作，对于每个询问操作输出对应的结果。

// 输入格式
// 第一行包含整数 N，表示操作数量。

// 接下来 N 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。

// 输出格式
// 对于每个询问指令 Q x，输出一个询问结果，如果 x 在集合中出现过，则输出 Yes，否则输出 No。

// 每个结果占一行。

// 数据范围
// 1≤N≤105
// −109≤x≤109
// 输入样例：
// 5
// I 1
// I 2
// I 3
// Q 2
// Q 5
// 输出样例：
// Yes
// No

// 拉链法
// #include<iostream>
// #include<cstring>
// using namespace std;

// const int N = 100003;
// int e[N], ne[N], h[N], idx; // e数组用来保存真实的值，ne数组用来保存某一个区域中，当前值的下一个元素的下标，h数组用来保存每一条链子的第一个元素下标

// void insert(int x){
//   int k = (x % N + N) % N; // 获取它所在的区域
//   e[idx] = x; // 保存值
//   ne[idx] = h[k]; // 将当前值得ne设置为第一个元素的下标
//   h[k] = idx++; // 将当前区域的第一个下标设置为idx
// }

// bool find(int x){
//   int k = (x % N + N) % N;
//   for(int i = h[k]; i != -1; i = ne[i]){
//     if(e[i] == x) return true;
//   }
//   return false;
// }

// int main(){
//   int n;
//   cin >> n;
//   memset(h, -1, sizeof h);
//   while(n--){
//     char op[2];
//     int x;
//     scanf("%s%d", op, &x);
//     if(*op == 'I') insert(x);
//     else{
//       if(find(x)) printf("Yes\n");
//       else printf("No\n");
//     }
//   }
//   return 0;
// }

// 开放寻址法
#include<iostream>
#include<cstring>
using namespace std;
// N设置为200003是因为要把空间开足够了，一般会开两三倍，这样保证它的位置一定会是足够的
const int N = 200003, null = 0x3f3f3f3f; // 用0x3f3f3f3f来表示无穷大
int h[N];

int find(int x){
  int k = (x % N + N) % N;
  // 如果是插入，第二个条件一定会一直成立，所以直到找到一个空的地方为止它都会一直往后走
  // 如果是查询，会有两种情况，一种是查找到了空，说明不存在这个数，第二种是查找到了这个数
  while(h[k] != null && h[k] != x){ 
    k++;
    if(k == N) k = 0; // 如果超出了N的范围，从0再开始遍历
  }
  return k;
}

int main(){
  int n;
  cin >> n;
  memset(h, 0x3f, sizeof h); // memset是按照字节存储的，这句话的意思是把h这个数组上的每个字节都设置为0x3f
  while(n--){
    char op[2];
    int x;
    scanf("%s%d", op, &x);
    int k = find(x); // 如果是插入，则h[k]是空的，如果是查询，h[k]可能是空，也可能是x
    if(*op == 'I') h[k] = x;
    else{
      if(h[k] != null) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}