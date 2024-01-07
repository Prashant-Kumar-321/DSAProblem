
/**
 * Merge two Sorted array without using any extra space 
 * Place first N element to arr1 and remaining element to arr2 
*/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution
{
public:
  // Merge Two Sorted arrays without Using Extra space 
  void merge(long long arr1[], long long arr2[], int n, int m)
  {
    int i = 0;
    while (i < n)
    {
      if (arr1[i] > arr2[0])
      {
        long long temp = arr1[i];
        arr1[i] = arr2[0];

        // Insert temp  into arr2

        // Find correct position for temp to be placed
        int j = 1;
        for (; arr2[j] < temp; ++j)
          ;

        // shift all element in the range [1, j) backward by one position
        int k;
        for (k = 1; k < j; ++k)
        {
          arr2[k - 1] = arr2[k];
        }

        // Place temp at k-1 postion
        arr2[k - 1] = temp;
      }
      ++i;
    }
  }
  // Time complexity O(NM)
  // N for iterating over arr1 
  // M for inserting each element of arr1 at its proper place in sorted arr2 



  // 2nd Approach 
  // Steps: 
  /*
   * Start from the end of arr1 and from begining of arr2
   * Compare elements of arr1 and arr2 at this positons and swap if necessary 
   * By Repeatedly doing so we ensure that larger elements are moved to the end of arr1 
   * and smaller elements are moved to the begining of the arr2
   * 
   * sort arr1 and arr2 using any optimized sorting algorithm sperately 
  */

 // Time complexity O(nlogn + mlogm)
 void merge(int arr1[], int arr2[], int n, int m)
 {
    int i=n-1; /*last element of arr1*/
    int j = 0; /*first element of arr2*/

    // Move all greater element from arr1 to arr2 
    // and Move all smaller element from  arr2 ot arr1
    while (i>=0 && j<m)
    {
      if (arr1[i] >= arr2[j]){
        std::swap(arr1[i], arr2[j]); 
        i--; 
        j++; 
      }else {
        break; 
        /*all element on the left side are smaller in arr1 */
        /*all elements on the right side are greater in arr2*/
      }
    }

    std::sort(arr1, arr1+n); 
    std::sort(arr2, arr2+m); 
 }

};

// Implement 
/**
 * find position of new element in sorted array using binary Serach 
 * 
 * 2. Implement in-place Merge algorithm for two sorted list  
*/


void printArray(int arr[], int n)
{
  for (int i=0; i<n; ++i)
    cout<< arr[i]<< " "; 
}

int main()
{
  int arr1[] = {14, 273, 306, 971, 1002, 1109, 1258, 1439, 1556, 1979, 2515, 2527, 2541, 2860, 2866, 3139, 4037, 4123, 4236, 4276, 4896, 5189, 6016, 7200, 7814, 8005, 8131, 8564, 8624, 9519, 9883};
  int n = sizeof(arr1)/sizeof(arr1[0]); 

  int arr2[] = {748, 751, 1384, 1831, 1885, 2709, 3031, 3359, 3369, 3428, 3854, 4068, 4400, 4535, 4591, 4756, 5442, 5518, 5633, 5714, 5784, 5913, 5935, 5989, 6047, 6068, 6424, 6479, 6607, 6841, 8394, 8789, 8812, 8900, 9553};
  int m = sizeof(arr2)/sizeof(arr2[0]); 

  Solution sol; 
  sol.merge(arr1, arr2, n, m); 

  printArray(arr1, n); 
  printArray(arr2, m); 

  return 0;
}
