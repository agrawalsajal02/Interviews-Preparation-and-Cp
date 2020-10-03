/*          don't look at my code
            make your own code

            by: SAJAL AGRAWAL
                                    ----XBAR

*/
//OHM NAMA SHIVAY -- ACCEPT KARVA DO
///remember to use strlen outside the loop --even not in heading because it it increases time complexicity
#include<bits/stdc++.h>
using namespace std;
#define ll int
#pragma GCC optimize O2
#define _CRT_DISABLE_PERFCRIT_LOCKS

#define endl '\n'
int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++){
	char s[1000000];
cin>>s;
ll a[26];
for(ll j=0;j<26;j++){
	a[j]=0;
    
}
ll l=strlen(s);
for(ll j=0;j<l;j++){
	a[s[j]-'A']++;
    
}

sort(a,a+26,greater<ll>());
ll m=0;
for(ll j=0;j<26;j++){
	if(a[j]==0){break;
	}
	m++;
    
}

vector<ll>v;
ll ans=INT_MAX;

ll vj=0;
for(ll p=1;p<=26;p++){
		if(l%p==0){		
			v.push_back(p);
			    if(m==p){
           vj=p;
		}
		}	}
	
if(vj!=0){

	if(l%vj!=0){
		continue;
	}ll kk=0;
	ll count=0;
	ll value=l/vj;  //give no of letter in one pair
	for(ll k=0;k<vj;k++){
		if(a[k]==value){
			continue;
		}			if(a[k]<value){
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

	}
	if(count>ans){
	    break;
	}
	ans=min(ans,count);


}
else{
	
	
for(ll j=0;j<v.size();j++){ //j is no of pairs of distinct letter
	if(l%v[j]!=0){
		continue;
	}ll kk=0;
	ll count=0;
	ll value=l/v[j];  //give no of letter in one pair
	for(ll k=0;k<v[j];k++){
		if(a[k]==value){
			continue;
		}			if(a[k]<value){
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

	}
	if(count>ans){
	    break;
	}
	ans=min(ans,count);
}
	
	
}



cout<<ans<<endl;




}
}








