#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll fw(ll value,ll posofstall[],ll cow,ll noofstall){
	ll pos=0;
	for(ll i=0;i<noofstall;i++){
		if(pos+value>posofstall[noofstall-1]){
			cow--;
		}
		else{
			return false;
		}
		
	}
	return true;
}


ll f(ll x,ll pos[],ll N,ll C)
{

  //We can always place the first cow in the leftmost stall

  ll cowsplaced=1,lastpos=pos[0];

  for(ll i=1;i<N;i++)

  {

    if(pos[i]-lastpos>=x)

    {

      //We are at least x away from last placed cow

      //So we can place one here

      if(++cowsplaced==C)return 1;

      lastpos=pos[i];

    }

  }

  return 0;

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
	
	ll l=0;
	ll h=a[n-1];
	ll ans=0;
	
	while(l<h-1){   //in case of two member array predicate it drops
		
		ll mid=l+(h-l)/2;
		
		if(f(mid,a,n,c)){
	          ///it it the pat of moving toward highst t    in ttttttttttttttttffffffffffffff
	   l=mid;	  //fortttttttttttttttffffffffffff         //  h=mid  for fffftttttttttttttttttt
	}
		else{                    // it is the pasrt of moving toward t from f
	h=mid-1;       //for tttttttttttttffffffffffffffff   //  l=mid+1	//for  fffffffffffffffftttttttttttttt	
		}
		
		
		
	}
	
	if(f(h,a,n,c))cout<<h<<endl;   ////////////for    fffffffffffffftttttttttttttttt
	else cout<<l<<endl;            ///for   tttttttttttttttttffffffffffff
}	
	
}
