class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<int>indegree(V,0);
        queue<int> q;
        vector<int> topo;

    //first creating a directed graph adj list
        vector<int> adjLst[numCourses];

      
        for (auto it : prerequisites) {
            adjLst[it[1]].push_back(it[0]);
        }
        //indegree intialize krna h

        for(int i=0;i<V;i++){
            for(auto it: adjLst[i]){
                indegree[it]++;
            }
        }

        //put all the nodes with indegree 0
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
       //bfs algo

       while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adjLst[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
       }

       //conditions

       if(topo.size()==V) return topo;
       else return vector<int>();

    }
};