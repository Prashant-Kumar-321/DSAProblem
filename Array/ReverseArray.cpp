#include<iostream>
#include<vector>
using namespace std; 

void reverseArray (vector<int>& arr)
{
  int i = 0, j = arr.size()-1; // index pointer 
  while (i<j){
    std::swap(arr[i++], arr[j--]); 
  }
}

void rec_reverseArray (vector<int>& arr, int front, int rear)
{
  if (front < rear) // base case 
  {
    std::swap(arr[front], arr[rear]); 
    rec_reverseArray(arr, front+1, rear-1); 
  }
}
// Time compexity O(N), space complexity O(1)

void printArray (vector<int>& arr)
{
  for(auto& element: arr){
    cout<< element<< " "; 
  }
  cout<< endl; 
}

int main (int argc, char** argv)
{
  vector<int> arr = {8, 7, 2, 1, 21, 4, 3, 5, 9, 13, 10, 7}; 
  rec_reverseArray(arr, 0, arr.size()-1); 
  // reverseArray(arr); 
  printArray(arr); 

  return 0; 
}