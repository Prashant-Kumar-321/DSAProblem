#include<iostream>
using namespace std; 

// counting number of digits for 32-bit integer 
int countDigit(int num){
		if(num < 0) return countDigit(-num); 

        return  (num < 10 ? 1:
                (num < 100? 2: 
                (num < 1000? 3: 
                (num < 10000? 4: 
                (num < 100000? 5: 
                (num < 1000000? 6:
				(num < 10000000? 7: 
				(num < 100000000? 8: 
				(num < 1000000000? 9: 10))))))))); 
    }

int countDigit(long long num){
		if(num < 0) num *= -1; 

		return (num < 10 ? 1: 
			   (num < 100 ? 2: 
			   (num < 1000? 3: 
			   (num < 10000? 4: 
			   (num < 100000? 5: 
			   (num < 1000000? 6: 
			   (num < 10000000? 7: 
			   (num < 100000000? 8: 
			   (num < 1000000000? 9: 
			   (num < 10000000000? 10:
			   (num < 100000000000? 11: 
			   (num < 1000000000000? 12: 
			   (num < 10000000000000? 13: 
			   (num < 100000000000000? 14: 
			   (num < 1000000000000000? 15: 
			   (num < 10000000000000000? 16: 
			   (num < 100000000000000000? 17: 
			   (num < 1000000000000000000? 18: 19 )))))))))))))))))); 
	}

int main(){
	
	cout<< "number of digits = "<< countDigit((long long)84)<< endl; 
	 

	return 0; 
}