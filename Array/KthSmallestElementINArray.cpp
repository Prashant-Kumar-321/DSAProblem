#include<iostream>
#include<vector>
#include<utility>
using namespace std; 

pair<int, int> getMaxMinEle (std::vector<int>& arr)
{
  int max = arr[0], min = arr[0]; // Assume 
  for (auto& currEle: arr)
  {
    max = std::max(max, currEle); 
    min = std::min(min, currEle); 
  } 

  return make_pair(min, max); 
}

int getElementCount_sm (vector<int>& arr, const int& mid)
{
  int counter = 0; 
  for (auto& ele: arr)
  {
    if (ele <= mid){
      counter++; 
    }
  }

  return counter; 
}

int getElementCount_lr (std::vector<int>& arr, const int& mid)
{
  int counter = 0; 
  for (auto& ele: arr)
  {
    if (ele > mid){
      ++counter; 
    }
  }
  return counter; 
}

int getKthSmallestElement (std::vector<int>& arr, int k)
{
  // min, max variale are defining serach space range within my ans will lie for binary search  
  auto [min, max] = getMaxMinEle(arr);  
  int mid;  

  //Binary Search 
  while (min < max)
  {
    mid = min + (max - min)/2; 
    int elementCount = getElementCount_sm(arr, mid); // no of element less than or equal to mid
    if (elementCount >= k){
      max = mid; 
    }
    else{ // elementCount < k
      min = mid+1; 
    }
  }
  return min; 
}

// int getKthLargestElement (std::vector<int>& arr, int k)
// {
//   /*
//   *kth largest element  = arr.size()-k + 1 smallest element  
//   */
//   return getKthSmallestElement(arr, (arr.size()-k+1));
// }

// finding kth smallest element 
// Quick select 
int partition (vector<int>& arr, int st, int end)
{
  int pivot = arr[end]; 
  int i = st; 
  for (int j=st; j<=end; ++j)
  {
    if (arr[j] <= pivot){
      swap(arr[i++], arr[j]); 
    }
  }

  return (i-1); // index of pivot position 
}

int getKthSmallestElement (vector<int>& arr, int st, int end, int k)
{
  int idx = partition(arr, st, end); 

  if (idx == k-1){
    return arr[idx]; //kth smallest element 
  }
  else if (k <= idx){
    return getKthSmallestElement(arr, st, idx-1, k); // left sub Array  
  }
  else { // k > idx 
    return getKthSmallestElement(arr, idx+1, end, k); // right sub array  
  }
}

int getKthSmallestElement (vector<int>& arr, int k)
{
  return getKthSmallestElement(arr, 0, arr.size()-1, k); 
}


int main (int argc, char** argv)
{
  vector<int> arr = {7, 10, 4, 20, 12};
  int k = 3; 
  int kthSmallestElement = getKthSmallestElement(arr, k);
  cout<< k<< "th smallest element = "<< kthSmallestElement<< endl;  

  return 0; 
}