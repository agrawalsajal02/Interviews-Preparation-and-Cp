#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
map<string,bool>m;

ll dp[1010];
bool wordb(string s){
ll l=s.length();
if(l==0){
    return 0;
}
ll dp[l+1];f(i,0,l+1)
dp[i]=0;
for(int i=1;i<=l;i++){
if(dp[i]==false&&m[s.substr(0,i)]){
    dp[i]=true;
}
if(dp[i]==true){
if(i==l){
    return 1;
}
for(int j=i+1;j<=l;j++){
if(dp[j]==false&&m[s.substr(i,j-i)]){
    dp[j]=true;
}
if(j==l&&dp[j]==true){
    return true;
}
}


}

}

return false;
}
int main(){

    ll t;
    cin>>t;
    while(t--){
ll n;
cin>>n;

f(i,0,n){
    string x;
    cin>>x;
    m[x]=1;
}
string k;
cin>>k;
ll len=k.length()-1;
cout<<wordb(k)<<endl;
m.clear();






    }


}
