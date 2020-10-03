/*Inversion count*/
//updatd version
//l=i-2r+1
//r=i
//two things to remember
//1)you have to clean the bit array, clean only the required ammount , not the whole array
//2)use cordinate compression
//3)try same question with pbts
//4)try same with balanced binary search tree
//try samw with merge sort
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
  ll a[1000000]={0};
  ll b[1000000]={0};
  ll *bit=new ll[10000000]{0};
void update(ll i,ll val,ll n){
  while(i<=n){
    bit[i]+=val;
    i=i+(i&(-i));

  }
  return;
}
ll query(ll i){
  ll ans=0;
  while(i>0){
    ans+=bit[i];
    i=i-(i&(-(i)));
  }
  return ans;
}
int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll ma=0;
    set<ll>s;
    for(ll i=1;i<=n;i++){
cin>>a[i];
s.insert(a[i]);
ma=max(ma,a[i]);
    }
/*ll val=1;
unordered_map<ll,ll>m;
    for(auto it=s.begin();it!=s.end();it++){
m[*it]=val;
val++;
    }

f(i,1,n+1){
  b[i]=m[a[i]];
}
*/
    f(i,0,ma+2){
bit[i]=0;
    }
    ll cnt=0;
  for(ll i=n;i>=1;i--){

    cnt+=query(b[i]-1);
   
    update(b[i],1,ma+1);
  }
cout<<cnt<<endl;
/*Very Important Cleaning Process , Not required to clean the whole Bit Process*/
  for(ll i=n;i>=1;i--){
      update(b[i],-1,ma+1);
}



}

}
