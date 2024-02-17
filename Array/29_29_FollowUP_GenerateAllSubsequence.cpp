#include<iostream>
#include<string>
#include<set>
using namespace std; 

class SubSequence 
{
public: 
  SubSequence(string str): str(std::move(str)){  }
  void generateAllSubSeqs(){
    generateAllSubSeqs(0, ""); 
  }

  void show() const; 

private: 
  void generateAllSubSeqs(int idx, string subSeq); 

  
private: 
  string str;
  set<string> superSeq; 
};

void SubSequence::generateAllSubSeqs(int idx, string subSeq)
{
  if(idx == str.length()){
    superSeq.insert(subSeq); 
    return ; 
  }
  char curr = str[idx]; 

  // choose current element 
  generateAllSubSeqs(idx+1, subSeq+curr); 

  // not to choose current element 
  generateAllSubSeqs(idx+1, subSeq); 

}


void SubSequence::show() const{
  for(auto& subSeq: superSeq){
    if(subSeq == ""){
      cout<< "[Empty]"; 
    }
    cout<< subSeq<< endl; 
  }
}


// Driver function 
int main()
{
  string str = "KUMAR"; 

  SubSequence subSeq(str); 
  subSeq.generateAllSubSeqs(); 
  subSeq.show(); 

  return 0; 
}