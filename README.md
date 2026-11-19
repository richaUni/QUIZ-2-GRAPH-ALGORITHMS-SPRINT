# QUIZ-2-GRAPH-ALGORITHMS-SPRINT
Quiz 2
Problem 1 : LeetCode-1584. Min Cost to Connect All Points
We used Kruskal algorithm with a struct of Edge :   struct Edge {
        int u, v, weight;
    };
Basically sort the the edges with nondecreasing order, then push them into the vector if that edge is not in the vector already, and while that happen we add the weight into total cost.

Problem 2
