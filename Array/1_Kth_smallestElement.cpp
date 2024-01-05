#include<iostream>
#include<random>
using namespace std; 

class kthSmallestElement{
public:
  int getKthElement (int arr[], const int& n, const int& k){
    return getKthElement(arr, 0, n-1, k); 
  }

private: 
  // Return randon integer value in the provided range
  int rand(int min, int max){
    std::random_device rd; 
    std::mt19937 gen(rd()); // Seed the PRNG by random device 

    std::uniform_int_distribution randomNum(min, max);
    return randomNum(gen); 
  }

  int getPivoteEleIdx (int*const arr, int st, int end) 
  {
    int pivote = rand(st, end); // Return a random number in the range [st, end]

    int i=st; // point to index where next smaller element than pivote going to be placed 

    for (int j=st; j<=end; ++j){
      if (arr[j] < arr[pivote]) {
        std::swap(arr[i++], arr[j]); 
      }
    }

    // Placing the pivote Element at its correct position 
    std::swap(arr[pivote], arr[i]); 
    return i; 
  }

  // Note:-
  // kth smallest element will be at (k-1)th index 
  // in the sorted array (ascending order)
  // Quick Selection Algorithm 
  int getKthElement (int*const arr, int st, int end, const int& k){
    int pivoteIdx = getPivoteEleIdx(arr, st, end); 

    if (pivoteIdx == (k-1)){
      return arr[pivoteIdx]; // required element 
    }
    else if (k-1 < pivoteIdx){
      return getKthElement(arr, st, pivoteIdx-1, k); // kth minimum element is lying on the left subarray 
    }
    else { // k-1 > pivoteIdx
      return getKthElement(arr, pivoteIdx+1, end, k); // kth minimum element is lying on the rigth subarray 
    }

  }
}; 

// Driver function 
int main (int argc, char** argv)
{
  int arr[] = {7, 10, 4, 3, 20, 15}; 
  int n = sizeof(arr)/sizeof(arr[0]); 

  kthSmallestElement kthSEle; 
  std::cout<< kthSEle.getKthElement(arr, n, 1)<< std::endl; 


  return 0; 
}

/**
 * Class Diagram of KthSmallestElement
 * ------------------------------------------
 * |         KthSmallestElement             |
 * ------------------------------------------
 * |                                        |
 * |                                        |
 * ------------------------------------------
 * | + getKthElement(arr, n, k):int         |
 * | - getKthElement(arr, st, end, k): int  |
 * | - getPivoteEleIdx(arr, st, end): int   |
 * ------------------------------------------
 * 
*/

/*Note
* 1 Byte Rule:->  
* Empty Class (No data memeber/field) has 1 byte of space 
* By this compiler ensure different objects have different addresses
* and it helps in pointer comparision and other aspect of languges 
*/