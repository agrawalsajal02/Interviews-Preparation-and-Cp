#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll mid,ll a[],ll n,ll k){

if(mid==0){
	return 1;
}
	ll count=0;
	for(ll i=0;i<n;i++){
		if(a[i]>=mid){
			ll g=a[i]/mid;
			count=count+g*mid;
				if(count>=k*mid){
				break;
			}
		}
		else{
			continue;
		}
		
		
		
	}
	if(count>=k*mid){
		return 1;
	}
	else{
		return 0;
	}
	
	
	
}
int main(){
ll t;
cin>>t;
for(ll i=0;i<t;i++){
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(ll j=0;j<n;j++){
		cin>>a[j];
	}
	sort(a,a+n);
	ll l=0;ll r=a[n-1];
	
	while(l<r-1){
		ll mid=l+(r-l)/2;
		
		if(f(mid,a,n,k)){
			l=mid;
		}
		else{
			r=mid-1;
		}
		
		
		
	}
	
	if(f(r,a,n,k)){
		cout<<r<<endl;
	}else{
		cout<<l<<endl;
	}
	
}



}
