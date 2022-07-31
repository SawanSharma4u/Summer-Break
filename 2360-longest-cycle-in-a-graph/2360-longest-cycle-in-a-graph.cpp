class Solution {
    int find(vector<int>& visited, vector<int>& edges, int src){
        queue<int> q;
        while(src!=-1 && visited[src]==0){
            q.push(src);
            visited[src] = -1;
            src = edges[src];
        }
        int ans = -1;
        if(src!=-1){
            ans = visited[src];
        }
        cout<<q.size()<<" ";
        while(!q.empty() && src!=-1){
            int front = q.front();
            if(front==src){
                cout<<src<<" ";
                ans=q.size();
            }
            q.pop();
            if(ans!=-1){
                visited[front] = ans;
            }
        }
        return ans;
    }
    
public:
    int longestCycle(vector<int>& edges) {
        vector<int> visited(edges.size(), 0);
        int ans = 0;
        for(int i = 0; i < edges.size(); i++){
            if(visited[i]==0){
                int temp = find(visited, edges, i);
                cout<<temp<<endl;
                ans = max(temp, ans);
            }
        }
        return ans==0?-1:ans;;
    }
};