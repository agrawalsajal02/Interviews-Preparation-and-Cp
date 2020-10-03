//manachers algorithm
//for longest palindrome substring on o(n)
//https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0/?track=md-string&batchId=144

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
ll center=0;
string temp="$#";
f(i,0,s.length()){
temp=temp+s[i];
temp=temp+"#";
}
temp=temp+"@";

//cout<<temp<<endl;
ll p[temp.length()+1]={0};
ll c=0,r=0;

for(int i=1;i<temp.length()-1;i++){
if(i<r){
//should be strictly less than boundary
ll mirror=2*c-i;

    p[i]=min(r-i,p[mirror]);
}


while(temp[i-(p[i]+1)]==temp[i+(p[i]+1)]){
    p[i]++;
}

if(i+p[i]>r){
c=i;
r=p[i]+i;
}
//below not require
center=max(center,p[i]);
}

/*  below not require , only if you need to find first occutnce of max length */

f(i,0,temp.length()){
    if(p[i]==center){
        c=i;
        r=p[i]+i;
        break;
    }
}

/*
f(i,0,temp.length()){
    cout<<p[i];
}cout<<endl<<endl;
*/
//cout<<" "<<c<<" "<<r<<endl;
for(int i=c-(r-c);i<=r;i++){
    if(temp[i]!='#'){
          cout<<temp[i];
    }
}
cout<<endl;
/*
input 1
aaaabbaa
output
aabbaa


*/
}


}
