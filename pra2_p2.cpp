#include<iostream>
#include<vector>

using namespace std;

int Binaryiterate(vector<int>ar,int tar)
{
    int low =0;
    int high = ar.size()-1;

    while(low<=high)
    {
        int mid = low + ( high - low )/2;

        if(ar[mid]==tar)
        {
            return mid;
        }
        else if(ar[mid]<tar)
        {
            low= mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}
int Binaryrecursive(vector<int>ar,int tar,int low,int high)
{
    

    while(low<=high)
    {
        int mid = low + ( high - low )/2;

        if(ar[mid]==tar)
        {
            return mid;
        }
        else if(ar[mid]<tar)
        {
           return Binaryrecursive(ar,tar,mid+1,high);
        }
        else
        {
           return Binaryrecursive(ar,tar,low,mid-1);
        }
    }
    return -1;
}

int main()
{
    vector<int>ar = {1,2,8,9,19,47,68,70};
    int tar = 9;

    cout<<"\nUSING ITERATOR :- "<<Binaryiterate(ar,tar);
    cout<<"\nUSING Rcursive :- "<<Binaryrecursive(ar,tar,0,ar.size());
    
}