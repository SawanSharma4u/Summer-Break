class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        vector<int> indegree(n, 0);
        for(auto i : prerequisites){
            int u = i[1];
            int v = i[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        //vector<bool> dfsvisited(n, false);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto i : adj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()==n){
            return ans;
        }
        vector<int> arr;
        return arr;
    }
};