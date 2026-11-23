class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
// We will start by thinking the distances are very large
// Large number since we don't know the path yet
    vector<vector<int>> distance(n, vector<int>(n, 1000000));
    for (int i = 0; i < n; i++){
        distance[i][i] = 0;
    }

    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        distance[u][v] = w;
        distance[v][u] = w;

    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (distance[i][k] + distance[k][j] < distance[i][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    int answer = -1;
    int smallestCount = n;
    for (int i = 0; i < n; i++){
        int count = 0;

        for (int j = 0; j < n; j++){
            if(i != j && distance[i][j] <= distanceThreshold){
               count++;
            }
        }

        if (count <= smallestCount){
            smallestCount = count;
            answer = i;
        }
    }
    return answer;
  }

};
