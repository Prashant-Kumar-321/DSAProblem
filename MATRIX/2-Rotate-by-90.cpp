#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std; 

//*************************************************

#define pb push_back 
#define eb emplace_back 
#define endl '\n'

#define Sort(v) sort(v.begin(), v.end()) 
#define forAll(A, C) for(auto& A: C) 
#define c_forAll(A, C) for(const auto& A: C) 
#define all(v) (v).begin(), (v).end() 

using ii = pair<int, int>; 
using vi = vector<int>; 
using vvi = vector<vi>; 

//************************************************

class RotateMatrix90
{

public: 
	void rotateMat90(vvi& mat, int N)
	{
		vvi rMat(N, vi(N)); 

		int j = N-1; 

		c_forAll(row, mat){
			int r = 0; 
			c_forAll(v, row){
				rMat[r++][j] = v; 
			}
			j--; 
		}
		mat = std::move(rMat); 
	}

	// O(N^2) TC where N is Dimension of matrix 	
	// O(N^2) SC wher N is Dimenstion of Matrix 

}; 



int main()
{
	int N; 
	cin>> N; 

	vvi mat(N, vi(N)); 

	forAll(row, mat){
		forAll(v, row) cin>> v; 
	}


	c_forAll(row, mat){
		c_forAll(v, row){
			cout<< v<< " "; 
		}
		cout<< endl; 
	}
	cout<< endl<< endl; 

	RotateMatrix90 rm; 
	rm.rotateMat90(mat, N); 

	c_forAll(row, mat){
		c_forAll(v, row){
			cout<< v<< " "; 
		}
		cout<< endl; 
	}

	return 0; 
}




