class Solution {
public:

    int solve(int sum, vector<int>& nums, int i, vector<vector<int>>& dp){

        if(i == nums.size()){
            return (sum == 0);
        }

        if(dp[i][sum] != -1){
            return dp[i][sum];
        }

        int take = 0;

        if(sum >= nums[i]){
            take = solve(sum - nums[i], nums, i + 1, dp);
        }

        int nottake = solve(sum, nums, i + 1, dp);

        return dp[i][sum] = take + nottake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int total_sum = 0;

        for(int x : nums){
            total_sum += x;
        }

        if((total_sum + target) % 2 != 0 || abs(target) > total_sum){
            return 0;
        }

        int sum1 = (total_sum + target) / 2;

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(sum1 + 1, -1));

        return solve(sum1, nums, 0, dp);
    }
};