class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prev;
        prev.push_back(0);
        int n = height.size();
        vector<int> next(n);
        int temp = height[0];
        for(int i = 0; i < n-1; i++){
            temp = max(height[i], temp);
            prev.push_back(temp);
        }
        next[n-1] = 0;
        temp = height[n-1];
        for(int i = n-1; i > 0; i--){
            temp = max(height[i], temp);
            next[i-1] = temp;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += max(0, min(next[i],prev[i])-height[i]);
        }
        return ans;
    }
};