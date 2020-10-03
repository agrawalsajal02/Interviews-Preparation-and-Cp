#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve(){

ll t;
cin>>t;
for(ll d=0;d<t;d++){


string s;
fflush(stdin);
getline(cin,s);
fflush(stdin);
cout<<s<<endl;
string p="not";

size_t found = s.find(p); 
    if (found != string::npos){
      cout<<"found"<<endl;
  } 
  else{
    cout<<"not found"<<endl;
  }




}

  
}

  
int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
   
    freopen("output.txt", "w", stdout);
#endif
solve();
}
