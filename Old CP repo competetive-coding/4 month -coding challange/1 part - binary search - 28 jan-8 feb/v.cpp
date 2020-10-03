#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll mid,ll a[],ll n,ll k){
	ll count=0;
	for(ll i=0;i<n;i++){
		if(a[i]>=mid){
			ll g=a[i]/mid;
			count=count+g;
			count++;
			if(count==k){
				break;
			}
		}
		else{
			continue;
		}
		
		
		
	}
	if(count==k){
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
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll l=0;r=a[n-1];
	ll b[n];
	
	while(l<r-1){
		for(ll g=0;g<n;g++){
			b[g]=a[g];
		}
		ll mid=l+(r-l)/2;
		
		if(f(mid,b,n,k)){
			l=mid;
		}
		else{
			r=mid-1;
		}
		
		
		
	}
	
	if(f(mid,a,n,k)){
		cout<<n*r<<endl;
	}else{
		cout<<n*l<<endl;
	}
	
}



}
