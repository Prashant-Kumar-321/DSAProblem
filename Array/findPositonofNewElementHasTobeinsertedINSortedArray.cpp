#include<iostream>
using namespace std; 

int findPosition (int arr[], int st, int end, const int& ele) // n => total number of elements in array 
{
  if (st == -1) return -1; // empty array

  // Edge cases 
  if (ele >= arr[end]) return end+ 1; 
  else if(ele < arr[st]) return st-1; 
  
  while (st < end)
  {
    int mid = st + (end-st)/2; 

    if (ele >= arr[mid])
    {
      if (ele < arr[mid+1]){ // element is greater than mid but less than next 
        return mid+1; 
      }else {                // element is greater than both mid and next 
        st = mid+1; 
      }
    }
    else // ele < arr[mid]
    { 
      if (ele >= arr[mid-1]){ // element is less than mid but greater or equal than previous element 
        return mid; 
      }
      else {                  // element is less than both mid and prev 
        end = mid-1; 
      }
    }
  }

  // fake return value; 
  return -1; 
}

int main(int argc, char** argv)
{
  int arr[] = {0, 1, 2, 3, 5, 9, 12, 20}; 
  int n = sizeof(arr)/sizeof(arr[0]); 

  int ele = 10; 
  int pos = findPosition(arr,-1, -1, ele); 
  cout<< "Position of ele "<< ele<< " is : "<< pos<< endl; 

}