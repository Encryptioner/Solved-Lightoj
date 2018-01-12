#include <stdio.h>//Accepted

int main()
{
    freopen("1225. Palindromic Numbers (II).txt","r",stdin);
    int i,j,l,t,c=0;

    char s[11];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",&s);

        l=strlen(s);

        int x=1;

        printf("Case %d: ",++c);

        for(i=0, j=l-1 ; i<=j ; i++, j--)
        {
            if(s[i]==s[j])
            {
                continue;
            }
            else
            {
                x=0;
                printf("No\n");
                break;
            }
        }
        if(x==1)
        {
            printf("Yes\n");
        }
    }
    return 0;
}

