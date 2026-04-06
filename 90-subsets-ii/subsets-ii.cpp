class Solution {
public:
    void solve(vector<int>& nums,int i,int n,vector<int>&temp,vector<vector<int>>& res){
        if(i==n){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums,i+1,n,temp,res);
        temp.pop_back();
        int j=i+1;
        while(j<n && nums[i]==nums[j]){
            j++;
        }
        solve(nums,j,n,temp,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> temp;
        vector<vector<int>> res;
        solve(nums,0,n,temp,res);
        return res;
    }
};