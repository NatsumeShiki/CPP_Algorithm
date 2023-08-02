// ��°ͺղ�����������£�

// ����һ������ 4
//  ��ż�������Բ������������֮�͡�

// ���磺

// 8=3+5

// 20=3+17=7+13

// 42=5+37=11+31=13+29=19+23
// ���ڣ������������֤����С��һ�����ż���ܷ������°ͺղ��롣

// �����ʽ
// ��������������ݡ�

// ÿ������ռһ�У�����һ��ż�� n
// ��

// ������ 0
//  ������

// �����ʽ
// ����ÿ�����ݣ�������� n = a + b������ a,b
//  ����������

// ���ж������������� a,b
// ����� b?a
//  ����һ�顣

// ���޽⣬��� Goldbach's conjecture is wrong.��

// ���ݷ�Χ
// ���������� 50006
//  �����ݡ�
// 6��n<106
// ����������
// 8
// 20
// 42
// 0
// ���������
// 8 = 3 + 5
// 20 = 3 + 17
// 42 = 5 + 37

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
bool st[N];
int primes[N], cnt;

void init(){
    for(int i = 2; i <= N; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= N / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    init();    
    int x;
    while(cin >> x, x){
        for(int i = 0; i < cnt; i++){
            int a = primes[i], b = x - primes[i];
            if(!st[b]){
                printf("%d = %d + %d\n", x, a, b);
                break;
            }
        }
    }
    
    return 0;
}