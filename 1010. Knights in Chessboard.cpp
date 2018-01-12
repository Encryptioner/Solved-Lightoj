#include<bits/stdc++.h>//Accepted
using namespace std;

int main()
{
    freopen("1010. Knights in Chessboard.txt","r",stdin);
    int t,m,n,c=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);

        printf("Case %d: ",++c);

        if(m==1 || n==1)
        {
            printf("%d",max(m,n));
        }
        else if(m==2 || n==2)
        {
            int MAX=max(m,n);

            if((MAX&3)==0)
            {
                printf("%d",MAX);
            }
            else if((MAX&3)==1)
            {
                printf("%d",MAX+1);
            }
            else
            {
                MAX=MAX>>2;
                MAX=(MAX<<2)+4;
                printf("%d",MAX);
            }
        }
        else if((m&1)==0 || (n&1)==0)
        {
            printf("%d",(m*n)>>1);
        }
        else
        {
            printf("%d",((m*n)>>1)+1);
        }
        printf("\n");
    }
    return 0;
}
