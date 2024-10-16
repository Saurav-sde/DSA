// Max SUbarray sum 
#include<iostream>
using namespace std;

void maxSubArraySum1(int *arr,int n)
{
    int maxSum = INT8_MIN;
    for(int start=0;start<n;start++)
    {
        for(int end = start;end<n;end++)
        {
            int currSum = 0;
            for(int i=start;i<=end;i++)
                currSum += arr[i];
            maxSum = max(maxSum,currSum);  
        }
    }
    cout<<maxSum;
}

// better approach
void maxSubArraySum2(int *arr,int n)
{
    int maxSum = INT8_MIN;
    for(int start=0;start<n;start++)
    {
        int currSum = 0;
        for(int end = start;end<n;end++)
        {
            currSum += arr[end];
            maxSum = max(maxSum,currSum);  
        }
    }
    cout<<maxSum;
}

//KADANE'S ALGORITHM
void maxSubArraySum3(int *arr,int n)
{
    int maxSum = INT8_MIN;
    int currSum = 0;
    for(int i=0;i<n;i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum,currSum);
        if(currSum < 0)
            currSum = 0;
    }
    cout<<"Max SubArray Sum is "<<maxSum;
}

//Driver  Code
int main()
{
    int arr[6] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);
    maxSubArraySum3(arr,n);
    return 0;

}
