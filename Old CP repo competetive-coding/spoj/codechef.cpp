/*          don't look at my code
            make your own code

            by: SAJAL AGRAWAL
                                    ----XBAR

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef double ld;
#define ll long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++){
ll n;
cin>>n;
	ll d=0;
ll a[n],b[n];
for(ll j=0;j<n;j++){
	cin>>d;
	a[j]=d;
}
for(ll j=0;j<n;j++){
	cin>>d;
	b[j]=d;
}
if(a[0]!=0||b[n-1]!=0||a[n-1]!=b[0]||b[0]==0){
	cout<<"NO"<<endl;
	continue;
}else{
	ll s=1;
	for (s=1;s<n-1;s++){
		
	
		if( a[s]+b[s] < b[0] || a[s]+b[0] < b[s] || b[s]+b[0] < a[s] || !a[s] || !b[s] ){
			cout<<"NO"<<endl;
			break;
		}
	
}
	if(s==n-1){
		cout<<"YES"<<endl;
	}
	

}


}

}


