#include<iostream>
#include<vector>
using namespace std; 

class Solution {
  /*
   Intution:
   Positive element => index is even 
   Negative element => index is odd 

  */

public:
    vector<int> rearrangeArray(vector<int>& nums) {

      vector<int> posNums(nums.size()/2), negNums(nums.size()/2); 

      int pI = 0, nI = 0; 

      for(int ele: nums)
      {
        if(ele < 0){
          negNums[nI++] = ele; 
        }
        else {
          posNums[pI++] = ele; 
        }
      }

      pI = 0, nI = 0; 

      for(int i=0; i<nums.size(); ++i)
      {
        if( (i&1) == 0) { // even 
          nums[i] = posNums[pI++]; 
        }
        else {
          nums[i] = negNums[nI++];  
        }
      }

      return nums; 
    }
      // Time Complexity is O(N)
      // Auxilary Space O(N) 
};