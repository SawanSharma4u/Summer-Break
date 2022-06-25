class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> points;
        vector<int> list;
        for(int i = 0; i < nums.size(); i++){
            if(points.count(nums[i])==0){
                list.push_back(nums[i]);
            }
            points[nums[i]] += nums[i];
        }
        sort(list.begin(), list.end());
        int a = 0;
        int b = points[list[0]];
        for(int i = 1; i < list.size(); i++){
            int temp;
            if(list[i]-list[i-1]==1){
                temp = max(b, a + points[list[i]]);
            }
            else{
                temp = b + points[list[i]];
            }
            a = b;
            b = temp;
        }
        return b;
    }
};