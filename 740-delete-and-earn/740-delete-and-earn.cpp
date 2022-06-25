class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = 0;
        unordered_map<int, int> points;
        for(int i = 0; i < nums.size(); i++){
            points[nums[i]] += nums[i];
            if(maxNumber < nums[i]){
                maxNumber = nums[i];
            }
        }
        vector<int> maxPoint(maxNumber+1, 0);
        maxPoint[1] = points[1];
        for(int i = 2; i <= maxNumber; i++){
            maxPoint[i] = max(maxPoint[i-1], maxPoint[i-2] + points[i]);
        }
        return maxPoint[maxNumber];
    }
};