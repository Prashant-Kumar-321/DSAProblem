#include<iostream>
#include<vector>
using namespace std; 

//Approach two pointer 
void moveAllNegativeEnd (std::vector<int>& arr)
{
  if (!arr.empty())
  {
    int i=0, j = arr.size()-1;
    do
    { 
      std:swap(arr[i], arr[j]); 

      // moving i to the element which is positive and in the front
      while(arr[i] < 0) i++; 

      // moving j to the element which is negative and in the end 
      while(arr[j] > 0) j--; 

    }while(i < j); 
  }
}

//Approach => Two Pointer (Slightly Different than previous)
void _moveAllNegativesEnd (std::vector<int>& arr)
{
  int left = 0, right = arr.size()-1; 

  while (left < right)
  {
    if (arr[left] < 0 && arr[right] < 0){ // Both are negative, increment left 
      ++left; 
    }
    else if (arr[left] > 0 && arr[right] < 0){ // left is Positive and right is negative 
      std::swap(arr[left++], arr[right--]); 
    }
    else if (arr[left] > 0 && arr[right] > 0){ // Both are positive , Decrement right 
      --right; 
    }
    else{ // arr[left] < 0 && arr[right] >0
      ++left; 
      --right; 
    }
  }
}

// Quick sort partion approach 
void moveAllNegativeEnd_quickSortPartion (vector<int>& arr)
{
  // -3, 2, 4, 0, -1, 7, 9   pivote = 0; 
  int n = arr.size(); 
  int i = 0; // index pointer (pointing to the index of next negative elment to be placed ) 
  for (int j=0; j<n; ++j)
  {
    if (arr[j] < 0)
    {
      if (i != j){
        swap(arr[i], arr[j]); 
      }
      i++; 
    }
  }

}

void printArray (const vector<int>& arr)
{
  for(const auto& ele: arr){
    cout<< ele<< " "; 
  }
  cout<< endl; 
}

int main (int argc, char** argv)
{
  vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6}; 
  printArray(arr); 
  moveAllNegativeEnd_quickSortPartion(arr); 
  printArray(arr); 

  return 0; 
}
