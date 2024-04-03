#include<iostream>
#include<vector>
#include<string> 
using namespace std; 

// N S E W // freq array of directions 
int hashV(char dir)
{
	switch(dir)
	{
		case 'N': return 0; 
		case 'S': return 1; 
		case 'E': return 2; 
		case 'W': return 3; 
	}

	return -1; 
}

pair<string, int> shortestpath(string_view path)
{
	vector<int> steps(4); 

	// count number of steps taken in each direcrtions 
	for(auto dir: path){
		steps[hashV(dir)]++; 
	}

	// storing ans 
	string shPath = ""; 
	int shdist = 0; 

	// overall vertical movement
	int temp = std::abs(steps[hashV('N')] - steps[hashV('S')]); 
	if(steps[hashV('N')] > steps[hashV('S')]){ // net movement in the N directions
		shPath.append(temp, 'N'); 
		shdist += (temp * 'N'); 
	}
	else{									// net movement in the S directions 
		shPath.append(temp, 'S');  
		shdist += (temp * 'S'); 
	}

	// overall horizontal movement 
	temp = std::abs(steps[hashV('E')] - steps[hashV('W')]); 
	if(steps[hashV('E')] > steps[hashV('W')]){ // net movement is in the E direction 
		shPath.append(temp, 'E'); 
		shdist += (temp * 'E'); 
	}
	else { 										// net movement is in the W direction 
		shPath.append(temp, 'W'); 
		shdist += (temp * 'W'); 
	}


	return make_pair(shPath, shdist); 
}

/* New ideas 
	mapping technique of char to indices using hash function  
	and Net concept 
 */


// dirver code 
int main()
{
	string steps = "WNEENESENNN";
	steps = "WNEWSNEEW";  
	auto shPaths = shortestpath(steps); 

	cout<< "shaPaths = "<< shPaths.first<< '\n'; 
	cout<< "shortest distance = "<< shPaths.second<< '\n'; 

	return 0; 
}
