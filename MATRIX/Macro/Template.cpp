#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

#define endl '\n'
#define pb push_back 
#define eb emplace_back
#define mp make_pair 
#define mt make_tuple

#define Sort(v) sort(v.begin(), v.end()) 
#define all(v) (v).begin(), (v).end() 
#define yes() cout<< "YES"<< endl 
#define no() cout<< "NO"<< endl 


using ll = long long; 
using ii = pair<int, int>; 
using vi = vector<int>; 
using vs = vector<string>; 
 

int main()
{
	vi v; 
	v.pb(39);     // v.push_back(89); 
	v.pb(90); 
	v.eb(71); 
	v.eb(21); 
	Sort(v); 
	sort(all(v)); 

	for(auto x: v){
		cout<< x<< " "; 
	}
	cout<< endl; 

	int n = 34; 
	if( n == 89){
		yes(); 
	}else{
		no(); 
	}

	ii p; 
	p = mp(1, 3); 
	cout<< p.first<< " "<< p.second<< endl; 

	tuple<int, int> tp; 
	tp = mt(3, 4); 
	cout<< get<0>(tp)<< " "<< get<1>(tp)<< endl; 

	return 0; 
}