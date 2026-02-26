class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int zero=0;
        int ans=0;
        for(int a=0;a<n;a++){
            if(nums[a]==0){
                zero++;
            }}
            if(zero<k){
                return n;
            }
        
        while(j<n){
            sum+=nums[j];
            if(j-i+1-sum >k){
                sum-=nums[i];
                i++;
            }
            else if(j-i+1-sum ==k){
                ans =max(j-i+1,ans);
                }
                j++;
                
            }
            return ans;
        }
    
};