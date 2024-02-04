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

/**
 * [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
*/

int  moveAllNegativeToFirst(int arr[], int n)
{
  // Quick sort partition taking 0 as pivot element 
  int i=0; 
  for(int j=0; j<n; ++j)
  {
    if(arr[j] < 0)
    {
      arr[i++] = shiftRight(arr, i, j); // this will make sure that order remains same as original 
    }
  }

  return i; // positive element starts form this index; 
}

void placePosNegElementAlternatively (int nums[], int n)
{
 int j =  moveAllNegativeToFirst(nums, n); 
 int i = 1; 

 while((j<n) && (i<j) )
 {
    nums[i] = shiftRight(nums, i,j); 
    i += 2; 
    j += 1;  
 }
}

/* Intution 
    Negative element will be at even index 
    Positive element will be at odd index 
 */

class Approach2
{
  public: 
    static void placePosNegEleAlternatively(int nums[], int n)
    {
      int outOfPlace = -1; 

      for(int i=0; i<n; ++i)
      {
        if(outOfPlace == -1)
        {
          if(((nums[i] < 0) && ((i&1) == 1) ) || ((nums[i]>=0) && ((i&1) == 0))) {
            outOfPlace = i; 
          }
        }
        else 
        {
          if((nums[outOfPlace] < 0) && (nums[i] >= 0)){
            rotateRight(nums, outOfPlace, i); 
            i = outOfPlace+1; 
            outOfPlace = -1; 
          }
          else if ((nums[outOfPlace] >=0) && (nums[i] < 0)){
            rotateRight(nums, outOfPlace, i); 
            i = outOfPlace+1; 
            outOfPlace = -1; 
          }
        }
      }
    }
  
  private: 
    static void rotateRight(int nums[], int st, int end)
    {
      int temp = nums[end]; 
      for(int i=end-1; i>=st; --i){
        nums[i+1] = nums[i]; 
      }
      nums[st] = temp; 
    }
}; 


/**<VisualizeQuestion>
 * 
 *   i
 * [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
 *  j
 * </VisualizeQuestion>
*/

// Driver function 
int main(int argc, char**argv)
{
  int nums[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}; 
  int n = sizeof(nums)/sizeof(nums[0]); 

//  placePosNegElementAlternatively(nums, n); 
 Approach2::placePosNegEleAlternatively(nums, n); 

  for(int i=0; i<n; ++i)
  {
    cout<< nums[i]<< "  "; 
  }

  cout<< endl<< ((6&1)== 0)<< endl; 

  return 0; 
}