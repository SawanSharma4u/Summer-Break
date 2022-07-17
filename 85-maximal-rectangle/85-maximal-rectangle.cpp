class Solution {
    vector<int> nextSmallerChar(vector<int> &arr){
        stack<int> s;
        s.push(-1);
        vector<int> ans(arr.size());
        for(int i = arr.size()-1; i >= 0; i--){
            while(s.top()!=-1 && arr[i] <= arr[s.top()]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerChar(vector<int> &arr){
        stack<int> s;
        s.push(-1);
        vector<int> ans(arr.size());
        for(int i = 0; i < arr.size(); i++){
            while(s.top()!=-1 && arr[i] <= arr[s.top()]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largetAreaOfHistogram(vector<int> &arr){
        vector<int> next = nextSmallerChar(arr);
        vector<int> prev = prevSmallerChar(arr);
        int n = arr.size();
        int area = INT_MIN;
        for(int i = 0; i < n; i++){
            if(next[i]==-1){
                next[i] = n;
            }
            area = max(area, arr[i]*(next[i]-prev[i]-1));
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> arr;
        for(int i = 0; i < matrix[0].size(); i++){
            arr.push_back(matrix[0][i]-'0');
        }
        int area = largetAreaOfHistogram(arr);
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j]!='0'){
                    arr[j]++;
                }
                else{
                    arr[j] = 0;
                }
            }
            area = max(area, largetAreaOfHistogram(arr));
        }
        return area;
    }
};