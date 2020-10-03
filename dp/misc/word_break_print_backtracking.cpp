#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
map<string,bool>m;
string k;
bool find(ll i,string ans){
if(i==k.length()){
    cout<<"(";
    f(p,1,ans.length()){
        cout<<ans[p];
    }
    cout<<")";
}

for(ll j=i;j<k.length();j++){
if(m[k.substr(i,j-i+1)]){
 find(j+1,ans+' '+k.substr(i,j-i+1));   
}
}

}
int main(){

    ll t;
    cin>>t;
    while(t--){
ll n;
cin>>n;
m.clear();
f(i,0,n){
    string x;
    cin>>x;
    m[x]=1;
}
cin>>k;
string s="";
find(0,s);
cout<<endl;





    }

/*
1
5
lr m lrm hcdar wk
hcdarlrm

(hcdar lr m)(hcdar lrm)

*/

}
