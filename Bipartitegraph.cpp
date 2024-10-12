#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col;
        for (auto neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, !col, color, graph)) {
                    return false;
                }
            } 
            else if (color[neighbor] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if (solution.isBipartite(graph1)) {
        cout << "Graph 1 is Bipartite" << endl;
    } else {
        cout << "Graph 1 is not Bipartite" << endl;
    }

    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    if (solution.isBipartite(graph2)) {
        cout << "Graph 2 is Bipartite" << endl;
    } else {
        cout << "Graph 2 is not Bipartite" << endl;
    }

    return 0;
}
