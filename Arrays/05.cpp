#include<iostream>
using namespace std;


void print(int *arr,int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool isSwap = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap) // array is already sorted
            return;
    }
    print(arr,n);
}

void selectionSort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIdx = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i] , arr[minIdx]);
    }
    print(arr,n);
}

void insertionSort(int *arr, int n)
{
    for(int i=1;i<n;i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while(prev >=0 && arr[prev] > curr)
        {
            swap(arr[prev],arr[prev + 1]);
            prev--;
        }
        arr[prev + 1] = curr;
    }
    print(arr,n);
}

void countSort(int *arr, int n)
{
    int freq[100000]; // range
    int minVal = INT8_MAX, maxVal = INT8_MIN;

    // 1st step creating freq array  O(n)
    for(int i=0;i<n;i++)
    {
        minVal = min(minVal,arr[i]);
        maxVal = max(maxVal,arr[i]);
        freq[arr[i]]++;
    }

    // 2nd Step modfying org array from freq Array  0(range)=max-min
    for(int i = minVal,j = 0;i<=maxVal;i++)   
    {
        while(freq[i] > 0)
        {
            arr[j++] = i;
            freq[i]--;
        }
    }

    print(arr,n);
}

int main()
{
    int arr[5] = {5,4,1,3,2};
    countSort(arr,5);
}