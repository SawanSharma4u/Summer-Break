class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==0){
                cnt--;
            }
            else cnt++;
            if(mp.count(cnt)){
                ans = max(ans, i-mp[cnt]);
            }
            else mp[cnt] = i;
        }
        return ans;
    }
};