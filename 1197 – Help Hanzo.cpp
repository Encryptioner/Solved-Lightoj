#include<bits/stdc++.h>//Memory limit exceeded
using namespace std;

//#define MAX 214783658
int sieve[(MAX>>6)+10];
int prime_size;
vector<int>prime_list;

int counter[214783699];
bool cat[214783699];

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
    //prime_list.push_back(1);
    prime_list.push_back(2);
    prime_size=0;//last index value of prime, thinking 1 as prime
    counter[2]=1;
    cat[2]=1;

    for(i=3;i<=MAX;i+=2)
    {
        if( Check(sieve[i>>6],(i>>1)&31)==0)
        {
            //prime_list.push_back(i);
            ++prime_size;
            cat[i]=1;
        }
        counter[i]=prime_size+1;
        counter[i+1]=prime_size+1;
    }
    for(i=0;i<prime_size;i++)
    {
        cout<<prime_list[i]<<endl;
    }
    cout<<prime_size<<" "<<prime_list[prime_size]<<endl;
    return 0;
}

int main()
{
     Bitwise_Sieve();
     int t,a,b,c=0,v;
     scanf("%d",&t);
     while(t--)
     {
         v=0;
         scanf("%d %d",&a,&b);
         //cout<<counter[a]<<" "<<counter[b]<<endl;
         if(cat[a]==1 || cat[b]==1)
         {
             v+=1;
         }
        if(a==1 && cat[b]==1)
        {
            v-=1;
        }
         printf("Case %d: %d\n",++c,counter[b]-counter[a]+v);
     }
     return 0;
}
