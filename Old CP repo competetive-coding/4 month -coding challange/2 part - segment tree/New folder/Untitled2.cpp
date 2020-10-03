#include<iostream>
using namespace std;
int main(){
int n,v;
cin>>n>>v;
if(n-1==v){
cout<<n-1;
return 0;
}int diff=0;
int p=v;
int tank=p,cost=p;
for(int i=1;i<=n;i++){
if(n-i<=v){
continue;}
if(p<v){
diff=v-p;
p=v;
}
p--;
cost=cost+i*diff;


}

cout<<cost;


}
