#include <iostream>
#include <vector>
using namespace std;

// creating subArray from front  and then
// creating subArray from back
class Approach1
{
public:
  // Function to find maximum product subarray
  long long maxProduct(vector<int> arr, int n)
  {
    long long maxProduct = arr[0];
    long long currProduct = 1; // product of elements till ith index

    for (int i = 0; i < n; ++i)
    {
      // include current element
      currProduct *= arr[i];

      maxProduct = max(maxProduct, currProduct);

      if (currProduct == 0)
      {
        // start forming new subarray
        currProduct = 1;
      }
    }

    // Iterate array in reverse order
    //  and forming subarray
    currProduct = 1;
    for (int i = n - 1; i >= 0; --i)
    {
      // include current elment
      currProduct *= arr[i];

      maxProduct = max(maxProduct, currProduct);

      if (currProduct == 0)
      {
        // restart forming a new subArrauy
        currProduct = 1;
      }
    }
    return maxProduct;
  }
};

// User function template for C++
class Approach2
{
public:
  // Function to find maximum product subarray
  long long maxProduct(vector<int> arr, int n)
  {
    // store maximum and minmum product till ith index of the array
    long long maxValue, minValue;
    maxValue = minValue = arr[0];

    long long maxProduct = arr[0];

    for (int i = 1; i < n; ++i)
    {
      // When multiplied with -ve  end
      // max becomes min
      // min becomes max
      if (arr[i] < 0){
        swap(minValue, maxValue);
      }

      maxValue = max((long long)arr[i], arr[i] * maxValue);
      minValue = min((long long)arr[i], arr[i] * minValue);

      maxProduct = max(maxProduct, maxValue);
    }
    return maxProduct;
  }
};