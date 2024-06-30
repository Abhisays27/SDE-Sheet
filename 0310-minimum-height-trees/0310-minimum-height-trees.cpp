class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
         if (n == 1) return {0};

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(n,0);
        queue<int> q;


        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }

        int rnodes = n;

        while(rnodes>2){
            int size = q.size();
            rnodes-=q.size();

            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();

                for(auto it: adj[node]){
                    indegree[it]--;
                    if(indegree[it]==1){
                        q.push(it);
                    }
                }
            }
        }

        vector<int> ans;

       while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
       }

        return ans;
        
    }
};