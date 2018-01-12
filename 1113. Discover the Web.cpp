#include <iostream>//Runtime error
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    string s,n,p;
    vector<string>backward_stack(0);
    vector<string>forward_stack(0);

    int i,t,x=1,count_b,count_f;

    freopen("1113. Discover the Web.txt","r",stdin);

    cin>>t;

    while(t--)
    {
        if(t==-1)
        {
            break;
        }
        else
        {
            cout<<"Case "<<x<<":"<<endl;
            x++;
        }
        count_b=-1;
        count_f=0;
        forward_stack.push_back("http://www.lightoj.com/");
        //cout<<forward_stack.at(count_f);

        for(i=0;;i++)
        {
            cin>>s;

            if(s=="QUIT")
            {
                break;
            }
            else if(s=="VISIT")
            {
                cin>>n;
                backward_stack.push_back(n);
                count_b++;
                cout<<n<<endl;
                cout<<"sggbjg "<<count_b<<endl;
                cout<<backward_stack.at(0);
                cout<<backward_stack.at(1);
                //cout<<p;
            }

            else if(s=="FORWARD")
            {
                if(forward_stack.empty())
                {
                    cout<<"f___Ignored"<<endl;
                }
                else
                {

                    backward_stack.at(count_b++)=forward_stack.at(count_f);
                    cout<<forward_stack[count_f]<<endl;
                    forward_stack.pop_back();
                }
            }
            else if(s=="BACK")
            {
                if(backward_stack.empty())
                //if(count_b<0)
                {
                    cout<<"b__Ignored"<<endl;
                }
                else
                {

                    cout<<"dghrjn"<<endl;
                    //forward_stack[count_f++]=backward_stack[count_b];
                    //backward_stack.at(count_b)=forward_stack.at(count_f++);
                    n=backward_stack.at(count_b);
                    cout<<n;
                    forward_stack.push_back(n);
                    backward_stack.pop_back();
                    if(count_b-->=0)
                    {
                        cout<<backward_stack.at(count_b)<<endl;
                    }
                    else
                    {
                        cout<<"Ignored"<<endl;
                    }

                }
            }
            forward_stack.clear();
            backward_stack.clear();
        }
    }
}
