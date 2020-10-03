/*          don't look at my code
            make your own code

            by: SAJAL AGRAWAL
                                    ----XBAR

*/
//USE EMPLACE_BACK IN PLACE OF PUSH_BACK
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
using namespace std;
int main(){
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++){
	char s[20];
cin>>s;
ll a[26],b[26];
for(ll j=0;j<26;j++){
	a[j]=0;b[j]=0;
}

for(ll j=0;j<strlen(s);j++){
	a[s[j]-'A']++;

}
sort(a,a+26,greater<ll>());

for(ll j=0;j<26;j++){
	cout<<a[j]<<" ";
}
cout<<endl;
ll ans=INT_MAX;
ll l=strlen(s);
for(ll j=1;j<=26;j++){ //j is no of pairs of distinct letter
	if(l%j!=0){
		continue;
	}ll kk=0;
	ll count=0;
	ll value=l/j;  
	vector<ll>v;
	//give no of letter in one pair
	for(ll k=0;k<j;k++){
		if(a[k]==value){
			continue;
		}

			if(a[k]<value){
				if(kk>0){
					if(kk>=abs(a[k]-value)){
						kk=kk-abs(a[k]-value);
						continue;
					}
					else{
						
						ll jj=abs(a[k]-value)-kk;
						kk=0;
						count=count+jj;
					}
				
					
			continue;
				}
			}
			
				if(a[k]>value){
		
		kk=kk+abs(a[k]-value);	
		}
						
		count=count+abs(a[k]-value);

		if(j==5)cout<<" c2 "<<count<<"  ";

	}
	ans=min(ans,count);
	cout<<"  count "<<count<<"  FOR J "<<j<<endl;
	
	
}


cout<<"  ans is "<<ans<<endl;


}
}
	







