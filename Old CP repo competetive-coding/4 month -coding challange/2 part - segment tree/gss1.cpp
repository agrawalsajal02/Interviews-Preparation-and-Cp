#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// #define endl '/n'  dnt write this it can cause error because fflushing is not done here .. even fflush is not work here fflush after endl
struct node{
	ll maxsuff,maxpre,tsum,mms;
	
};
node tree[16*50010];
ll a[50010];

void build(ll start,ll end,ll pos){
	if(start==end){
		tree[pos].tsum=a[start];
		tree[pos].maxpre=a[start];
		tree[pos].maxsuff=a[start];
		tree[pos].mms=a[start];
		return;
	}
	else{
	
	ll mid=(end+start)/2;
	build(start,mid,2*pos+1);
	build(mid+1,end,2*pos+2);
	tree[pos].maxpre=max(tree[2*pos+1].maxpre,tree[2*pos+1].tsum+tree[2*pos+2].maxpre);
	tree[pos].maxsuff=max(tree[2*pos+2].maxsuff,tree[2*pos+2].tsum+tree[2*pos+1].maxsuff);	tree[pos].tsum=tree[2*pos+1].tsum+tree[2*pos+2].tsum;
tree[pos].mms=max(tree[pos].maxpre,max(tree[pos].maxsuff,max(tree[2*pos+1].maxsuff+tree[2*pos+2].maxpre,max(tree[2*pos+1].mms,tree[2*pos+2].mms))));
	
}
}

node queries(ll start,ll end,ll x,ll y,ll pos){
node result;
result.mms=result.maxsuff=result.maxpre=result.tsum=INT_MIN;
if(start>=x&&end<=y){
		return tree[pos];
	}
	else if(y<start||x>end){
		return result;
	}
	ll mid=(start+end)/2;
	node left=queries(start,mid,x,y,2*pos+1);
	node right=queries(mid+1,end,x,y,2*pos+2);
	result.maxpre=max(left.maxpre,left.tsum+right.maxpre);
	result.maxsuff=max(right.maxsuff,right.tsum+left.maxsuff);
	result.tsum=left.tsum+right.tsum;
result.mms=max(result.maxpre,max(result.maxsuff,max(left.maxsuff+right.maxpre,max(left.mms,right.mms))));
	
	return result;
	
	
}

int main(){
	 ios_base::sync_with_stdio(false);   // use this , if not this will cause time limit error because there is lot ogf queries in  it
    cin.tie(NULL);
	ll n,m;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	
	///built tree tree
	build(0,n-1,0);
	
	cin>>m;
	for(ll j=0;j<m;j++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		//queries
		cout<<queries(0,n-1,x,y,0).mms<<endl;
		
	}
}

//or simpler form of solution ablove one is bit complex and unnecessary

/*    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    struct node{
    	ll suff;
    	ll pre;
    	ll tot;
    	ll maxa;
    	
    };
    node seg[16*50010];
    ll v[50010];
     
    void build(ll low,ll high,ll pos){
    	if(low==high){
    		seg[pos].tot=v[low];
    		seg[pos].pre=v[low];
    		seg[pos].suff=v[low];
    		seg[pos].maxa=v[low];
    		return;
    	}
    	
    	ll mid=(high+low)/2;
    	build(low,mid,2*pos+1);
    	build(mid+1,high,2*pos+2);
    	seg[pos].pre=max(seg[2*pos+1].pre,seg[2*pos+1].tot+seg[2*pos+2].pre);
    	seg[pos].suff=max(seg[2*pos+2].suff,seg[2*pos+2].tot+seg[2*pos+1].suff);
    	seg[pos].tot=seg[2*pos+1].tot+seg[2*pos+2].tot;
    	
    	seg[pos].maxa=max(seg[2*pos+1].maxa,max(seg[2*pos+2].maxa,seg[2*pos+1].suff+seg[2*pos+2].pre));
    	
    	
    }
     
    node queries(ll low,ll high,ll x,ll y,ll pos){
     
    	node result ;
    result.maxa=result.suff=result.pre=result.tot=INT_MIN;
    if(low>=x&&high<=y){
    		return seg[pos];
    	}
    	else if(y<low||x>high){
    		return result;
    	}
    	ll mid=(low+high)/2;
    	node left=queries(low,mid,x,y,2*pos+1);
    	node right=queries(mid+1,high,x,y,2*pos+2);
    	result.pre=max(left.pre,left.tot+right.pre);
    	result.suff=max(right.suff,right.tot+left.suff);
    	result.tot=left.tot+right.tot;
    	result.maxa=max(left.maxa,max(right.maxa,left.suff+right.pre));
    	
    	return result;
    	
    	
    }
     
    int main(){
    	 ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    	ll n,m;
    	cin>>n;
    	for(ll i=0;i<n;i++){
    		cin>>v[i];
    	}
    	
    	///built seg tree
    	build(0,n-1,0);
    	
    	cin>>m;
    	for(ll j=0;j<m;j++){
    		ll x,y;
    		cin>>x>>y;
    		x--;y--;
    		//queries
    		cout<<queries(0,n-1,x,y,0).maxa<<endl;
    		
    	}
    } 
	
	
	*/
