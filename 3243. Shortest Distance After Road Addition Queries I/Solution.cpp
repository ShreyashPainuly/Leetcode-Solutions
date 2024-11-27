// You are given an integer n and a 2D integer array queries.
// There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.
// queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.
// Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

// Example 1:
// Input: n = 5, queries = [[2,4],[0,2],[0,4]]
// Output: [3,2,1]
// Explanation:
// After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.
// After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.
// After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.

// Example 2:
// Input: n = 4, queries = [[0,3],[0,2]]
// Output: [1,1]
// Explanation:
// After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.
// After the addition of the road from 0 to 2, the length of the shortest path remains 1.

//Approach-1 : Using Dijkstra's Algorothm - Assuming each edge weight is 1
//T.C : O(q * (V+E)) , V = number of vertices and E = number of edges
//S.C : O(V+E)

class Solution {
public:
    #define P pair<int, int>
    unordered_map<int, vector<P>> adj;

    int dijkstra(int n) {
        vector<int> result(n, INT_MAX);
        result[0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int d    = pq.top().first;    // Distance of current node
            int node = pq.top().second; // Current node
            pq.pop();
            
            if (node == n - 1)
                return result[n - 1];
            
            if (d > result[node])
                continue;

            for (P &p : adj[node]) {
                int adjNode = p.first;
                int dist    = p.second;
                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
        return result[n - 1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;

        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back({i + 1, 1});
        }

        for (auto query : queries) {
            int u = query[0];
            int v = query[1];
            adj[u].push_back({v, 1});
            int d = dijkstra(n);
            result.push_back(d);
        }

        return result;
    }
};

//Approach-2 : Using BFS (edges are unweighted
//T.C : O(q * (E log(V)) , V = number of vertices and E = number of edges
//S.C : O(V+E)

class Solution {
public:
    unordered_map<int, vector<int>> adj;

    int bfs(int n) {
        queue<int> que;
        que.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;

        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int node = que.front();
                que.pop();

                if (node == n - 1) {
                    return level; // Found the destination node
                }

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        que.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
         adj.clear();

        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        int k = queries.size();
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            adj[queries[i][0]].push_back(queries[i][1]);
            res[i] = bfs(n);
        }
        return res;
    }
};
