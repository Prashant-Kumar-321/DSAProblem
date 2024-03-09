/**
 * Poblem statement:  
 * Given 2 sorted arrays Ar1 and Ar2 of size N each. Merge the given arrays and find the sum of the two middle elements of the merged array.
*/

class MidSum 
{
public:
    int findMidSum(int ar1[], int ar2[], int n)
	{
        int i = 0, j = 0, x = 0;
        
        int mid = 0 , mid_1 = 0; 
        
        while( i< n && j<n && x <= n)
        {
            mid_1 = mid; 
            
            if(ar1[i] < ar2[j]){
                mid = ar1[i++]; 
            }else{
                mid = ar2[j++]; 
            }
            x++; // number of elements have been merged 
        }
        
        
        // Copying the leftover elements in the either of elment 
        while(i < n && x <= n){
            mid_1 = mid; 
            mid = ar1[i++]; 
            x++; 
        }
        
        while(j < n && x <= n){
            mid_1 = mid;
            mid = ar2[j++]; 
            x++; 
        }
        
        return mid+mid_1; 
    }
    // O(N) Tc
    // O(1) Sc 
};