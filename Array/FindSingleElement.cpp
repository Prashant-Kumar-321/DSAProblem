#include<iostream>
#include<vector>
using namespace std;

/* Problem Statement
    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

    You must implement a solution with a linear runtime complexity and use only constant extra space. 
*/

class FindSingleElement
{
public:
  int singleNumber(vector<int> &nums)
  {
    int ans = nums[0]; // xor of nums[0....i]

    for (int i = 1; i < nums.size(); ++i)
    {
      ans = ans ^ nums[i]; // calculate xor of current ele with xor of arr[0..(i-1)]
    }

    return ans;
  }
};