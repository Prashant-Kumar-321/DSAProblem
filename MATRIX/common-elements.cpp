#include<iostream>
#include<vector> 
#include<map> 

using namespace std; 

using vi = vector<int>; 

#define pb  push_back
#define em  emplace_back
#define MP  make_pair 
#define MTP make_tuple

#define all(v) (v).begin(), (v).end() 
#define forAll(E, C) for(auto& E: C) 
#define FOR(i, a, n) for(int i=a; i<n; ++i) 


#define ROW 4
#define COL 5 


vi commonElements(int mat[ROW][COL], int n, int m)
{
	vi final; 
	map<int, int> freq; 

	// readying the freq from first row 
	for(int i=0; i<m; ++i){
		freq[mat[0][i]] = 1; 
	}

	// Iterating over the remaing rows 
	//  Incrementing the freq for every unique element of the row that is present in
	//  the freq 
	for(int i=1; i<n; ++i)	{
		for(int j=0; j<m; ++j){
			if(freq[mat[i][j]] == i){ // ways to ensure to take only one time an elemnt per row 
				freq[mat[i][j]]++; 
			}
		}
	}

	// create final answer
	for(auto& [e, f]: freq){
		if(f == n) final.pb(e); 
	} 

	return final; 
}



// Driver Function 
int main(int argc, char** agrv)
{
	int mat[ROW][COL] = {
		{1, 2, 1, 4, 8},
		{3, 7, 8, 5, 1},
		{8, 2, 7, 2, 1},
		{8, 1, 2, 7, 9},
    };

	// 2 = 0 
	// i = 2 

	auto ans = commonElements(mat, ROW, COL); 

	for(auto& v: ans){
		cout<< v<< " "; 
	}
	cout<< endl;

	FOR(i, 0, 10){
		cout<< i<< ' '; 
	}
	cout<< endl; 

	

	return 0; 
}