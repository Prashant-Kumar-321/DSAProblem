#include<iostream>
#include<vector>
using namespace std; 

class MaximumProfit
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int b1, b2, s1, s2, p1, p2;
    int maxP;

    maxP = 0, b1 = prices[0], s1 = prices[0];
    p1 = 0;

    for (int i = 1; i < n; ++i)
    {
      s1 = max(s1, prices[i]);
      if (prices[i] < b1)
      {
        s1 = b1 = prices[i];
      }
      p1 = max(p1, s1 - b1);

      // Second transcation of the stock 
      // compute max Profit of arr[i+1...n-1]
      if (i != n - 1){
        b2 = s2 = prices[i + 1];
      }
      p2 = 0;
      for (int j = i + 2; j < n; j++) {
        s2 = max(s2, prices[j]);
        if (prices[j] < b2){
          s2 = b2 = prices[j];
        }
        p2 = max(p2, s2 - b2);
      }
      maxP = max(maxP, p1 + p2);
    }

    return maxP;
  }
};

// Problem with above implementation 
// We are freshly calculating the max Profit fo second trascation 
// for every first transcation 
// we already calcualte max profit of second transcation 


// Solution 
class MaximumProfit
{
public:        
  int maxProfit(vector<int>&prices){
      int n = prices.size(); 
      // compute profit array of prices array[i....n-1]
      vector<int> profit(n); 
      computeProfitArrayOfSecondTranscation(profit, prices); 
      
      int b1, s1, p1; 
      int maxP; 
      
      maxP = 0, b1 = prices[0], s1 = prices[0];
      p1 = 0; 
      
      for(int i=1; i<n; ++i)
      {
          s1 = max(s1, prices[i]); 
          if(prices[i] < b1){
              s1 = b1 = prices[i]; 
          }
          p1 = max(p1, s1-b1); 
          
          // no second transciation
          if( i == n-1){
              maxP = max(maxP, p1); 
          }
          else { 
              maxP = max(maxP, p1+profit[i+1]); 
          }
      }    
        
      return maxP; 
  }

  void computeProfitArrayOfSecondTranscation(vector<int>& profit, const vector<int>& prices)
  {
      int n = prices.size();
      int b , s, p; 
      b = s = prices[n-1]; 
      p = 0; 
      profit[n-1] = 0; 
      
      for(int i=n-2; i>=0; i--){
          if(prices[i] < b){
              b = prices[i]; 
          }
          else if(prices[i] > s){
              b = s = prices[i]; 
          }
          
          p = max(p, s-b); 
          profit[i] = p; 
      }
  }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
};