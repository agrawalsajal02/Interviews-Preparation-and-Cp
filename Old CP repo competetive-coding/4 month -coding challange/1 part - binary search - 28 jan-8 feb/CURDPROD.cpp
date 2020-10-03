#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll f(ll mid,ll a[],ll n,ll k){
	ll count=0;
	for(ll i=0;i<n;i++){
		count=count+mid/a[i];
		if(count>=k)break;
	}
	if(count>=k)return 1;
	else return 0;
}
int main(){
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++){
		ll n,k;cin>>n>>k;
		ll a[n];
		for(ll j=0;j<n;j++){
			cin>>a[j];
		}
		
		//binary search i am so excited
		ll l=1;ll r=10e18;
		  while(l<r-1){
		  	ll mid=l+(r-l)/2;
		  	
		  	if(f(mid,a,n,k)){
		  		r=mid;
			  }
			  else{
			  	l=mid+1;
			  }
		  	
		  } 
	    if(f(l,a,n,k)){
	    	cout<<l<<endl;
		}else{
			cout<<r<<endl;
		}	
		
		
	}
}
