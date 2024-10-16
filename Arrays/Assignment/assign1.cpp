#include<iostream>
using namespace std;

// CONTAIN DUPLICATES
bool findDup(int *arr,int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            if(arr[i] == arr[j])
                return true;
    }
    return false;
}

int main()
{
    int arr[10] = {1,1,1,3,3,4,3,2,4,2};
    cout<<findDup(arr,10);
}



// Search in Rotated Sorted Array

int search(int *arr,int n,int target)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        // target found
        if(arr[mid] == target)
            return mid;
    
        // left half is sorted
        if(arr[low] <= arr[mid])
        {
            // target is in this sorted half
            if(arr[low] <= target && target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;    
        }
        else
        {
            // right half is sorted
            if(arr[mid] <= target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;    
        }
    }
    return -1;
}