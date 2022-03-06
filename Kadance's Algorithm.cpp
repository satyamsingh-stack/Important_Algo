/*Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
                      Example 1:
                      Input:
                      N = 5
                      Arr[] = {1,2,3,-2,5}
                      Output:
                      9
                      Explanation:
                      Max subarray sum is 9
                      of elements (1, 2, 3, -2, 5) which 
                      is a contiguous subarray.

                      Example 2:
                      Input:
                      N = 4
                      Arr[] = {-1,-2,-3,-4}
                      Output:
                      -1
                      Explanation:
                      Max subarray sum is -1 
                      of element (-1)
                      Expected Time Complexity: O(N)
                      Expected Auxiliary Space: O(1)*/
                      
#include<bits/stdc++.h>
using namespace std;
long long kadane(int n,int *arr){
	long max_sum=INT_MIN;
	long cur_sum=0;
	for(int i=0;i<n;i++){
		cur_sum=cur_sum+arr[i];
		if(cur_sum>max_sum)
			max_sum=cur_sum;
		if(cur_sum<0)
			cur_sum=0;
	}
	return cur_sum;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<kadane(n,arr);
	return 0;
}
