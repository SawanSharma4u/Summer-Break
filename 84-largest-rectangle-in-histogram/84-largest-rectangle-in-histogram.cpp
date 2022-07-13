class Solution {
    void findNextGreaterElement(vector<int>& heights, vector<int>& next){
        stack<int> s;
        s.push(-1);
        int n = heights.size();
        for(int i = n-1; i >= 0; i--){
            while(s.top()!=-1 && heights[s.top()]  >= heights[i]){
                s.pop();
            }
            next[i] = s.top();
            s.push(i);
        }
    }
    void findNextPrevElement(vector<int>& heights, vector<int>& prev){
        stack<int> s;
        s.push(-1);
        int n = heights.size();
        for(int i = 0; i < n; i++){
            while(s.top()!=-1 && heights[s.top()]  >= heights[i]){
                s.pop();
            }
            prev[i] = s.top();
            s.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        findNextGreaterElement(heights, next);
        vector<int> prev(n);
        findNextPrevElement(heights, prev);
        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++){
            if(next[i]==-1){
                next[i] = n;
            }
            int temp = next[i]-prev[i]-1;
            maxArea = max(maxArea, temp*heights[i]);
        }
        return maxArea;
    }
};