#include <bits/stdc++.h>
using namespace std;

class MinSwap
{
public:
    int minSwap(int arr[], int n, int k) {
        
        int outsiders = 0; 
        int myeles = 0; 
        int ans = 0; 
        
        for(int i=0; i<n; ++i){   // O(N)
            if(arr[i]<=k) myeles++; 
        }
        
        // Outsiders in first window     // O(l) 
        for(int i=0; i<myeles; ++i){
            if(arr[i] > k) outsiders++;    
        }
        ans = outsiders; 
        
        // check outsiders in every remaining window 
        for(int i=1; i+myeles<=n; ++i){                // O(N) 
            // calculate outsiders in the current window 
            if(arr[i-1] > k) outsiders--; 
            if(arr[i+myeles-1] > k) outsiders++; 
            
            ans = min(ans, outsiders); 
        }
        
        return ans;

    }
    
    // O(N) 
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
