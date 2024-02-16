#include <iostream>
#include <algorithm>
using namespace std;

class LongestConsecutiveSubsequence
{
public:
  // Function to return length of longest subsequence of consecutive integers.
  int findLongestConsecutiveSubseq(int arr[], int N)
  {
    sort(arr, arr + N);

    int longestLen = 0;
    int currLen = 1;

    for (int i = 0; i < N - 1; ++i)
    {
      // next element is one more than currenet element
      if (arr[i] + 1 == arr[i + 1])
      {
        currLen++;
      }
      else if (arr[i] == arr[i + 1])
      { // element are equal move to next element
        continue;
      }
       // one consecutive sequence ends
      else
      {
        longestLen = max(longestLen, currLen);
        currLen = 1;
      }
    }
    longestLen = max(longestLen, currLen);
    return longestLen;
  }
};