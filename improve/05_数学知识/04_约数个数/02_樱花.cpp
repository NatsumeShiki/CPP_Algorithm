// ����һ������ n
// �����ж������������� (x,y)
//  ���� 1x+1y=1n!
// ��

// �����ʽ
// һ������ n
// ��

// �����ʽ
// һ����������ʾ��������������������

// �𰸶� 109+7
//  ȡģ��

// ���ݷ�Χ
// 1��n��106
// ����������
// 2
// ���������
// 3
// ��������
// ������������ (x,y)
//  �����������ֱ��� (3,6),(4,4),(6,3)
// ��

/*
1/x + 1/y = 1/n!
(x + y) / xy = 1/n!
x*n! + y*n! = xy
x*n! = (x - n!)*y
y = x*n! / (x - n!) = (x - n! + n!) * n! / (x - n!) = (x - n!)*n! / (x - n!) + n!^2 / (x - n!) = n! + n!^2 / (x - n!)
�����������˼������ n! ^ 2 ��Լ������
n! = p1 ^ c1 + p2 ^ c2 + ... + pn ^ cn
���n!��Լ������Ϊ (c1 + 1) * (c2 + 1) * ... * (cn + 1)
n! ^ 2 = p1 ^ 2c1 + p2 ^ 2c2 + ... + pn ^ 2cn
���n! ^ 2��Լ������Ϊ (2c1 + 1) * (2c2 + 1) * ... * (2cn + 1)
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;
int primes[N], cnt;
bool st[N];
int n;

void init(){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    cin >> n;
    init();
    
    int res = 1;
    for(int i = 0; i < cnt; i++){
        int p = primes[i];
        int s = 0;
        for(int j = n; j; j /= p) s += j / p;
        res = (res * (2ll * s + 1)) % mod;
    }
    cout << res << endl;
    
    return 0;
}