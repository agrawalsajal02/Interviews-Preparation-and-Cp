#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll binary(ll l,ll mid,ll a[]){
	ll r=2*mid-l;
	while((l<r-1)){
		
	
	if(a[mid]+a[l]>=a[r]){
		r=mid;
	}else{
		l=mid+1;
	}
}
   return l;	
}
int main(){
	while(1){
		ll n;
		cin>>n;
		if(n==0)break;
		ll a[n];
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		ll count=0;
		for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				if(a[i]+a[j]<a[n-1]){
					ll l=j+1;ll ans;
					ll r=n-1;
					while(l<r-1){
						ll mid=r+(l-r)/2;
						if(a[mid]>a[i]+a[j]){
							r=mid;
						}else{
							l=mid+1;
						}
						
						
					}
					if(a[l]>a[i]+a[j]){
						ans=n-l;
					}else{ans=n-r;
					}
					count=count+ans;
								}
				
				
				
				
			}
		}
		
		cout<<count<<endl;
		
	}
}
