#include<iostream>
using namespace std;
int minicoinneeded(int n,int a[],int k){
	if(n==0){
	return 0;
	}
	if(n<0){
	return INT_MAX;
	}
	int ans=INT_MAX;
	for(int i=0;i<k;i++){
	int smallerans=min(ans,minicoinneeded(n-a[i],a,k));
 if(smallerans!=INT_MAX){
 	ans=min(ans,smallerans+1);//minimum of smaller ans and jo ans us level par chal raha he
	}
 }
	return ans;
	}
	
	
// Bottom Up Dp
int coinsNeededDP(int coins[],int amount,int n){
    int *dp = new int[amount+1];

    for(int i=0;i<=amount;i++){
        dp[i] = INT_MAX;
    }



    dp[0] = 0;
    for(int rupay=1; rupay<=amount;rupay++){

        // Iterate Over Coins
        for(int i=0;i<n;i++){

            if(coins[i]<=rupay){

                int smallerAns = dp[rupay-coins[i]];
                if(smallerAns!=INT_MAX){
                    dp[rupay] = min(dp[rupay],smallerAns + 1);
                }

            }

        }
    }


    return dp[amount];

}
	
int main(){
	int n=15;
	int a[3]={1,7,10};
	//it return int max when it is not possible to make coins 
	cout<<minicoinneeded(n,a,3);
}
