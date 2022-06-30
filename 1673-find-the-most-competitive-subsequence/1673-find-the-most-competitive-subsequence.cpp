class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(ans.size()==0){
                ans.push_back(nums[i]);
            }
            else{
                if(ans[ans.size()-1] < nums[i] && ans.size() < k){
                    ans.push_back(nums[i]);
                }
                else{
                    while(ans.size()>0 && ans.size() + nums.size() - i > k && ans[ans.size()-1] > nums[i]){
                        ans.pop_back();
                    }
                    if(ans.size() < k) ans.push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};