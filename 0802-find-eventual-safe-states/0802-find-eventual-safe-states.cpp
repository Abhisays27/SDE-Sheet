class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adjList[V]; // Reverse graph
        vector<int> indegree(V, 0);
        queue<int> q;
        vector<int> safeNodes;

        // Reverse the graph and compute the indegree
        for (int i = 0; i < V; ++i) {
            for (int neighbor : graph[i]) {
                adjList[neighbor].push_back(i);
                indegree[i]++;
            }
        }

        // Put all the nodes with indegree 0 in the queue
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : adjList[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Sort the safe nodes
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
