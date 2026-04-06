class Solution {
public:
    void solve(vector<int>& nums,int idx,int n,vector<vector<int>>&res){
        if(idx==n){
            res.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[idx],nums[i]);
            solve(nums,idx+1,n,res);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        solve(nums,0,n,res);
        return res;
    }
};