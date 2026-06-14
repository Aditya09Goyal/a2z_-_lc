class Solution {
public:
    int solve(int day ,int canBuy ,  vector<vector<long>>&dp , vector<int>&prices ) {
        if(day==prices.size()) return 0 ; 
        if(dp[day][canBuy]!=-1) return dp[day][canBuy] ; 

        if(canBuy){
            long long buy = -prices[day] + solve(day+1,0,dp,prices); 
            long long skip = solve(day+1,1,dp,prices) ; 
            return dp[day][canBuy] = max(buy,skip) ; 
        }
        else{
            long long hold = solve(day+1,0,dp,prices) ;
            long long sell = prices[day]  + solve(day+1,1,dp,prices) ; 
            return dp[day][canBuy] = max(hold,sell) ; 
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        vector<vector<long>>dp(n,vector<long>(2,-1)) ; 
        return solve(0,1,dp,prices) ;  

    }
};