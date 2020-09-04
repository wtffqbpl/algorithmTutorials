#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <memory>
#include <string.h>
#include <climits>

using namespace std;

#define INVALID (-1)
#define VALID   (0)

// the Edge
template <typename T>
struct  ENode {
    int vertex;
    int adjvex;
    T weight;
    ENode<T>* next;

    ENode() : next(nullptr) {}
    ENode(int _vertex, int adjvertex, T w, ENode<T>* nextArc) :
            vertex(_vertex),
            adjvex(adjvertex),
            weight(w),
            next(nextArc) {}

    operator T() const { return weight;}

    bool operator< (const ENode<T>& rhs) const {
        return this->weight > rhs.weight;
    }
};

template <typename T>
class Graph {
private:
    ENode<T>** enodes;
    int n;                              // number of vertex.
    int edges;                      // number of edge.
    int connectedCount;    // connection number.
    int* id;                            // 
    vector<int>* tarjanConnection;      // tarjan
    int connectedCountForTarjan;
    bool hasCycle;
    stack<int> cycle;
    stack<int> reversePost;
    UnionFind* uf;

    // void DFS(int v, bool* visited);
    // void BFS(int v, bool* visited);
    void DFS(int idx, shared_ptr<vector<bool>> visited);
    void BFS(int idx, shared_ptr<vector<bool>> visited);

    void DFSForCycle(int v, bool* visited, bool* onstack, int* edgeTo);
    void DFSForReversePost(int v, bool* visited);
    void DFSForConnection(int v, bool* visited);
    void TarjanForConnection(int u, bool* visited, int* DFN, int* low,
        stack<int>* tarjanStack, bool* inStack, int& index);
    
    void ClearCycle();
    void ClearReversePost();
    void CalInDegree(int* inDegree);

    void Prim(int v0, int* nearest, T* lowcost);
    void Kruskal(priority_queue<ENode<T>>& pq);
    void Dijkastra(int v0, int* path, T* curShortLen);
    int FinMinLen(T* curShortLen, bool* mark);
    /* data */
public:
    Graph(int mSize);
    ~Graph();
    bool Exist(int u, int v) const;
    bool Insert(int u, int v, T w);
    bool Remove(int u, int v);
    Graph<T> Reverse();
    void DFS();
    void BFS();
    
    bool HasCycle();
    stack<int> GetCycle();
    void CalReversePost();
    void TopoSort();
    void TopoSortByDFS();
    stack<int> getReversePost();
    void CalculateConnection();
    int GetConnectedCount();
    void ShowConnection();
    void tarjanForConnection();

    void Prim(int v0);
    void Kruskal();
    void Dijkstra(int v0);
    void Floyd();
    T GetWeight(int u, int v);
};
