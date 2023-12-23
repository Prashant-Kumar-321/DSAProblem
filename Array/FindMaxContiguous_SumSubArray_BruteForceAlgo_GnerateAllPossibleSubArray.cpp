#include<iostream>
#include<vector>
#define NEGATIVE_INFINITY  LLONG_MIN

using namespace std; 

long long maxSubArray (const vector<int>& arr)
{
  long long max = NEGATIVE_INFINITY; 
  long long subArraySum = 0; 

  //Generate all Possible contiguous subArray of Given array 
  for (int i=0; i<arr.size(); ++i)
  {
    subArraySum = 0; 
    for (int j=i; j<arr.size(); ++j)
    {
      subArraySum += arr[j]; // adding current element in the previous subArray 
      max = std::max(max, subArraySum); // compare sum of previous subarray's element with the sum of current subarray's element 
    }
  }

  return max;
}// o(n^2)


int main (int agrc, char** argv)
{
  vector<int> arr = {1, 2, 5, -9, 3, 4, -5, 6, 8}; 
  long long maxSum = maxSubArray(arr);
  cout<< maxSum<< endl;  

  return 0; 
}