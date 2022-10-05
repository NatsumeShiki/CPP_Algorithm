// 给定两个正整数（不含前导 0），计算它们的差，计算结果可能为负数。

// 输入格式
// 共两行，每行包含一个整数。

// 输出格式
// 共一行，包含所求的差。

// 数据范围
// 1≤整数长度≤105
// 输入样例：
// 32
// 11
// 输出样例：
// 21

#include<iostream>
#include<vector>

using namespace std;

// 判断两个数的大小
bool cmp(vector<int> &A, vector<int> B){
  if(A.size() != B.size()){ // 如果两个vector的大小不一样，直接比较二者的size即可
    return A.size() > B.size();
  }
  for(int i = A.size() - 1; i >= 0; i--) // 如果二者的大小一样，就从高位到低位比较
    if(A[i] != B[i]) return A[i] > B[i]; // 如果比较出来有一位两个数不一样，返回二者的比较
  return true; // 到这里说明二者大小相同，用谁减谁都可以
}

vector<int> sub(vector<int> &A, vector<int> &B){
    
    int t = 0; // 用于保存是否借位
    vector<int> C; // 用于保存最终的结果
    for(int i = 0; i < A.size(); i++){
      t = A[i] - t; // 如果借位了，先让A[i]减去借的
      if(i < B.size()) t -= B[i]; // 如果i此时还没有到B的末尾，就继续减
      C.push_back((t + 10) % 10); // 如果二者相减结果小于0，需要借位，所以通过这种方式可以获取结果。如果大于0，按照这样的做法也不会有差。直接将两种可能结合
      if(t < 0) t = 1; // 如果t小于0，说明借位了，把t设置成1
      else t = 0; // 否则，说明不需要借位，设置为0
    }
    // 如果高位有0，需要除去
    while(C.size() > 1 && C.back() == 0) // 这个判断保证了必须起码有一位，因为如果两个数相同，必须输出 0
      C.pop_back();
    
    return C;
}

int main(){
    string a, b; // 用于保存从控制台读取的两个数
    vector<int> A, B; // 用来保存读取的数的倒序
    
    cin >> a >> b;
    
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0'); // 将字符转换成整型
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if(cmp(A, B)){ // 如果a > b，此时用A减去B
      auto C = sub(A, B);
      
      for(int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    }else{ // 否则，用B减去A
      auto C = sub(B, A);
      cout << "-"; // 在输出结果前需要先输出 -
      for(int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    }
    
    return 0;
}