//time complexicity sqrt(n)  :- efficieant than bruteforce
#include<iostream>
using namespace std;
#define ll long long int
ll finddivisorsum(int a){
    ll sum=0;
    for(ll i=1;i*i<=a;i++){
        if(a%i==0){
            sum=sum+i;
            if(a/i!=i)
            sum=sum+a/i;
        }
    }
    sum=sum-a;//proper divisor
    return sum;
}
int main(){
    ll n;
    cin>>n;
   ll a;
   for(ll i=0;i<n;i++){
       cin>>a;
       cout<<finddivisorsum(a)<<endl;     
       
   }
}
