#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std; 

class Factorial 
{

public: 
  string calcualteFactorial(int n); 

  string sum(string num1, string num2); 
  string getLeadingZeroes(int cnt); 

}; 

string Factorial::calcualteFactorial(int n)  
{
  string result = "1", prevSum = "1";   

  for(int i=1; i<n; ++i){    
    
    for(int j=1; j<=i; ++j){  
      result = sum(result, prevSum);     
    }

    prevSum = result;  
  }

  return result; 
}

string Factorial::getLeadingZeroes(int cnt)
{
  string leadingZeroes(""); 
  while(cnt--)
  {
    leadingZeroes.push_back('0'); 
  }

  return leadingZeroes; 
}

string Factorial::sum(string num1, string num2) // "5321", "273"
{
  // making size of num1 and num2 equal 
  int lenDiff = std::abs((int)(num1.length()-num2.length())); 
  string leadingZeores = getLeadingZeroes(lenDiff);

  if(num1.length() > num2.length()){
    num2 = leadingZeores+num2; 
  } 
  else{
    num1 = leadingZeores+num1; 
  }

  // "5321", "0273"

  // create stack and intialize 
  stack<int> opr1, opr2, sumAns; 

  for( int i=0; i<num1.length(); ++i){
    opr1.push(num1[i]-48); 
    opr2.push(num2[i]-48); 
  }

 
  
  // perform calcualtion 
  int carry = 0, temp; 
  while(!opr1.empty())
  {
      temp = opr1.top()+opr2.top()+carry; 
      carry = temp/10; 
      sumAns.push(temp%10); 
      opr1.pop(); 
      opr2.pop(); 
  } 
  if(carry){
    sumAns.push(carry); 
  }

  // preparing ans from sumAns Stack
  string result(sumAns.size(), '0');  
  int idx = 0; 
  while(!sumAns.empty())             
  {
    result[idx++] = sumAns.top()+48;  // convert to respective char
    sumAns.pop(); 
  }

  return result; 
}


int main()
{ 
  int num = 10; 


  Factorial obj; 
  
  cout<< obj.calcualteFactorial(num)<< endl; 

  return 0; 
}