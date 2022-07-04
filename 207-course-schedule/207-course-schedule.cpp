class Solution {
    // bool dfs(unordered_map<int, list<int>>& adj, int src, vector<bool>& visited, vector<bool>& dfsvisited){
    //     visited[src] = true;
    //     dfsvisited[src] = true;
    //     for(auto i : adj[src]){
    //         if(!visited[i]){
    //             bool ans = dfs(adj, i, visited, dfsvisited);
    //             if(ans) return true;
    //          }
    //         else if(dfsvisited[i]){
    //             return true;
    //         }
    //     }
    //     dfsvisited[src] = false;
    //     return false;
    // }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for(auto i : prerequisites){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(n, false);
        //vector<bool> dfsvisited(n, false);
        vector<int> indegree(n, 0);
        for(auto i : adj){
            for(auto j : i.second){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cnt++;
            for(auto i : adj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(cnt == n) return true;
        return false;
        // for(int i = 0; i < n; i++){
        //     if(!visited[i]){
        //         bool ans = dfs(adj, i, visited, dfsvisited);
        //         if(ans == true) return false;
        //     }
        // }
        // return true;
    }
};