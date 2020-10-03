//do not use elseif condition in dfs or bsf , use only if if if if
//correction:-forgot to !=m
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
char **a;
bool b[20][20];
ll co=0;
ll level[20][20];
//bfs here
void bfs(ll x,ll y,ll s,ll e){
b[x][y]=1;
level[x][y]=0;
queue<pair<ll,ll>>q;
q.push(make_pair(x,y));
while(!q.empty()){
    pair<ll,ll>lr=q.front();q.pop();
    ll a1=lr.first;ll a2=lr.second;
     if(a1==s&&a2==e)return;
    if(b[a1-1][a2]==false&&(a[a1-1][a2]!='#')&&(a[a1-1][a2]!='m')){
        level[a1-1][a2]=level[a1][a2]+1;
        //cout<<" here  1 "<<a1-1<<" "<<a2<<" "<<" "<<level[a1-1][a2]<<" "<<endl;
        b[a1-1][a2]=true;
        q.push(make_pair(a1-1,a2));
    }
    if(b[a1+1][a2]==false&&(a[a1+1][a2]!='#')&&(a[a1+1][a2]!='m')){
        level[a1+1][a2]=level[a1][a2]+1;
        b[a1+1][a2]=true;
    q.push(make_pair(a1+1,a2));
    //cout<<" here  2 "<<a1+1<<" "<<a2<<" "<<endl<<level[a1+1][a2];

    }
    if(b[a1][a2-1]==false&&(a[a1][a2-1]!='#')&&(a[a1][a2-1]!='m')){
        level[a1][a2-1]=level[a1][a2]+1;
        b[a1][a2-1]=true;
        q.push(make_pair(a1,a2-1));

      //  cout<<" here  3 "<<a1<<" "<<a2-1<<" "<<endl<<level[a1][a2-1];
    }
    if(b[a1][a2+1]==false&&(a[a1][a2+1]!='#')&&(a[a1][a2+1]!='m')){
        level[a1][a2+1]=level[a1][a2]+1;
        b[a1][a2+1]=true;
        q.push(make_pair(a1,a2+1));
        //cout<<" here  4 "<<a1<<" "<<a2+1<<" "<<endl<<level[a1][a2+1];
    }



}


}



int main(){
    ll t;cin>>t;
    for(ll i=0;i<t;i++){
        ll n,m;cin>>n>>m;
        ll a1,a2,b1,b2,c1,c2,f1,f2;
        a=new char*[n];
        for(ll j=0;j<n;j++){
            a[j]=new char[m];
            for(ll k=0;k<m;k++){
                cin>>a[j][k];
                if(a[j][k]=='a'){
                    a1=j;
                    a2=k;
                }
                else if(a[j][k]=='b'){
                    b1=j;
                    b2=k;
                }
                else if(a[j][k]=='c'){
                    c1=j;c2=k;
                }
                else if(a[j][k]=='h'){
                    f1=j;f2=k;
                }
            }
        }
       ll ma=0;
        for(ll j=0;j<n;j++){
            for(ll k=0;k<m;k++){
                b[j][k]=0;level[j][k]=-1;
            }
        }
        bfs(a1,a2,f1,f2);
        ma=max(ma,level[f1][f2]);



        for(ll j=0;j<n;j++){
            for(ll k=0;k<m;k++){
                b[j][k]=0;
                level[j][k]=-1;
            }
        }
        bfs(b1,b2,f1,f2);
        ma=max(ma,level[f1][f2]);
     for(ll j=0;j<n;j++){
            for(ll k=0;k<m;k++){
                level[j][k]=-1;
                b[j][k]=0;
            }
        }
        bfs(c1,c2,f1,f2);ma=max(ma,level[f1][f2]);

        cout<<"Case "<<i+1<<": "<<ma<<endl;
        co=0;

    }
}

