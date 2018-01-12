#include<bits/stdc++.h>//Accepted
using namespace std;

#define MAX 46656//sqrt(pow(2,31))+316
#define pii pair<int, int>

int sieve[(MAX>>6)+10];//there is 32 bit in an integer which is pow(2,5) and excluding even position so MAX is divided by pow(2,6)
int prime_size,L;
vector <int> prime_list;
vector <int> divisors;
vector <pii> factors;

bool Check(int n,int pos)
{
    return (n & (1<<pos));//cheaking if the pos position has 1 or n
}
int Set(int n,int pos)
{
    return (n | (1<<pos));//set 1 to the pos
}

int Bitwise_Sieve()
{
     int i, j, max1;
     max1=sqrt(MAX);

     for( i = 3; i <= max1; i += 2 )
     {
		 if( Check(sieve[i>>6],(i>>1)&31)==0)//if( Check(sieve[i/64],(i/2)%31)==0)
		 {
	 		 for( j = i*i; j <= MAX; j += 2*i )
			 {
				 sieve[j>>6]=Set(sieve[j>>6],(j>>1)&31) ;
	 		 }
		 }
	 }
    prime_list.push_back(2);
    prime_size=0;
    for(i=3;i<=MAX;i+=2)
    {
        if( Check(sieve[i>>6],(i>>1)&31)==0)
        {
            prime_list.push_back(i);
            ++prime_size;
        }
    }
    //cout<<prime_size<<" "<<prime_list[prime_size]<<endl;
    return 0;
}

int primeFactors(int num)
{
    int expo,prime;
    for (int i = 0; prime_list[i] <= sqrt(num); i++)
    {
        expo = 0;
        prime = prime_list[i];
        while (num % prime == 0)
        {
            expo++;
            num = num / prime;
        }
        if (expo>0)
        {
            factors.push_back(make_pair(prime, expo));
        }
    }
    if ( num >= 2)
    {
        factors.push_back(make_pair(num, 1));
    }
    return 0;

}

int setDivisors(int n, int i)
{
    int j, x, k,l;
    l=factors.size();
    for (j = i; j<l; j++)
    {
        x = factors[j].first * n;
        for (k = 0; k<factors[j].second; k++)
        {
            if(x>L)
            {
                divisors.push_back(x);
            }
            setDivisors(x, j + 1);
            x *= factors[j].first;
        }
    }
    return 0;
}
int main()
{
     int num,t,p,l,c=0;
     Bitwise_Sieve();
     scanf("%d",&t);
     while(t--)
     {
        scanf("%d %d",&p,&l);
        if((p-l)<=l)
        {
            printf("Case %d: impossible\n",++c);
            continue;
        }
        num=p-l;
        L=l;
        primeFactors(num);
        setDivisors(1, 0);

        if(l==0)
        {
            divisors.push_back(1);
        }
        sort(divisors.begin(), divisors.end());
        //cout << divisors.size() << "\n";
        int s=divisors.size();
        printf("Case %d:",++c);
        for (int j = 0; j < s ; j++)
        {
            printf(" %d",divisors[j]);
        }
        printf("\n");
        divisors.clear();
        factors.clear();
     }

     return 0;
}


