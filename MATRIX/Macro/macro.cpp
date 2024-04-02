#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define srt(v) sort(v.begin(),v.end())
#define all(v) (v).begin(), (v).end()
#define yes() cout<<"YES"<<endl
#define no() cout<<"NO"<<endl
const ll mod = 1e9 + 7;
const ll N = 1e6;

ll gcd(ll a, ll b){if(b==0) return a; return gcd(b,a%b);}
int n,k;

int check(int mid, vector<int> &v){
    int num =0;
    int x = v[0];
    for (int i = 1; i < n; i++)
    {
        int t = (v[i]-x)/mid;
        int temp = (v[i]-x)%mid ? t: t-1;
        num+=temp;
        if(num > k) return 0;
        x = v[i];
    }
    return 1;
        
}

int32_t main()
{
ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int tt; cin >> tt;
    //tt = 1;
    while (tt--) {
        cin>>n>>k;
        vi v(n);
        for(auto &x : v) cin>>x;
        int lo = 1, hi = v[n-1] - v[0], ans = 0;
        while (lo<=hi)
        {
            int mid = lo + (hi - lo)/2;
            if(check(mid,v) == 1){
                ans=mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


// cpp Template 
#define  endl '\n'; 






