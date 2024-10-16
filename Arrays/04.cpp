#include<iostream>
using namespace std;

void trap(int *heights,int n)
{
    // Declaring two array to store left and right maximum
    int leftMax[20000],rightMax[20000];

    // initialising 0th index of leftmax array and last index of right max array
    leftMax[0] = heights[0];
    rightMax[n-1] = heights[n-1];
    
    // calculating left and right max
    for(int i=1;i<n;i++)
        leftMax[i] = max(leftMax[i-1],heights[i-1]);
    for(int i=n-2;i>=0;i--)
        rightMax[i] = max(rightMax[i+1],heights[i+1]);

    int waterTrapped = 0;
    for(int i=0;i<n;i++) 
    {
        // calculating water stored at each bar 
        int currWater = min(leftMax[i],rightMax[i])-heights[i];
        if(currWater > 0)
            waterTrapped += currWater;
    }
    cout<< "Water Trapped = " << waterTrapped<<endl;
}

int main()
{
    int arr[7] = {4,2,0,6,3,2,5};
    int n = sizeof(arr)/sizeof(int);
    trap(arr,n);
}