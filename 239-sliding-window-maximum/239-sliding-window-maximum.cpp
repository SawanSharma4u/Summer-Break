class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++){
            pq.push(make_pair(nums[i], i));
        }
        vector<int> op;
        for(int i = k; i < nums.size(); i++){
            pair<int, int> top;
            while(pq.size() >= k){
                top = pq.top();
                if(i - top.second > k) pq.pop();
                else break;
            }
            op.push_back(top.first);
            pq.push(make_pair(nums[i], i));
        }
        pair<int, int> top;
        while(pq.size() >= k){
            top = pq.top();
            if(nums.size() - top.second > k) pq.pop();
            else break;
        }
        op.push_back(top.first);
        return op;
    }
};