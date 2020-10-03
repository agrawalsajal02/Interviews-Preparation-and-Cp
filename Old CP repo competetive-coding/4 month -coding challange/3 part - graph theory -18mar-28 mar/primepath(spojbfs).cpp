#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//first genertae seive series from 1000 to 9999
int main(){
bool prime[10000];
ll parent[10000];
memset(prime, true, sizeof(prime));
     for (ll p=1000; p*p<=10000; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (ll i=p*p; i<=10000; i += p)
                prime[i] = false;
        }
    }

    cout<<" here "<<prime[1179]<<endl;    // Print all prime numbers
    map< ll , ll  > dist;
        for(ll j=1000;j<=9999;j++){

        if(prime[j]){
            dist[j]=-1;
        }

    }

    ll n;cin>>n;
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
            queue<ll>q;
            if(a<b){
            q.push(a);
            dist[a]=0;
            parent[a]=-1;
            }
            else{
               q.push(b);
            parent[b]=-1;
            dist[b]=0;
            }
            while(!q.empty()){
                ll value=q.front();

                q.pop();
                if(!prime[value])continue;
                for(ll s=0;s<=9;s++){
                ll ans=(value/10)*10+s;
                 if(!prime[value]||!prime[ans])continue;
                if(ans>=1000&&ans<=9999&&dist[ans]==-1&&dist[value]==-1){
                    dist[ans]=dist[value]+1;
                    q.push(ans);

                    parent[ans]=value;
                  cout<<"  here 1  "<<ans<<"  v  "<<value<<"  dist[ans] " <<  dist[ans]<<endl;

                }
                }
                for(ll s=0;s<=9;s++){
                ll pp=value%100;
                pp=pp%10;
                ll ans=(value/100)*100+s*10+pp;

   if(!prime[value]||!prime[ans])continue;
                if(ans>=1000&&ans<=9999&&dist[ans]==-1&&dist[value]==-1){
                    dist[ans]=dist[value]+1;
                    q.push(ans);
                    parent[ans]=value;
                  cout<<"  here 2  "<<ans<<"  v  "<<value<<"  dist[ans] " <<  dist[ans]<<endl;

                }
                }
                for(ll s=0;s<=9;s++){
                ll pp=value%1000;
                pp=pp%100;
                ll ans=(value/1000)*1000+s*100+pp;
   if(!prime[value]||!prime[ans])continue;
                if(ans>=1000&&ans<=9999&&dist[ans]==-1&&dist[value]==-1){
                    dist[ans]=dist[value]+1;
                    q.push(ans);
                    parent[ans]=value;
                      cout<<"  here 3  "<<ans<<"  v  "<<value<<"  dist[ans] " <<  dist[ans]<<endl;

                }
                }
                for(ll s=0;s<=9;s++){
                ll pp=value%1000;

                ll ans=s*1000+pp;
   if(!prime[value]||!prime[ans])continue;

                if(ans>=1000&&ans<=9999&&dist[ans]==-1&&dist[value]==-1){
                    dist[ans]=dist[value]+1;
                    q.push(ans);
                    parent[ans]=value;
                      cout<<"  here 4  "<<ans<<"  v  "<<value<<"  dist[ans] " <<  dist[ans]<<endl;

                }
                }





            }

	int temp=b;
		while(temp!=-1){
			cout<<temp<<" -> ";
			temp=parent[temp];
		}
cout<<"fuck"<<endl;

    cout<<dist[b]<<endl;

    }

}
