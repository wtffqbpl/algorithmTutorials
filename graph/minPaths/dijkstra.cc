#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int graph[N][N];
int dist[N];
bool determined[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    for (int i = 0;  i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (!determined[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        determined[t] = true;

        // update other nodes which connected with node t.
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[t] + graph[t][j]);
        }
    }

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
