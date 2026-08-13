#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int>v={5,7,6,4,3,2};
    int h;

    cout<<"Enter starting index number:";
    cin>>h;
    
    int n=v.size();
     h%=n;

     reverse(v.begin(),v.begin()+h);
     reverse(v.begin()+h,v.end());
     reverse(v.begin(),v.end());

     for (int i = 0; i < n; i++)
     {
        cout<<v[i]<<endl;
     }
    

}