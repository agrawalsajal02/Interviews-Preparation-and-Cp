#include<iostream>
using namespace std;
int knapsack(int wts[],int prices[],int n,int weight){
	 //thele me jagaye nahi he (bag remaining capacity is0)or saman hi nhi bacha(no of item is 0 to chor to kuch uta hi nhi sakta
	 if(weight==0||n==0){
	 	//base case
	 	return 0;
	 }
	 
	 int inc=0,exc=0;
	 // we have to check that item weight is not mare than the sack weight
//including a current item
if(weight>=wts[n-1]){

	 inc=prices[n-1]+knapsack(wts,prices,n-1,weight-wts[n-1]);
}
//excluding a current item
	 exc=0+knapsack(wts,prices,n-1,weight);
	 return max(inc,exc);
	 
}

// by bottom up  dp
// in this you have to create a two d dp table for memorization ::-
//it is a very interesting things
int bottomupdp(int wts[],int prices[],int n,int W){
	int dp[100][100]={0};
	
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if(i==0||w==0){
			//recursion base case here used as initilization
	dp[i][w]=0;
		}
		int inc=0,exc=0;
		if(w>=wts[i-1])
		inc=prices[i-1]+dp[i-1][w-wts[i-1]];
		exc=0+dp[i-1][w];
		dp[i][w]=max(inc,exc);
		
			}
	}
	
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
cout<<dp[i][w]<<"  ";	
}cout<<endl;
}
	
	return dp[n][W];
}

int main(){

    int wts[] = {2, 2, 3, 1};
    int prices[ ] = {5,20,20,10};

    int n = 4;
    int w = 5;
  int maxprofit=knapsack(wts,prices,n,w);
	cout<<maxprofit<<endl<<endl;
	
//cout<<bottomupdp(wts,prices,n,w);
cout<<endl<<endl;


}
