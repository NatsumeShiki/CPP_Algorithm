// �����κ������� x
// ����Լ���ĸ������� g(x)
// ������ g(1)=1��g(6)=4
// ��

// ���ĳ�������� x
//  ���㣺���������С�� x
//  �������� i
// ������ g(x)>g(i)
// ����� x
//  Ϊ��������

// ���磬���� 1��2��4��6
//  �ȶ��Ƿ�������

// ���ڸ���һ���� N
// ������������� N
//  �����ķ�������

// �����ʽ
// һ�������� N
// ��

// �����ʽ
// һ����������ʾ������ N
//  �����������

// ���ݷ�Χ
// 1��N��2?109
// ����������
// 1000
// ���������
// 840

/*
g(i) < g(x) x�Ƿ�����
1~N�����ķ��������ĸ�Լ��������С����
1.��ͬ�����������ֻ�����9����ǰ�Ÿ���������Ѿ�������2e9
2.ÿ�������ӵĴ��������30
3.���������ӵĴ���һ���ݼ�
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 110;
int primes[N], cnt;
bool st[N];
int res, ans;
int n;

void init(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void dfs(int u, int last, int p, int s){
    if(s > res || s == res && p < ans){
        res = s;
        ans = p;
    }
    if(u == 9) return;
    
    for(int i = 1; i <= last; i++){
        if((LL)p * primes[u] > n) break;
        p *= primes[u];
        dfs(u + 1, i, p, s * (i + 1));
    }
}

int main(){
    init(100);
    cin >> n;
    
    dfs(0, 30, 1, 1);
    cout << ans << endl;
    
    return 0; 
}