#include<iostream>
#include<vector> 

using namespace std; 
vector<vector<int>> permutations;

void printAllPer(vector<int> arr, vector<int> per)
{
	if(arr.size() == 0){
		permutations.push_back(per); 
		return; 
	}

	for(int i=0; i<arr.size(); ++i){
		per.push_back(arr[i]); 

		vector<int> temp; 
		for(int j=0; j<arr.size(); ++j){
			if( j != i){
				temp.push_back(arr[j]); 
			}
		}

		printAllPer(temp, per); 

		per.pop_back(); 
	}
}


int main(){
	vector<int> arr = {5, 2, 3}; 
	printAllPer(arr, vector<int>()); 


	for(int i=0; i<permutations.size(); ++i){
		cout<< "[ "; 
		for(int j=0; j<permutations[i].size(); ++j){
			cout<< permutations[i][j]<< " "; 
		}
		cout<< "]"; 

		cout<< endl; 
	}

	return 0; 
}

