//very hard to make program !!!takes days to build it;
// with updates query on point

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
	struct node{
	ll maxpre,maxsuff,tsum,mms;

};
node tree[16*50010];
ll a[50010];
void merge(node &nodee,node &cl,node &cr)
{
	nodee.tsum = cl.tsum+cr.tsum;
	nodee.maxpre= max(cl.tsum+cr.maxpre,cl.maxpre);
	nodee.maxsuff = max(cr.tsum+cl.maxsuff,cr.maxsuff);
	nodee.mms = max(cl.mms,max(cr.mms,cl.maxsuff+cr.maxpre));
}
void builttree(ll start,ll end,ll pos){
	if(start==end){
		tree[pos].maxpre=a[start];
		tree[pos].maxsuff=a[start];
		tree[pos].tsum=a[start];
		tree[pos].mms=a[start];
	
	}
	else{
	
	ll mid=(start+end)/2;
	builttree(start,mid,2*pos+1);
	builttree(mid+1,end,2*pos+2);
	
	merge(tree[pos],tree[2*pos+1],tree[2*pos+2]);
	/*  uses merge function to solve in one line
	tree[pos].maxpre=max(tree[2*pos+1].maxpre,tree[2*pos+1].tsum+tree[2*pos+2].maxpre);
	tree[pos].maxsuff=max(tree[2*pos+2].maxsuff,tree[2*pos+2].tsum+tree[2*pos+1].maxsuff);
	tree[pos].tsum=tree[2*pos+1].tsum+tree[2*pos+2].tsum;
//	tree[pos].mms=max(tree[pos].maxpre,max(tree[pos].maxsuff,max(tree[2*pos+1].maxsuff+tree[2*pos+2].maxpre,max(tree[2*pos+1].mms,tree[2*pos+2].mms))));
	tree[pos].mms=max(tree[2*pos+1].maxsuff+tree[2*pos+2].maxpre,max(tree[2*pos+1].mms,tree[2*pos+2].mms));
*/
}

}


node query(ll start,ll end,ll l,ll r,ll pos){
node result ;
result.maxpre=result.maxsuff=result.mms=result.tsum=INT_MIN;
	if(l<=start&&r>=end){
		return tree[pos];
	}
	if(r<start||end<l){
		return result;
	}
	
	
	
	ll mid=(start+end)/2;
/*  //isski jarurat nhi he
   if (l > mid)
         return query( mid+1, end, l, r,2*pos+2);
   if (r <= mid)
         return query( start, mid, l, r,2*pos+1);
*/	
	node left=query(start,mid,l,r,2*pos+1);
	node right=query(mid+1,end,l,r,2*pos+2);
merge(result,left,right);/*	
	result.tsum=left.tsum+right.tsum;
	result.maxpre=max(left.maxpre,left.tsum+right.maxpre);
	result.maxsuff=max(right.maxsuff,right.tsum+left.maxsuff);
//	result.mms=max(result.maxpre,max(result.maxsuff,max(left.maxsuff+right.maxpre,max(left.mms,right.mms))));
	result.mms=max(left.maxsuff+right.maxpre,max(left.mms,right.mms));
	*/
	return result;
	
}


void update(ll start,ll end,ll index,ll v,ll pos){
	if(start==end){
		tree[pos].maxpre=v;
		tree[pos].maxsuff=v;
		tree[pos].tsum=v;
		tree[pos].mms=v;
	
	}
	else{
	
	ll mid=(start+end)/2;
	 if (index<= mid){
	update(start,mid,index,v,2*pos+1);
 	
	 }
	 else{
	 	update(mid+1,end,index,v,2*pos+2);
	 }
	
	merge(tree[pos],tree[2*pos+1],tree[2*pos+2]);
		/*  
	tree[pos].maxpre=max(tree[2*pos+1].maxpre,tree[2*pos+1].tsum+tree[2*pos+2].maxpre);
	tree[pos].maxsuff=max(tree[2*pos+2].maxsuff,tree[2*pos+2].tsum+tree[2*pos+1].maxsuff);
	tree[pos].tsum=tree[2*pos+1].tsum+tree[2*pos+2].tsum;
	tree[pos].mms=max(tree[pos].maxpre,max(tree[pos].maxsuff,max(tree[2*pos+1].maxsuff+tree[2*pos+2].maxpre,max(tree[2*pos+1].mms,tree[2*pos+2].mms))));*/
	cout<<"  see: "<<tree[pos].mms<<endl;
}

}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	builttree(0,n-1,0);
	ll q;
	cin>>q;
	for(ll i=0;i<q;i++){
		ll c,b;
		cout<<" query "<<endl;
		
		cin>>b>>c;
		ll p=query(0,n-1,b,c,0).mms;
		cout<<p<<endl;
		cout<<" update : index , value "<<endl;
		ll k,u;
		cin>>k>>u;
		if(k<0){
			continue;
		}
		
		update(0,n-1,k,u,0);
		cout<<endl<<endl;for(ll r=0;r<4*n;r++){
			cout<<tree[r].mms<<" ";
		}
		
	}
}
