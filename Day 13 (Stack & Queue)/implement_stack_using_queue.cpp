#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();
        int Q;
        cin>>Q;
        while(Q--)
        {
            int QueryType=0;
            cin>>QueryType;
            if(QueryType==1)
            {
                int a;
                cin>>a;
                qs->push(a);
            }
            else if(QueryType==2)
                cout<<qs->pop()<<" ";
        }
        cout<<endl;
    }
}

// Using 2 Queues
void QueueStack :: push(int x)
{
    q2.push(x);
    while(!q1.empty())
    {
        int x=q1.front();
        q1.pop();
        q2.push(x);
    }
    while(!q2.empty())
    {
        int x=q2.front();
        q2.pop();
        q1.push(x);
    }
}

//  Using 1 Queue
void QueueStack :: push(int x)
{
    int n=q1.size();
    q1.push(x);
    for(int i=0;i<n;i++)
    {
        q1.push(q1.front());
        q1.pop();
    }
}


int QueueStack :: pop()
{
    if(q1.empty())
    return -1;
    int x=q1.front();
    q1.pop();
    return x;
}
