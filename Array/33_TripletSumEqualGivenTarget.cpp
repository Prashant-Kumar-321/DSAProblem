#include <iostream>
#include <map>
using namespace std;

class TripletSumEqualToTarget
{
public:
  bool find3Numbers(int arr[], int n, int X)
  {
    map<int, int> mp;
    // finding the frequency of elements
    for (int i = 0; i < n; ++i)
    {
      mp[arr[i]]++;
    }

    // make every possible pair
    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j){
        if (isTripletWithTargetSumPossible(mp, arr[i], arr[j], X)){
          return true;
        }
      }
    }

    return false;
  }

  bool isTripletWithTargetSumPossible(map<int, int> &mp, int a, int b, int X)
  {
    int less = X - (a + b);
    auto it = mp.find(less);

    if (it != mp.end()){ // third exist of triplet 
      return doesThirdElementReallyExist(it, mp[it->first], a, b, X); 
    }
    else{
      return false; 
    }
  }

  bool doesThirdElementReallyExist(map<int,int>::iterator it, int freq, int a, int b, int X)
  {
    if(it->first==a && it->first == b){ // all elements of triplet are equal 
      if(freq > 2){
        return true; 
      }
    }
    else if(it->first == a || it->first == b){ // two of three elements is either a  or b 
      if(freq > 1){
        return true; 
      }
    }
    else{ // all elements are different
      return true; 
    }

    return false; 
  }

};

// Approach 1 
// Brute Force
class BF_TripletSumEqualToTarget
{
public:
  bool find3Numbers(int A[], int n, int X)
  {
    // first element of triplet
    for (int i = 0; i < n - 2; i++) {
      if (fun2(A, n, X, i, A[i]))  {  // checking do two number exist whose sum equal to X-arr[i]
        return true;
      }
    }

    return false;
  }

  // for second element of triplet
  bool fun2(int A[], int n, int X, int idx, int trip1)
  {
    for (int i = idx + 1; i < n - 1; ++i){
      if (fun3(A, n, X, i, trip1 + A[i])){   // checking does a number exist which is equal to x-(arr[i]+arr[j])
        return true;
      }
    }

    return false;
  }

  // for third element of triplet
  bool fun3(int A[], int n, int X, int idx, int trip2)
  {
    for (int i = idx + 1; i < n; ++i) {
      if (trip2 + A[i] == X){
        return true;
      }
    }
    return false;
  }
};

int main()
{
  int arr[] = {3, 2, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int X = 6;

  TripletSumEqualToTarget ob;
  cout << ob.find3Numbers(arr, n, X) << endl;

  return 0;
}