#include<bits/stdc++.h>//Accepted
#define MAX 1000010
#define lld long long int
using namespace std;

int sieve[(MAX>>6)+10];
int prime_size;
vector<int>prime_list;

bool Check(int n,int pos)
{
    return (n & (1<<pos));
}
int Set(int n,int pos)
{
    return (n | (1<<pos));
}

int Bitwise_Sieve()
{
     int i, j, max1;
     max1=sqrt(MAX);

     for( i = 3; i <= max1; i += 2 )
     {
		 if( Check(sieve[i>>6],(i>>1)&31)==0)
		 {
	 		 for( j = i*i; j <= MAX; j += 2*i )
			 {
				 sieve[j>>6]=Set(sieve[j>>6],(j>>1)&31) ;
	 		 }
		 }
	 }
    prime_list.push_back(1);
    prime_list.push_back(2);
    prime_size=1;
    for(i=3;i<=MAX;i+=2)
    {
        if( Check(sieve[i>>6],(i>>1)&31)==0)
        {
            prime_list.push_back(i);
            ++prime_size;
        }
    }
    return 0;
}
int prime_factor(lld N)
{
    vector<int>factor;
    lld N1=N;
    int l=sqrt(N);

    int i,ans=1,count;
    for(i=1;prime_list[i]<=l;i++)
    {
        if(N%prime_list[i]==0)
        {
            count=0;

            while(N%prime_list[i]==0)
            {
                ++count;
                N=N/prime_list[i];
            }
            ans*=(count+1);
        }

        if(N == 1)
        {
            break;
        }
    }
    if(N!=1)
    {
        ans*=2;
    }

    if(N==N1)
    {
        return 1;
    }
    else
    {
        return ans-1;
    }
}
int main()
{
     freopen("1028. Trailing Zeroes (I).txt","r",stdin);

     Bitwise_Sieve();
     lld N;
     int T,ans,c=0;

     scanf("%d",&T);

     while(T--)
     {
         scanf("%lld",&N);
         if(N==1)
         {
             ans=0;
         }
         else
         {
             ans=prime_factor(N);
         }
         printf("Case %d: %d\n",++c,ans);
     }
     return 0;
}

