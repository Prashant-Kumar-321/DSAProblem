#include<iostream>
using namespace std; 

void mergeLeftElements (long long* mergedArr, long long* arr, int n, int i, int k)
{
  // from arr1 
  while (i < n){
    mergedArr[k++] = arr[i++]; 
  }
}

void copyFromMergedArr (long long* mergedArr, long long* arr, int n, int i)
{
  int j = 0; 
  while (j < n)
  {
    arr[j++] = mergedArr[i++]; 
  }
}

void merge (long long arr1[], long long arr2[], int n, int m)
{
  long long* mergedArr = new long long[n+m];
  int i, j, k; 
  i = j = k = 0; 

  // Merge by comparing elements of arr1 and arr2 
  while (i < n && j < m )
  {
    if (arr1[i] < arr2[j]){
      mergedArr[k++] = arr1[i++]; 
    }
    else {
      mergedArr[k++] = arr2[j++]; 
    }
  }

  // copy the remaining element 
  if (i< n){ // arr1 has left element 
   mergeLeftElements(mergedArr, arr1, n, i, k);  
  }
  else { // arr2 has left element 
    mergeLeftElements(mergedArr, arr2, m, j, k); 
  }

  copyFromMergedArr(mergedArr, arr1, n, 0); 
  copyFromMergedArr(mergedArr, arr2, m, n); // n -> start copying from nth index from mergedArr

  delete[] mergedArr;  
}

void printArray(long long arr[], int n)
{
  for (int i=0; i<n; ++i){
    cout<< arr[i]<< " "; 
  }
}

int main (int argc, char** argv)
{
  long long arr1[] = {14, 273, 306, 971, 1002, 1109, 1258, 1439, 1556, 1979, 2515, 2527, 2541, 2860, 2866, 3139, 4037, 4123, 4236, 4276, 4896, 5189, 6016, 7200, 7814, 8005, 8131, 8564, 8624, 9519, 9883};
  int n = sizeof(arr1)/sizeof(arr1[0]); 

  long long arr2[] = {748, 751, 1384, 1831, 1885, 2709, 3031, 3359, 3369, 3428, 3854, 4068, 4400, 4535, 4591, 4756, 5442, 5518, 5633, 5714, 5784, 5913, 5935, 5989, 6047, 6068, 6424, 6479, 6607, 6841, 8394, 8789, 8812, 8900, 9553};
  int m = sizeof(arr2)/sizeof(arr2[0]); 

  merge(arr1, arr2, n, m);

  printArray(arr1, n); 
  printArray(arr2, m); 

  return 0; 
}