#include<iostream>
#include<list>
#include<vector>
using namespace std; 

using listi = list<int>; 
using vi = vector<int>; 
using listiIt = list<int>::iterator; 

void print(const vi& vector){
	for(const auto& v: vector){
		cout<< v<< " "; 
	}
	cout<< '\n'; 
}

void printAllPermutation(listi list, vi perm, int ele)
{
	perm.push_back(ele); 
	
	if(list.empty()){
		print(perm); 
		return; 
	}

	int size = list.size();
	auto it = list.begin(); 
	while(size--){
		int ele = *it; 
		it = list.erase(it); 
		printAllPermutation(list, vi(), ele); 
		list.push_back(ele); 
	}



}

void printAllPermutation(listi& list){
	int size = list.size();
	auto it = list.begin(); 
	while(size--){
		int ele = *it; 
		it = list.erase(it); 
		printAllPermutation(list, vi(), ele); 
		list.push_back(ele); 
	}
}