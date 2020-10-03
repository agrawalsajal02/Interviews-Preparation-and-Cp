#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
int main(){
    ll t;
    cin>>t;
    while(t--){
string s;
cin>>s;
ll n=s.length();

string ans="";
f(i,0,n){
ll center=i,count=0;
ll i1=i,j1=i;
while(i-count>=0&&i+count<n&&(s[i-count]==s[i+count])){
    i1=i-count;j1=i+count;
    count++;
}

if(j1-i1+1>ans.length()){
    ans=s.substr(i1,j1-i1+1);
  }

}

f(i,0,n-1){
ll count=0;
ll i1=i,j1=i+1;
while(i-count>=0&&i+1+count<n&&(s[i-count]==s[i+1+count])){
i1=i-count;j1=i+1+count;
    count++;
    
}
if(s[i1]==s[j1]&&j1-i1+1>ans.length()){
    ans=s.substr(i1,j1-i1+1);
}

}



cout<<ans<<endl;


    }



}
