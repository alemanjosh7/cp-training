int dfs(int u, int p = -1) {
    sz[u] = 1;
    each(v, adj[u]) {
        if (v != p && !r[v]) {
            sz[u] += dfs(v, u);
        }
    }
    return sz[u];
}

int get_centroid(int u, int sz_subtree, int p = -1) {
    each(v, adj[u]) {
        if (v != p && !r[v]) {
            if (sz[v] * 2 > sz_subtree) {
                return get_centroid(v, sz_subtree, u);
            }
        }
    }
    return u;
}

void centroid(int u = 0) {
    u = get_centroid(u, dfs(u));
    r[u] = 1;
    each(v, adj[u]) {
        if (!r[v]) centroid(v);
    }
}