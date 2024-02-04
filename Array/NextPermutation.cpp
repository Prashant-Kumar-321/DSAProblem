#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        // single element array is itself next lexicographically greater element 
        if (nums.size()==1) {
          return; 
        }

        int i = nums.size()-2;  // second to last element 

        // find the range of elements from back that could be increased 
        while (i>=0 && nums[i] >= nums[i+1]){
          --i; 
        }

        // Given input nums is not sorted in descending order 
        if (i != -1) 
        {
          // finding just greater element than ith element 
          int j = i+1; 
          while (j < nums.size() && nums[j] > nums[i]) {
            ++j; 
          }
          j-=1; // index of just greater elment 

          std::swap(nums[i], nums[j]); 
        }

        std::reverse(nums.begin()+i+1, nums.end()); 
    }
};



// Driver function 
int main ()
{
  vector<int> nums = {1,5,1}; 
  Solution sol; 
  sol.nextPermutation(nums); 

  for(auto& ele: nums){
    cout<< ele<< " "; 
  }

  return 0;   
}