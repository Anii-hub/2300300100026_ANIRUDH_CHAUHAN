class Solution {
public:
    void solve(vector<int>&candidates,int target,int i,int n,vector<int>&temp,vector<vector<int>>&res){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(i==n){
            return ;
        }
      
      if(target>=candidates[i]) { 
        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],i+1,n,temp,res);
        temp.pop_back();
        }
        int j=i+1;
        while(j<n && candidates[j]==candidates[i]){
            j++;
        }
        solve(candidates,target,j,n,temp,res);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>> res;
        solve(candidates,target,0,n,temp,res);
        return res;
    }
};