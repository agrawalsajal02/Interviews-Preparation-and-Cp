/*          don't look at my code
            make your own code

            by: SAJAL AGRAWAL
                                    ----XBAR

*/
#include<iostream>
using namespace std;
#define ll long long
#define mod 1000000007
ll fastmodexp(ll a,ll b){
	ll res=1;
	while(b>0){
		 if (b & 1)
		res=((res%mod)*(a%mod))%mod;
	
		a=((a%mod)*(a%mod))%mod;
		b=b>>1;
	}
	return (res+mod)%mod;
}
int main(){
	ll t;cin>>t;
	for(ll i=0;i<t;i++){
	ll a1,a,b,b2;
	ll n,k,m;
	cin>>n>>k>>m;
	if(n==1){
		cout<<(1%mod)<<endl;
		continue;
	}
ll ans;
if(m%2==1){
	ll inside=(1-fastmodexp(n,mod-2)+mod)%mod;
	ans=((1-fastmodexp(inside,m/2+1)+mod)%mod);
	cout<<ans<<endl;
	
}
else{
	ll inside=(1-fastmodexp(n,mod-2)%mod+mod)%mod;
	ans=((1-fastmodexp(inside,(m+1)/2)+mod)%mod);
	ans=(ans+((fastmodexp(inside,(m)/2)%mod)*(fastmodexp(n+k,mod-2)%mod))%mod)%mod;
	cout<<ans<<endl;
}

}
}
