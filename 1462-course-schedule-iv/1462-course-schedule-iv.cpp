class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, list<int>> adj;
        vector<int> indegree(n);
        for(auto i : prerequisites){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        int m = queries.size();
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // int cnt = 0;
        // while(!q.empty()){
        //     int front = q.front();
        //     q.pop();
        //     cnt++;
        //     for(auto i : adj[front]){
        //         indegree[i]--;
        //         if(indegree[i]==0){
        //             q.push(i);
        //         }
        //     }
        // }
        // if(cnt!=n){
        //     vector<bool> ans(m, false);
        //     return ans;
        // }
        vector<bool> ans;
        vector<vector<int>> dp(n,vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            int src = queries[i][0];
            int des = queries[i][1];
            if(dp[src][des]!=-1){
                if(dp[src][des]==1) ans.push_back(true);
                else ans.push_back(false);
            }
            else{
                queue<int> q;
                q.push(src);
                vector<bool> visited(n, false);
                visited[src] = true;
                while(!q.empty()){
                    int front = q.front();
                    dp[src][front] = 1;
                    if(front==des){
                        ans.push_back(true);
                        break;
                    }
                    q.pop();
                    for(auto j : adj[front]){
                        if(!visited[j]){
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
                if(ans.size()==i){
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};