#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

/*

Imp condition
 array of n distinct positive integers
*/


// int getless(ordered_set &os, int R, int index)
// {
//       return os.order_of_key({R, index});
// }
ll a[10000000];
int main()
{
        ll t;
        cin>>t;
        while(t--){
    ordered_set os1;
    ll n;
    cin>>n;
    f(i,1,n+1)cin>>a[i];
    
ll ans=0;
    for(ll i=n;i>=1;i--){
  ans+=os1.order_of_key(a[i]);
  os1.insert(a[i]);
    }    
    cout<<ans<<endl;
    
    
    
    
    
        }
    






 //    os1.insert(63);
 //    os1.insert(85);
 //    os1.insert(15);
 //    os1.insert(64);
 //    os1.insert(96);
 // int k = 3;
 //    cout << k << "rd smallest: " << *os1.find_by_order(k-1) << endl;
 //   cout<<"no of element less than "<< os1.order_of_key(65) <<endl;
    
   
   return 0;
}
