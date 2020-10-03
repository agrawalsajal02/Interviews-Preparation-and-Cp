//longest palindromic substring using dp
//longest palindromic substring using dp
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
ll i1=0,j1=0;
ll n=s.length();
ll dp[s.length()+1][s.length()+1];
for(int i=s.length()-1;i>=0;i--){
    f(j,0,s.length()+1){
        dp[i][j]=0;
        if(i==j){
            dp[i][j]=1;        }
    }
}
ll ans=1;
ll ma=1;

for(int i=n-1;i>=0;i--){
    f(j,i,n){
       
            if(i+1==j&&s[i]==s[j]){
                dp[i][j]=1;
                if(ans<=2){ans=2;
                i1=i;
                j1=j;
                }
                continue;             }
              if(dp[i+1][j-1]==1&&s[i]==s[j]){
                if(ans<=j-i+1){
        ans=j-i+1;
                i1=i;
                j1=j;
                }
                
            dp[i][j]=1;
              }              
        }
    
}

for(int i=i1;i<=j1;i++){
    cout<<s[i];
}cout<<endl;
}}













































//old code
/*#include<bits/stdc++.h>
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
ll dp[s.length()+1][s.length()+1];
f(i,0,s.length()+1){
    f(j,0,s.length()+1){
        dp[i][j]=0;
        if(i==j){
            dp[i][j]=1;        }
    }
}
ll ma=1;
for(int i=n-1;i>=0;i--){
    f(j,0,n){
        if(i<j){
            if(i+1==j&&s[i]==s[j]){
                dp[i][j]=1;
                ll tt=2;
                ma=max(ma,tt);
                continue;             }
             //   cout<<" here "<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<" "<<endl;
              if(dp[i+1][j-1]==1&&s[i]==s[j]){
                ma=max(ma,j-i+1);
                dp[i][j]=1;
              }              
        }
    }
}
ll fl=0;
f(i,0,n){
    f(j,0,n){
if(j-i+1==ma&&dp[i][j]){
//cout<<" i "<<i<<" "<<j<<endl;
    f(k,i,j+1){
        cout<<s[k];
    }
    goto end;
}
    }
    //cout<<endl;
   
}
end:
cout<<endl;
}}*/
