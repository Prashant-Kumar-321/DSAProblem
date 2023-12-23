#include<iostream>
#include<algorithm> 
using namespace std; 

int nextJump (int st, int end, int arr[])       // 10, 7, 9, 4, 1   ele
{                                                // 6  7  8  9   10  idx 
  int maxReachablePos = st+arr[st]; 
  int pos = st;

  for (int i = st+1; i<= end; ++i){
    if (arr[i]+i >= maxReachablePos){
      maxReachablePos = arr[i]+i; 
      pos = i; 
    }
  } 

  return pos; 
}

int findMinJumps (int arr[], int n)
{
  int i = 0; 

  // some special edge cases 
  if ( n <= 1){ // we are already at the end of array 
    return 0; 
  }
  else if (arr[0] == 0){ // we can not move futher i.e can't reach to the end 
    return 1; 
  }

  int jumps = 0; 

  while (i+arr[i] < n-1) // if i can not reach to the end
  {
    i = nextJump(i+1, i+arr[i], arr); 

    // All possible reachable position are zero. 
    // we can not go futher through them 
    if (arr[i] == 0){
      return -1; 
    }

    jumps += 1; 
  }

  // I am at the index where i need to make only one jump 
  return ++jumps;
}

int main (int argc, char** argv)
{ 
  int arr[] = {10, 14, 29, 21, 17, 4, 18, 20, 18, 22, 21, 14, 27, 12, 3, 28, 17, 0, 2, 18, 8, 20, 26, 16, 9, 23, 25, 20, 7, 27, 5, 7, 16, 5, 25, 11, 3, 7, 2, 17, 14, 6, 12, 14, 23, 25, 26, 5, 18, 1, 6, 10, 9, 12, 2, 25, 29, 12, 19, 4, 8, 5, 8, 30, 2, 22, 24, 30, 7, 24, 8, 15, 16, 2, 11, 20};
  int size = sizeof(arr)/sizeof(int); 
  cout<< findMinJumps(arr, size)<< endl;  

  return 0; 
}


/*Logic******************

* Set i = 0
* if n is 1, return 0 (alreay at the end)
* if arr[0] is 0, return -1 (as we can not move futher)
* 
* Loop until reaching the end 
  while i+arr[i] < n-1 ( can not reach to the end from current idx)
    -Find the index 'idx' in the range [i+1, i+arr[i]], where arr[idx]+idx is maximized 
    
    -if arr[idx] is zero (0) for all idx in the range [i+1, i+arr[i]]
     return -1, as we can not reach to the end                       arr[1, 2, 0, 0, 0, 0]
    
    -Increment the total jumps 
    
    -Set i = idx; 
*
* After the loop we are at the index where we only neede to make 
  one jump
* return jumps; 


*/