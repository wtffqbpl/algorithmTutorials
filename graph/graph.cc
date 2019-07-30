#include "graph.h"

template <typename T>
void Graph<T>::DFS()
{
    shared_ptr<vector<bool>> visited;
    visited->resize(n);

    for (size_t idx = 0; idx < n; ++idx) {
        visited[idx] = false;
    }

    for (size_t idx = 0; idx < n; ++idx) {
        if (!visited[idx]) {
            DFS(idx, visited);
        }
    }
}

template <typename T>
void Graph<T>::DFS(int idx, shared_ptr<vector<bool>> visited)
{
    visited[idx] = true;

    cout << idx << " ";
    for (ENode<T>* w = enodes[v]; w; w = w->next) {
        if (!visited[w->adjvex]) {
            DFS(w->adjvex, visited);
        }
    }
}

template <typename T>
void Graph<T>::BFS()
{
    shared_ptr<vector<bool>> visited;
    visited->resize(n);

    for (size_t idx = 0; idx < count; ++idx) {
        visited[idx] = false;
    }

    for (size_t idx = 0; idx < count; ++idx) {
        if (!visited[idx]) {
            BFS(j, visited);
        }
    }
}

template <typename T>
void Graph<T>::BFS(int idx, shared_ptr<vector<bool>> visited)
{
    visited[idx] = true;
    cout << idx << " ";
    queue<int> myQueue;
    myQueue.push(idx);

    int s;
    while (!myQueue.empty()) {
        s = myQueue.front();
        myQueue.pop();

        for (auto w = enodes[s]; w; w = w->next) {
            if (!visited[w->adjVex]) {
                visited[w->adjVex] = true;
                cout << w->adjVex << " ";
                myQueue.push(w->adjVex);
            }
        }
    }
}