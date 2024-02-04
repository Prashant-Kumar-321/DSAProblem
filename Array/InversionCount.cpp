#include<iostream>
#include<map>
#include<utility>
using namespace std; 

int main (int argc, char** agrv)
{
  using namespace std; 
  multimap<int, int> map; 
  map.insert({2, 0}); 
  map.insert({2, 5}); 
  map.insert({2, 3}); 
  map.insert({2, 7}); 
  map.insert({1, 7}); 

  map.erase(map.find(2)); 
  cout<< (*map.find(2)).second<< endl; 

  for(auto& ele: map){
    cout<< ele.first<< ele.second<< endl; 
  }



  return 0; 
}

