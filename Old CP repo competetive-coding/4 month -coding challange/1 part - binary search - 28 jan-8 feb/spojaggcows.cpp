//finally accepted after two mistakes
// mistakes are end case chek and a[n-1]=r;
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll f(ll mid,ll cows,ll noosstalls,ll a[]){
	ll count=1;ll pos=a[0];
	for(ll i=1;i<noosstalls;i++){
		if(a[i]-pos>=mid){
			count++;
			pos=a[i];
		}
		if(count==cows)break;
	}
	if(count==cows){
		return mid;
	}
	else{
		return 0;
	}
}



int main(){
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++){
		ll n,c;
		cin>>n>>c;
		ll a[n];
		for(ll j=0;j<n;j++){
			cin>>a[j];
		}
		
		sort(a,a+n);
		
		//appling binary  search
		
		ll l=0;ll r=a[n-1];
		while(l<r-1){
			ll mid=l+(r-l)/2;
			
			
			if(f(mid,c,n,a)){
				l=mid;
			}
			else{
				r=mid-1;
			}
			
		}
		if(f(r,c,n,a)){
			cout<<r<<endl;
		}
		else{
			cout<<l<<endl;
		}
		
		
		
		
		
		
	}
}
