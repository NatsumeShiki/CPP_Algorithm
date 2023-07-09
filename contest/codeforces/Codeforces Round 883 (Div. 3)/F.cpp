#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
 
const long long mod = 1000000007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
 
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])
 
#define pb push_back
#define mp make_pair
 
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif
    multiset<ll> can;
//    vll can;
    const ll INF = 1e18;
    forn(n,2,1000001) {
        ll dn = ll(n)*n;
        ll sum = n+1;
        while(1) {
            sum += dn;
            can.insert(sum);
            if(INF/n < dn) break;
            dn *= n;
        }
    }
    // exit(0);
    int ta;
    cin>>ta;
    forn(ifa,0,ta) {
        ll n;
        cin>>n;
        if(can.find(n) != can.end()) {
            printf("YES\n");
        }
        else {
            ll l = sqrt(n);
            while(l*l > n) l--;
            while((l+1)*(l+1) <= n) l++;
            if(l>1 && l*l+l+1 == n) printf("YES\n");
            else printf("NO\n");
        }
    }
    
    
}