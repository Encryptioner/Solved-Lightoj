#include <bits/stdc++.h>//Accepted
using namespace std;

#define MAX 46656
#define RNG 100032
#define sq(x) ((x)*(x))
#define mset(array,v) memset(array,v,sizeof(array))
#define Check(array,n) (array[n>>6]&(1<<((n>>1)&31)))
#define Set(array,n) (array[n>>6]|=(1<<((n>>1)&31)))

unsigned sieve[MAX/64], segment[RNG/64];
int prime_size;
vector<unsigned long long int>prime_list;

int Bitwise_Sieve()
{
     int i, j, max1;
     max1=sqrt(MAX);

     for( i = 3; i <= max1; i += 2 )
     {
         if(!Check(sieve, i))
		 {
	 		 for( j = i*i; j <= MAX; j += (i<<1) )
			 {
				 Set(sieve,j) ;
	 		 }
		 }
	 }
    prime_size=0;
    for(i=3;i<=MAX;i+=2)
    {
        if(!Check(sieve, i))
        {
            prime_list.push_back(i);
            ++prime_size;
        }
    }

    return 0;
}

int segmented_sieve(int a, int b)
{
    unsigned i, j, k;//j noreeded to be unsigned for larger value
    unsigned count = (a<=2 && 2<=b)? 1 : 0;

    if(b<2) {return 0;}
    if(b==2) {return 1;}
    if(a<3) {a = 3;}
    if(a%2==0) {a++;}

    mset(segment,0);

    for(i=0; sq(prime_list[i])<=b; i++)
    {
        j = (a+prime_list[i]-1) / prime_list[i] ;
        j = prime_list[i] * j ;

        if(j%2==0) {j += prime_list[i];}

        for(k=prime_list[i]<<1; j<=b; j+=k)
        {
            if(j!=prime_list[i])
            {
                //cout<<i<<" "<<prime_list[i]<<" "<<j<<" "<<j-a<<endl;
                Set(segment, (j-a));
                if(j<0)
                {
                    break;
                }
            }
        }
    }

    for(i=0; i<=b-a; i+=2)
    {
        if(!Check(segment,i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    Bitwise_Sieve();
    int t,a,b,c=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",++c,segmented_sieve(a,b));
    }
    return 0;
}