/*
Best Submit :

    /*  Author: Ankit Sultana
     * * * * * * * * * * * * * * * * *
    #include <stdio.h>
    #include <cstring>
    #include <limits>
    #include <cmath>
    #include <fstream>
    #include <map>
    #include <algorithm>
    #include <iterator>
    #include <vector>
    #include <set>
    #include <cassert>
    #define LL long long
    #define PB push_back
    #define SWAP(a,b) a^=b,b^=a,a^=b
    #define MP make_pair
    #define vi vector<int>
    #define vll vector<LL>
    #define REP(i,n)    for(__typeof(n) i = 0; i < n; i++)
    #define REP1(i,n)   for(__typeof(n) i = 1; i <= n; i++)
    #define REPc(i,j,n) for(__typeof(n) i = j; i <= n; i++)
    #define FOR(i,c) for(__typeof(c.begin()) i = c.begin(); i != c.end(); i++)
    #define F first
    #define S second
    #define smax(a, b) a = max(a, b)
    #define smin(a, b) a = min(a, b)
    #define mod 1000000007ll
    #define SZ(a) int(a.size())
    #define SZll(a) (LL)(a.size())
    #define DECODE(x) int(x-'0')
    #define ENCODE(x) char(x+'0')
    #define what_is(x) cout<<#x<<" is "<<x<<'\n'
    #define pii pair<int, int>
    #define pll pair<LL, LL>
    #define pil pair<int, LL>
    #define pli pair<LL, int>

    using namespace std;

    template<typename T> T gcd(T a, T b) { return b == 0?a: gcd(b, a % b); }
    template<typename T> T LCM(T a, T b) { return a*(b/gcd(a, b)); }
    template<typename T> T expo(T b, T e, const T &m){if(e <= 1)return e == 0?1: b;\
        return (e&1) == 0?expo((b*b)%m, e>>1, m): (b*expo((b*b)%m, e>>1, m))%m;}
    template<typename T> T modinv(T a) { return expo(a, mod-2, mod); }
    template<class T, class S> std::ostream& operator<<(std::ostream &os, const std::pair<T, S> &t) {
        os<<"("<<t.first<<", "<<t.second<<")";
        return os;
    }
    template<class T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &t) {
        os<<"["; FOR(it,t) { if(it != t.begin()) os<<", "; os<<*it; } os<<"]";
        return os;
    }
    namespace variadic {
        template<typename T> T min(T v) { return v; }
        template<typename T, typename... Args> T min(T f, Args... args) {
            return std::min(f, min(args...)); }
        template<typename T> T max(T v) { return v; }
        template<typename T, typename... Args> T max(T f, Args... args) {
            return std::max(f, max(args...)); }
    }
    #define MAXN 10003

    bool is_prime[MAXN] = {false};
    vll primes;
    void sieve_eratosthenes()
    {
        REP(i,MAXN) is_prime[i] = true;
        is_prime[1] = false;
        for(int i = 2; i*i <= MAXN; i++){
            if(is_prime[i]){
                for(int j = i*i; j < MAXN; j += i){
                    is_prime[j] = false;
                }
            }
        }
        REPc(i,2,MAXN-1){
            if(is_prime[i])
                primes.PB(i);
        }
    }

    /* Miller Rabbin,
     * Complexity: O(k * log2^3(n))
     * * * * * * * * * * * *
    inline LL multiply(LL a, LL b, const LL &m)
    {
        a %= m, b %= m;
        long double res = a;res *= b;
        LL c = (LL)(res/m);
        a *= b, a -= c*m, a %= m;
        if(a < 0)
            a += m;
        return a;
    }

    inline LL power(LL a, LL b, const LL &m)
    {
        LL ans = 1;
        while(b) {
            if(b & 1) {
                ans = multiply(ans, a, m);
            }
            a = multiply(a, a, m);
            b >>= 1;
        }
        return ans;
    }

    // Returns true if p is prime
    inline bool Miller(LL p) {
        int b[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        if(p < 2)   return false;
        if(p != 2 && !(p&1))    return false;
        for(int i = 0; i < 25; i++) {
            if(p == b[i])   return true;
            else if(p % b[i] == 0)  return false;
        }
        int cnt = 0;
        LL s = p-1;
        while(!(s&1)) {
            s /= 2;
            cnt++;
        }
        LL accuracy = 2, m;
        for(int i = 0; i < accuracy; i++) {
            LL a = rand() % (p-1) + 1;
            m = p;
            LL x = power(a, s, m);
            if(x == 1 || x == p-1)  continue;
            int flag = 0;
            for(int i = 1; i < cnt; i++) {
                x = multiply(x, x, m);
                if(x == 1)  return false;
                if(x == p-1) {
                    flag = 1;
                    break;
                }
            }
            if(flag)    continue;
            return false;
        }
        return true;
    }

    LL count_divisors(LL n)
    {
        LL ans = 1;
        REP(j,SZ(primes)) {
            LL p = primes[j];
            if(p*p*p > n)   break;
            LL count = 1;
            while(n % p == 0) {
                n /= p;
                count++;
            }
            ans = ans*count;
        }
        LL sq = sqrt(double(n));
        if(Miller(n)) {
            ans = ans*2;
        }
        else if(sq*sq == n && Miller(sq)) {
            ans *= 3;
        }
        else if(n != 1) {
            ans *= 4;
        }
        return ans;
    }

    int main()
    {
        sieve_eratosthenes();
        int t;
        scanf("%d", &t);
        REP1(tc,t) {
            LL n;
            scanf("%lld", &n);
            LL res = count_divisors(n);
            printf("Case %d: %lld\n", tc, res - 1);
        }
        return 0;
    }

    Judge :

    #include <cstdio>
    #include <iostream>
    #include <cstdlib>
    #include <cmath>

    #define PrimeLIMIT 1000100
    #define MAX_TOTAL 100000

    #define i64 long long

    int prime[PrimeLIMIT / 64], pr[MAX_TOTAL], prlen;

    #define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
    #define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

    void sieve() {
        unsigned int i,j,sqrtN,i2;
        memset( prime, -1, sizeof( prime ) );
        sqrtN = ( int ) sqrt ( ( double ) PrimeLIMIT ) + 1;
        for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
            for( j = i * i, i2 = i << 1; j < PrimeLIMIT; j += i2 ) rP( j );
        pr[prlen++] = 2;
        for( i = 3; i < PrimeLIMIT; i += 2 ) if( gP( i ) ) pr[prlen++] = i;
    }

    // factors[]-contains all factors, factorCount[]-contains frequency, factorLen-length
    void findPrimeFactors( i64 n, i64 *factors, int *factorCount, int &factorLen ) {
        int i, cnt, sqrtN = ( int ) sqrt ( ( double ) n ) + 1;
        factorLen = 0;
        for( i = 0; pr[i] < sqrtN; i++ ) if( !( n % pr[i] ) ) {
            factors[factorLen] = pr[i], cnt = 0;
            while( !( n % pr[i] ) ) n /= pr[i], cnt++;
            factorCount[factorLen++] = cnt;
            sqrtN = ( int ) sqrt ( ( double ) n ) + 1;
        }
        if( n > 1 ) factors[factorLen] = n, factorCount[factorLen++] = 1;
    }

    int cases, caseno;
    i64 n;

    int main() {
        freopen( "b.in", "r", stdin );
        freopen( "b.ans", "w", stdout );

        sieve();
        scanf("%d", &cases);
        while( cases-- ) {
            scanf("%lld", &n);
            i64 factors[200];
            int factorCount[200], factorLen;
            findPrimeFactors( n, factors, factorCount, factorLen );

            i64 res = 1;
            for( int i = 0; i < factorLen; i++ ) res = res * ( factorCount[i] + 1 );
            res--;
            printf("Case %d: %lld\n", ++caseno, res);
        }
        return 0;
    }


*/
