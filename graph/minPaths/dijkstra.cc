#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int graph[N][N];     // 用邻接矩阵来存储图
int dist[N];         // 用来保存从start 点到该点的最短距离
bool determined[N];  // 用来保存该点保存的距离是否已经是最短距离了。

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;    // start点距离自己本身为0

    for (int i = 0;  i < n; ++i) {

        // 这几行代码是用来判断当前未最终确定最短距离的点中，距离start点最近的点,
        // 1. 通过determined[j]来排除已经最终确定最短距离的点
        // 2. 由于初始化起始点到每个点的距离为 INF，因此访问过的点距离肯定比INF小，
        //    所以可以遍历所有的点来找到离start点距离最近的点。
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (!determined[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        // 找到距离最近的点之后，该点就可以认为距离已经确定了
        determined[t] = true;

        // 用该点更新所有其他点的距离。
        // 与上面类似，由于已经决定过最短距离的点的距离肯定比通过当前点到那些点的距离，
        // 因此用来遍历那些点肯定是不会改变那些点的最短距离，
        // 同时，对于连通的点，如果还未访问，那么通过该点走过去的距离肯定比INF距离小，
        // 对于这些点，我们就可以把从start点到该点的距离更新为计算的距离。
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[t] + graph[t][j]);
        }
    }

    // 这里进行判断，如果距离仍然为INF，那么我们认为从start点无法到达该点。
    return dist[n] == INF ? -1 : dist[n];
}

int main()
{
    cin >> n >> m;
    memset(graph, 0x3f, sizeof(graph));

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    cout << dijkstra() << endl;

    return 0;
}
