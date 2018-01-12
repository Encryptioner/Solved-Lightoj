#include<bits/stdc++.h>//Accepted
using namespace std;

int main()
{
    int t,cas=0,i,j,temp,siz;
    string s1,s2;
    int c1[26],c2[26];
    bool secret;

    scanf("%d",&t);
    getchar();

    while(t--)
    {
        memset(c1,0,26*sizeof(int));
        memset(c2,0,26*sizeof(int));
        secret=true;

        getline(cin,s1);
        getline(cin,s2);

        siz=s1.length();
        for(i=0;i<siz;i++)
        {
            temp=s1[i];
            if(temp==' ')
            {
                continue;
            }
            if(temp>=65 && temp<=90)
            {
                c1[temp-65]+=1;
            }
            if(temp>=97 && temp<=122)
            {
                c1[temp-97]+=1;
            }
        }

        siz=s2.length();
        for(i=0;i<siz;i++)
        {
            temp=s2[i];
            if(temp==' ')
            {
                continue;
            }
            if(temp>=65 && temp<=90)
            {
                c2[temp-65]+=1;
            }
            if(temp>=97 && temp<=122)
            {
                c2[temp-97]+=1;
            }
        }
        printf("Case %d: ",++cas);
        for(i=0;i<26;i++)
        {
            if(c1[i]!=c2[i])
            {
                secret=false;
                printf("No\n");
                break;
            }
        }
        if(secret)
        {
            printf("Yes\n");
        }
    }
    return 0;
}
