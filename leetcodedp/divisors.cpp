class Solution {
public:
    bool divisorGame(int n) {
        #define ll int
        bool dp[n+1];
        dp[1]=0;
        dp[0]=0;
        for(ll i=2;i<=n;i++){
                      dp[i]=0;
            for(ll j=1;j<i;j++){
                if(i%j==0){
                    if(dp[i-j]==0){
                      dp[i]=1;
                        break;
                    }
                }
            }
        }
        
        
        
        return  dp[n];
        
    }
};
