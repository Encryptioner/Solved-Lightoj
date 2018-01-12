#include <bits/stdc++.h>//Accepted

using namespace std;

int main()
{
    unsigned int i,t,x=0;

    freopen("1113. Discover the Web.txt","r",stdin);

    cin>>t;

    while(t--)
    {
        cout<<"Case "<<++x<<":"<<endl;

        stack<string>backward_stack;
        stack<string>forward_stack;

        string s,p;

        backward_stack.push("http://www.lightoj.com/");

        while(cin>>s)
        {
            if(s=="QUIT")
            {
                break;
            }
            else if(s=="VISIT")
            {
                cin>>s;
                backward_stack.push(s);
                cout<<backward_stack.top()<<endl;
                p=backward_stack.top();
                while(!forward_stack.empty())
                {
                    forward_stack.pop();
                }
            }
            else if(s=="FORWARD")
            {
                if(forward_stack.empty())
                {
                    cout<<"Ignored"<<endl;
                }
                else
                {
                    backward_stack.push(forward_stack.top());
                    p=forward_stack.top();

                    cout<<forward_stack.top()<<endl;
                    forward_stack.pop();
                }
            }
            else if(s=="BACK")
            {
                forward_stack.push(backward_stack.top());
                backward_stack.pop();

                if(backward_stack.empty())
                {
                    cout<<"Ignored"<<endl;
                    backward_stack.push(forward_stack.top());
                    forward_stack.pop();
                }
                else
                {
                    cout<<backward_stack.top()<<endl;
                    p=backward_stack.top();
                }
            }
        }
    }
    return 0;
}

