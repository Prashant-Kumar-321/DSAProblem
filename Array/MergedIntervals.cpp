#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 

namespace Approach1
{
  class Solution 
  {
    bool isOverlapping (vector<int>& intervals1, vector<int>& intervals2)
    {
      // if start point of second interval lies between interval one then 
      // interval1 and interval2 are overlapping
      return (intervals2[0] >= intervals1[0] && intervals2[0] <= intervals1[1] );  
    }

    public:
    vector<vector<int>> merge (vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end()); 
        vector<vector<int>> ans; 

        vector<bool> merged (intervals.size(),false); // track which all interval has been merged

        for (int i = 0; i < intervals.size(); ++i) 
        {
            if (!merged[i]) 
            {
              for (int j = i + 1; j < intervals.size(); ++j) 
              {
                if (isOverlapping(intervals[i], intervals[j])) 
                {
                    // merged both interval
                    intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);

                    // marked jth interval as merged
                    merged[j] = true;
                }
              }
              ans.push_back(intervals[i]);
            }
        }

        return ans; 
    }
    // time complexity is o(nlogn); 
    // Space complexity is O(N); 
  };
}


namespace Approach2
{

}