#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

int findMaxlLenOfSubarray(vector<int>& arr, int k){

	int ans = 0; 
	int sum = 0; 
	unordered_map<int, int> ump;

	for(int i=0; i<arr.size(); ++i){
		sum += arr[i]; 

		if(sum == k){
			ans = i+1; 
		}
		else if(ump.count(sum-k)){
			ans = max(ans, i-ump[sum-k]); 
		}
		else{
			ump[sum] = i; 
		}
	}

	return ans; 
}


// Driver function 
int main(){
	int n; 
	cin>>n; 
	int k; 
	vector<int> arr(n); 
	for(int i=0; i<n; ++i){
		cin>> arr[i]; 
	}
	cin>> k; 

	cout<< findMaxlLenOfSubarray(arr, k)<< endl; 

	return 0; 
}