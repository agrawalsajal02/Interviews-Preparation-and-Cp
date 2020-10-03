#include<iostream>
#include<math.h>
using namespace std;
#define ll long long
#define maxa 999999999
void construct(ll a[],ll seg[],ll low,ll high,ll pos){
if(low==high){
    //you hae reached to the base node , just put the value in it
    //calculation of leafes nodes
    seg[pos]=a[low];
    return;
}
// calculte for the parent nodes from its child nodes
ll mid=(low+high)/2;
construct(a,seg,low,mid,2*pos+1);
construct(a,seg,mid+1,high,2*pos+2);
seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);

}
ll queries(ll qlow,ll qhigh,ll seg[],ll low,ll high,ll pos){
if(qlow<=low&&qhigh>=high){
    return seg[pos];
}
else if(qlow>high||qhigh<low){
    // means no overlap
    //return max vaue;
    return maxa;
}
ll mid=(high+low)/2;
return(min(queries(qlow,qhigh,seg,low,mid,2*pos+1),queries(qlow,qhigh,seg,mid+1,high,2*pos+2)));


}

int main(){
//for segment tree , you have to first built the tree in o n times
ll n;
cin>>n;
ll a[n];
for(ll i=0;i<n;i++){
    cin>>a[i];
}
ll p=ceil((log2(n)));
ll m=2*pow(p,2)-1;
ll b[m];
ll pos=0;
ll low=0,high=n-1;
//contruct the segment tree

construct(a,b,low,high,pos);
while(1){
cout<<endl<<" here "<<endl;
//now the most imp part
// range queries
ll qlow,qhigh;
cout<<" enter the range "<<endl;
cin>>qlow>>qhigh;
cout<<queries(qlow,qhigh,b,low,high,pos);


}
}
