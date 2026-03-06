class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n=nums.size();
        int i=0;
        while(i<n){
            int j=i+1;
            ans.push_back(nums[j]);
            ans.push_back(nums[i]);
            i+=2;
            
        }
        return ans;
    }
};