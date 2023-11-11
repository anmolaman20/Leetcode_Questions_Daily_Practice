class Graph {
public:
    int n;
    unordered_map<int,vector<pair<int,int>>> gr;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for(auto& edge : edges){
            gr[edge[0]].push_back({edge[1],edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        gr[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);

        pq.push({0,node1});

        while(!pq.empty()){
            int curDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(curDist > dist[node]) continue;
            if(node==node2) return curDist;

            for(auto it : gr[node]){
                if(dist[it.first] > curDist + it.second ){
                    int nwDist = curDist + it.second;
                    dist[it.first] = nwDist;

                    pq.push({nwDist,it.first});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */