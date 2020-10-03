    #include<bits/stdc++.h>
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
    void update(ll low,ll high,ll pos,ll index,ll value){
    	if(low==high&&index==low){
    		seg[pos].maxa=value;
    		seg[pos].pre=value;
    		seg[pos].suff=value;
    		seg[pos].tot=value;
    		
    		return;
		}
		if(low>index||high<index){
			return;
		}
		ll mid=(low+high)/2;
		update(low,mid,2*pos+1,index,value);
    	update(mid+1,high,2*pos+2,index,value);
    	seg[pos].pre=max(seg[2*pos+1].pre,seg[2*pos+1].tot+seg[2*pos+2].pre);
    	seg[pos].suff=max(seg[2*pos+2].suff,seg[2*pos+2].tot+seg[2*pos+1].suff);
    	seg[pos].tot=seg[2*pos+1].tot+seg[2*pos+2].tot;
    	
    	seg[pos].maxa=max(seg[2*pos+1].maxa,max(seg[2*pos+2].maxa,seg[2*pos+1].suff+seg[2*pos+2].pre));
    	
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
    	ll k;
    	cin>>k;
			ll x,y;
    	if(k==0){
    		cin>>x>>y;
    		x--;
    	update(0,n-1,0,x,y);
		continue;	
		}else if(k==1){
		cin>>x>>y;
		x--;y--;
    		//queries
    		cout<<queries(0,n-1,x,y,0).maxa<<endl;
    			
			
		}
    	}
    }
