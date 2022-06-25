class Solution {
    unordered_map<int, int> points;
    unordered_map<int, int> cache;
    int maxPoint(int num){
        if(num==0) return 0;
        if(num==1) return points[1];
        if(cache.count(num)) return cache[num];
        return cache[num] = max(maxPoint(num-1), maxPoint(num-2)+points[num]);
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = 0;
        for(int i = 0; i < nums.size(); i++){
            points[nums[i]] += nums[i];
            if(maxNumber < nums[i]){
                maxNumber = nums[i];
            }
        }
        return maxPoint(maxNumber);
    }
};