#include<iostream>
using namespace std;


int diagonalSum(int mat[][3], int n)
{
    int sum = 0;
    // O(n^2)
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(i == j)
    //             sum += mat[i][j];
    //         else if(j == n-i-1)
    //             sum += mat[i][j];
    //     }
    // }


    // O(N)
    for(int i =0;i<n;i++)
    {
        sum += mat[i][i]; //primary diagonal
        if(i != n-i-1)
            sum += mat[i][n-i-1]; // secondary diagonal
    }
    return sum;
}


int main()
{
    int matrix[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    // cout<<diagonalSum(matrix,4);

    int m[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    cout<<diagonalSum(m,3);
}