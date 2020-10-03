#include<iostream>
using namespace std;
#define ll long long int
ll fastexp(ll a,ll n){
	if(n==0){
		return 1;
	}
	ll r=fastexp(a,n/2);
	if(n%2==0){
		return (r*r);
	}
	else{
		return (r*a*r);
	}
}
int main(){
	ll x;
	ll y;
	cin>>x>>y;
	cout<<fastexp(x,y);
	
}
