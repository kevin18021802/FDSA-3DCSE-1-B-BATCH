#include<iostream>
#include<vector>
using namespace std;

void Bubblesort(vector<int>arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for( int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr [j + 1])
            {
                swap(arr[j],arr[j + 1]);
            }
        }
    }

    for(int k : arr)
    {
        cout<<k<<" ";
    }

    cout<<endl;
}

void Selectionsort(vector<int>arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j= i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(arr[i], arr[min]);
    }

    for(int k : arr)
    {
        cout<<k<<" ";
    }

    cout<<endl;
}

void Insertionsort(vector<int>arr, int n)
{
     for(int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j;

        for(j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }

    for(int k : arr)
    {
        cout<<k<<" ";
    }
}

int main()
{
    vector<int>a = {1,3,5,6,46,58,96,32,47,10,36,100};
    int n = a.size();

    Bubblesort(a, n);
    Selectionsort(a, n);
    Insertionsort(a, n);

}