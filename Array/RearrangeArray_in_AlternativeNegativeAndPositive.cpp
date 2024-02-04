#include<iostream>
using namespace std; 

int shiftRight(int arr[], int st, int end)
{
  int endE = arr[end]; 
  for(int i=end-1; i>=st; --i)
  {
    arr[i+1] = arr[i]; 
  }

  return endE; 
}

int  moveAllNegativeToFirst(int arr[], int n)
{
  // Quick sort partition taking 0 as pivot element 
  int i=0; 
  for(int j=0; j<n; ++j)
  {
    if(arr[j] < 0)
    {
      arr[i] = shiftRight(arr, i, j);
    }
  }

  return i; // positive element starts form this index; 


}