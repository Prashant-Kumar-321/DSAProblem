#include <bits/stdc++.h>
using namespace std; 

class Solution
{   
    vector<vector<bool>> vmat;
    vector<int> ans; 
    int R, C; 
    
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
		vmat.resize(r, vector<bool>(c, false));
		R = r, C = c; 
		spiralTraverse(0, 0, mat, {0, 1}); 
		return ans; 
    }

    void spiralTraverse(int i, int j, vector<vector<int>>& mat, pair<int, int> dir){

        if(!isValid(i, j) || vmat[i][j]) return;  // base case 
        while(isValid(i, j) && !vmat[i][j]){
            ans.push_back(mat[i][j]);
            vmat[i][j] = true; 
            
            i += dir.first; 
            j += dir.second; 
        }
                
        int nSi, nSj; pair<int, int> ndir; 

		update(nSi, nSj, ndir, dir, i, j); 

        spiralTraverse(nSi, nSj, mat, ndir);
    }
    
    bool isValid(int i, int j){
        return i>=0 && i<R && j>=0 && j<C ; 
    }

	void update(int& nSi, int& nSj, pair<int, int>& ndir,pair<int,int>& dir, int i, int j){
		        // Right Word direction :org
        // Down Word direction  :next
        if(dir.first == 0 && dir.second == 1){
            ndir = {1, 0}; 
            nSi = i+1; 
            nSj = j-1; 
        }
        // Down Word Direction :org
        // left word direction :next
        else if(dir.first == 1 && dir.second == 0){
            ndir = {0, -1}; 
            nSi = i-1; 
            nSj = j-1; 
         }
        // Left word Direction  :org 
        // UP word dirction     :next
        else if(dir.first == 0 && dir.second == -1){
            ndir = {-1, 0}; 
            nSi = i-1; 
            nSj = j+1; 
        }
        // Upword direction     : org
        // right word direction : next; 
        else { // dir.first == -1 && dir.second == 
            ndir = {0, 1}; 
            nSi = i+1; 
            nSj = j+1; 
        }
	}
};


// Driver function 
int main(int argc, char** agrv){

	vector<vector<int>> mat = {
		{5, 17}, 
		{9, 80}
	}; 

	Solution sol; 
	auto ans = sol.spirallyTraverse(mat, 2, 2); 

	for(auto& v: ans){
		cout<< v<< " "; 
	}
	cout<< '\n'; 

	return 0; 
}