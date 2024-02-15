  #include<iostream>
  #include<vector>

  using std::cout; 
  using std::endl;
  using std::vector; 


class Factorial {
public:
    vector<int> factorial(int n)
    {
      vector<int> prevProduct({1}); 
      
      for(int i=2; i<=n; ++i) {
          multiply(i, prevProduct); 
      }

      // To get the correct order of digits of factorial 
      std::reverse(prevProduct.begin(), prevProduct.end()); 

      return prevProduct; 
    }
    
    void multiply(int n, vector<int>& number)
    {
        int carry = 0; 
        
        for(int i=0; i<number.size(); ++i)
        {
            int temp = number[i]*n+carry; 

            number[i] = temp%10; // unit digit 

            carry = temp/10; // remaining number 
        }
        
        while(carry){
            number.push_back(carry%10); 
            carry /= 10; 
        }
    }
};
