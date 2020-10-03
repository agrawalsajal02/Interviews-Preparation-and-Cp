/*
1
4
1 2 3 4
*/
/*
CHAIN OF MATRIX :A1      A2      A3       A4
Dimentions:   P0 * P1  P1 *P2  P2 *P3  P3 * P4

FOR perticular matrix   :    AI
                            PI-1* PI


(Ai ----------Aj ) =( Ai----Ak )+(Ak+1  Aj) +pi-1*pk*pj 
                      pi-1*pk     pk*pj
              i<=k<j



recursive equation:
m[i,j]={    0    i==j;                                                                                                                                                  min(    m[i,k]+m[k+1,j]+pi-1*pk*pj;)
           i<=k<j                                                                   
        }        


total number of ways we can paranthesize the matrix is  
                        (2*n)!/((n+1!)(n!))   same as binary search tree          where n=no of matrices-1                          


 l  ---------------
 1   11  22   33   44
    ---------------
 2  12  23   34
    --------------- 
 3  13  24
    ---------------
 4  14






*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
ll dp[1000][1000];
ll find(ll i,ll j,ll a[]){
if(i==j){
  return 0;
}
if(dp[i][j]!=-1){
  return dp[i][j];
}
ll ans=INT_MAX;
for(ll k=i;k<j;k++){
  ans=min(ans,find(i,k,a)+find(k+1,j,a)+a[i-1]*a[k]*a[j]);
}
return dp[i][j]=ans;
}



void printbrackets(ll **dp,ll i,ll j,char *cnt){
//cout<<" i "<<i<<" "<<j<<endl;
if(i==j){
  cout<<(*cnt);
  (*cnt)++;
return;
}
cout<<("(");
printbrackets(dp,i,dp[i][j],cnt);
printbrackets(dp,dp[i][j]+1,j,cnt);
cout<<")";
}


ll dpbottom(ll lengthofarray,ll a[]){
ll noofmatrices=lengthofarray-1;
ll n=noofmatrices;
ll **s=new ll*[n+1];
f(i,0,n+1){
  s[i]=new ll[n+1];
  f(j,0,n+1){
    s[i][j]=0;
      }
}

ll dp[n+1][n+1]={0};
f(i,1,n+1){
  dp[i][i]=0;
}
//l is length of chain
for(ll l=2;l<=n;l++){
for(ll i=1;i<=n-l+1;i++){
  ll j=i+l-1;
  dp[i][j]=INT_MAX;
  for(ll k=i;k<j;k++){
    ll val=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
    if(dp[i][j]>=val){
      dp[i][j]=val;
  s[i][j]=k;
    }
  }
}
}

f(i,1,n+1){
  f(j,1,n+1){
    cout<<dp[i][j]<<" ";
  }cout<<endl;
}

cout<<endl;
f(i,1,n+1){
  f(j,1,n+1){
    cout<<s[i][j]<<" ";
  }cout<<endl;
}

cout<<endl;
char r='A';
char *p=&r;
printbrackets(s,1,n,p);
return dp[1][n];
}

int main(){
ll t;
cin>>t;
while(t--){
  ll n;
  cin>>n;
  f(i,0,n+1){
    f(j,0,n+1){
      dp[i][j]=-1;
    }
  }
  ll a[n];
  f(i,0,n){
    cin>>a[i];
  } 
  //find(1,n-1,a);

cout<<dpbottom(n,a)<<endl;
}


}

/*

2
5
1 2 3 4 5
3
3 3 3
*/
