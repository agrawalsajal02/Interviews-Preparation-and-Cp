#include<iostream>
using namespace std;
//unbounded knapsack :- one item can be choosem more than one time
int bottomupdpun(int wts[],int prices[],int n,int W){
	int dp[100][100]={0};
	
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if(i==0||w==0){
			//recursion base case here used as initilization
	dp[i][w]=0;
		}
		int inc=0,exc=0;
		if(w>=wts[i-1])
		inc=prices[i-1]+dp[i][w-wts[i-1]];
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
    int prices[] ={5,20,100,30};

    int n = 4;
    int w = 5;
cout<<endl<<endl;
cout<<bottomupdpun(wts,prices,n,w);


}
