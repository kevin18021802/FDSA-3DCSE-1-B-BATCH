#include<iostream>
#include<vector>

using namespace std;

int plate(vector<string>s , string tar)
{
    for(int i =0 ; i < s.size()-1;i++)
    {
        if(s[i]==tar)
        {
            return i+1;
            break;

        }
    }
    return -1;

}
int recursive(vector<string>s ,string tar,int st =0 )
{

    if(st>=s.size()-1)
    {
        return -1;
    }
    else if(s[st]==tar)
    {
        return st+1;

    }
    else
    {
        recursive(s,tar,st+1);
    }

}

int main()
{
    vector<string>s = {"DSA201","WEB201","JAVA201","MATHS201","CRE201"};

    cout<<"\n Iterate  :- "<<plate(s,"DSA201");
    
    cout<<"\n recursive  :- "<<recursive(s,"DSA201");



}