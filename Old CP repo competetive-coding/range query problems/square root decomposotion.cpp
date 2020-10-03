//square root decomposiotion
//for range sum query
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll query(ll *blocks,ll a[],ll l,ll r,ll rn){
	//spliting the query in three part
	ll ans=0;
	while(l<r&&l!=0&&l%rn!=0){
		ans=ans+a[l];
		l++;
	}
	
	//middle part
	while(l+rn<=r){
		ll block=l/rn;//since l already reaches to net block
		ans=ans+blocks[block];
		l=l+rn;
	}
	//l is moving toward r
	//rightmost patrt
	while(l<=r){
		ans=ans+a[l];
		l++;
	}
	return ans;
	
}

void update(ll *bl,ll a[],ll index,ll value,ll rn){
	ll block=index/rn;	
	bl[block]=bl[block]+value-a[index];
	a[index]=value;
	
}
int main(){
	ll a[]={1,3,5,2,7,6,3,1,4,8};
	ll n=sizeof(a)/sizeof(ll);
	
	//step 1:-built a block araay 
	// then update and query function
	ll rn=sqrt(n);  //roon n block size
	ll *blocks=new ll[rn+1]{0};
	ll block=-1;
	for(ll i=0;i<n;i++){
		if(i%rn==0){
			// at every starting of block i have to initialize blok array
			block++;//give block to 0 id
		}
		blocks[block]=blocks[block]+a[i];
	}
	for(ll i=0;i<=rn;i++){
		cout<<blocks[i]<<endl;
	}
	
	update(blocks,a,2,15,rn);
	//now how to queery
  cout<<query(blocks,a,2,8,rn);
	
}
