// �������� N
// ���� 1��x,y��N
//  �� GCD(x,y)
//  Ϊ���������� (x,y)
//  �ж��ٶԡ�

// GCD(x,y)
//  ���� x��y
//  �����Լ����

// �����ʽ
// ����һ������ N
// ��

// �����ʽ
// ���һ����������ʾ��������������������

// ���ݷ�Χ
// 1��N��107
// ����������
// 4
// ���������
// 4

/*
���ݷ�Χ��1e7��Ҫ��gcd(x, y)������
��ô һ��ѭ��ö������p������ѭ��ö��x��1��n������ѭ��ö��y��1��n�����gcd(x, y)����p�������������
���͵��� һάѭ��ö��p����άѭ��ö��x��1��n/p����άѭ��ö��y��1��n/p�����gcd(x, y)����1�����������
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e7 + 10;
int primes[N], cnt;
bool st[N];
int n;
LL s[N], phi[N];

void init(int n){
    // phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0){
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1); 
        }
    }
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + phi[i];
}

int main(){
    cin >> n;
    init(n);
    LL res = 0;
    for(int i = 0; i < cnt; i++){
        int p = primes[i];
        res += (LL)s[n / p] * 2 + 1;
    }
    cout << res << endl;
    
    return 0;
}