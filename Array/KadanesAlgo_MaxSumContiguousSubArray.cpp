#include <iostream>
#include <string>
using namespace std; 

class KadanesAlgorithm
{
public: 
  static int findMaxSumContiguousSubarr(int arr[], int n)
  { 
    // SubArray string 
    std::string ansSubarr = "0"; 
    std::string currSubarr; 

    // Intialization Part 
    int sum = 0; 
    int max = arr[0]; 

    for (int i=0; i<n; ++i)
    {
      // Step 1 
      // (Include the current element into current contiguous sub Array) 
      sum += arr[i]; 
      currSubarr += std::to_string(i); // optional

      // Step 2
      // Compare current max sum with elements sum of current contiguous sub Array 
      if( sum > max){
        max = sum ; 
        ansSubarr = currSubarr; // optional
      } 

      // Step 3 
      // if Elements sum of current contigous subArray is Negative 
      // Then Drop that sub Array and start creating new Subarray , as it can not be my ans sub Array 
      if (sum < 0){
        sum = 0; 
        currSubarr.clear(); // Optional
      }
    }

    cout<< "Sub Array = "<< ansSubarr<< endl; 
    return max; 
  }
}; 



int main (int argc, char** argv)
{
  int arr[] =  {-1,-2,-3,-4}; 
  int n = sizeof(arr) / sizeof(arr[0]); 

  cout<< KadanesAlgorithm::findMaxSumContiguousSubarr(arr, n)<< endl;  

  return 0; 
}