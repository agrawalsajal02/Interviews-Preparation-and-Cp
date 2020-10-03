#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
int main() {
ll t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    ll len=s.length();
    ll *dp=new ll[len+2]{0};
    dp[0]=0;
    for(ll i=1;i<=s.length();i++){
     if(s[i-1]=='('){
    dp[i]=0;
     }
     else{
        if(s[i-1]==')'&&s[i-1-1]=='('){
        dp[i]=dp[i-2]+2;
        }
        else{
            if(i-dp[i-1]-2>=0&&s[i-dp[i-1]-1-1]=='('){
            dp[i]=dp[i-dp[i-1]-2]+dp[i-1]+2;   
            }
            else{
                dp[i]=0;
            }
        }
     }
    }
/*for(ll i=0;i<=len;i++){
    cout<<dp[i]<<" ";
}*/
cout<<*max_element(dp,dp+len+1)<<endl;
}


}
