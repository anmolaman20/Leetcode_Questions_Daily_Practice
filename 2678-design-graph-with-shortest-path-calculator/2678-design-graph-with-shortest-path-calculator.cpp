class Graph {
public:
    int n;
    unordered_map<int,vector<pair<int,int>>> gr;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for(auto& it : edges){
            gr[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        gr[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dis(n,INT_MAX);
        dis[node1] = 0;
        pq.push({0,node1});

        while(!pq.empty()){
            int node = pq.top().second;
            int curDis = pq.top().first;
            pq.pop();


            if(curDis > dis[node]) continue;
            if(node==node2) return curDis;

            for(auto& it : gr[node]){
                if(dis[it.first] > curDis + it.second){
                    int newDis = curDis + it.second;
                    dis[it.first] = newDis;
                    pq.push({newDis,it.first});
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