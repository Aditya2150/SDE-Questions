#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>s;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='{' || x[i]=='(' || x[i]=='[')
            s.push(x[i]);
            else
            {
                if(!s.empty())
                {
                    char a=s.top();
                    if((a=='[' && x[i]==']') || (a=='{' && x[i]=='}') || (a=='(' && x[i]==')'))
                    s.pop();
                    else
                    return false;
                }
                else
                return false;
            }
        }
        if(s.empty())
        return true;
        return false;
    }

};
int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}