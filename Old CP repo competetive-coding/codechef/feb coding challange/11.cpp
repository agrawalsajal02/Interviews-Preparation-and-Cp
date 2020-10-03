/*          don't look at my code
            make your own code

            by: SAJAL AGRAWAL
                                    ----XBAR

*/
//USE EMPLACE_BACK IN PLACE OF PUSH_BACK
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll lcm(ll x,ll y){
	  ll a = x;
  ll b = y;
 
  while (b != 0) {
    ll t = b;
    b = a % b;
    a = t;
  }
 
  ll gcd = a;
  ll lcm = (x*y)/gcd;
  return lcm;
}
int main(){
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++){
ll n;
cin>>n;
ll a,b,k;
cin>>a>>b>>k;
ll a1=n/a;
ll b1=n/b;
ll c1=lcm(a,b);
c1=n/c1;
ll ans1=a1-c1;

ll ans2=b1-c1;
if(ans1+ans2>=k){
	cout<<"Win"<<endl;
}
else{
	cout<<"Lose"<<endl;
}



	}

}






