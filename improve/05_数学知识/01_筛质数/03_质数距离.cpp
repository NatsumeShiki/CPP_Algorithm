// ������������ L
//  �� U
// ������Ҫ�ڱ����� [L,U]
//  ���ҵ�������ӽ��������������� C1
//  �� C2
// ���� C2?C1
//  ����С�ģ������������ͬ������������������ԣ��������һ�ԡ�

// ͬʱ���㻹��Ҫ�ҵ�������Զ�������������� D1
//  �� D2
// ���� D1?D2
//  �����ģ������������ͬ������������������ԣ��������һ�ԡ�

// �����ʽ
// ÿ�������������� L
//  �� U
// ������ L
//  �� U
//  �Ĳ�ֵ���ᳬ�� 106
// ��

// �����ʽ
// ����ÿ�� L
//  �� U
// �����һ����������ռһ�С�

// �������������������������Ժ;�����Զ�����������ԡ��������ʽ����������

// ��� L
//  �� U
//  ֮�䲻���������ԣ������ There are no adjacent primes.��

// ���ݷ�Χ
// 1��L<U��231?1
// ����������
// 2 17
// 14 17
// ���������
// 2,3 are closest, 7,11 are most distant.
// There are no adjacent primes.

/*
�����Ҫʹ��һ�����ʣ�x�Ǻ�������ô����p <= 50000��ʹ��x���Ա�p������������ҪpС��x
1.�ҳ�1~50000�е�����������
2.����1~50000�е�ÿ������p����[L, R]������p�ı���ɸ��������������
��Ȼl��r�ܴ󣬵���ƫ��������ɸ��ʱ��Ҫ��(l / p)����ȡ���ڳ���p��ʼɸ������ת����(l + p - 1) / p * p�����Ҫ������2p֮��ȡ���ֵ����ð������ɸ����
�ڰ���ɸ����Ҳ�Ǵ�������ʼ��
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];

void init(int n){
    memset(st, 0, sizeof st);
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    int l, r;
    init(50000);
    while(cin >> l >> r){
        memset(st, 0, sizeof st);
        for(int i = 0; i < cnt; i++){
            LL p = primes[i];
            for(LL j = max(p * 2, (l + p - 1) / p * p); j <= r; j += p){
                st[j - l] = true;
                // cout << j - l << " ";
            }
            // cout << endl;
        }
        vector<int> alls;
        for(int i = 0; i <= r - l; i++){
            if(!st[i] && i + l != 1)
                alls.push_back(i + l);
        }
                
        if(alls.size() == 1) puts("There are no adjacent primes.");
        else{
            int a = 1, b = 1;
            for(int i = 1; i < (int)alls.size(); i++){
                int len = alls[i] - alls[i - 1];
                if(len < alls[a] - alls[a - 1]) a = i;
                if(len > alls[b] - alls[b - 1]) b = i;
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", alls[a - 1], alls[a], alls[b - 1], alls[b]);
        }
    }
    
    return 0;
}