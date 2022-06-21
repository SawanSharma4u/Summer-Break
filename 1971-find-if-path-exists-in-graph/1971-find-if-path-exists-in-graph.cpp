class Solution {
    int findparent(int v, vector<int>& parents){
        if(parents[v]==v) return v;
        return findparent(parents[v], parents);
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<int> parents(n);
        for(int i = 0; i < n; i++){
            parents[i] = i;
        }
        bool ans = false;
        int i = 0;
        while(!ans && i < edges.size()){
            int srcParent = findparent(edges[i][0], parents);
            int desParent = findparent(edges[i][1], parents);
            parents[srcParent] = desParent;
            srcParent = findparent(source, parents);
            desParent = findparent(destination, parents);
            if(srcParent == desParent){
                ans = true;
            }
            i++;
        }
        return ans;
    }
};