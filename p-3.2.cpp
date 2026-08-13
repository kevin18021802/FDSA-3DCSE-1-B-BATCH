#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int>arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for(int k : arr)
    {
        cout<<k<<" ";
    }
}

int main()
{
    vector<int>a = {0,0,0,1,0,2,0,1,2,1,2,0,1,2,2,2,1,1,0,1,1,2};
    int n = a.size();

    sort(a, n);
}