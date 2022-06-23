vector<pi> adj[MXN];
vl dist;
int n;
void dijkstra(int u) {
    dist.assign(n, INF);
    priority_queue<pi, vpi, greater<pi> > q;
    dist[u] = 0;
    q.push({ 0, u });
    while (!q.empty()) {
        u = q.top().s; ll w = q.top().f; q.pop();
        if (dist[u] != w) continue;
        each(v, adj[u]) {
            if (w + v.s < dist[v.f]) {
                dist[v.f] = w + v.s;
                q.push({ dist[v.f], v.f })
            }
        }
    }
}