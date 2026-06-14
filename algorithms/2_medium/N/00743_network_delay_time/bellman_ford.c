int networkDelayTime(int** times, int times_len, int* times_cols_len, int n, int k)
{
    assert(times != NULL && times_cols_len != NULL && times_len > 0 && 
           times_cols_len[0] == 3 && n > 0 && k > 0 && k <= n && n < INT_MAX);

    int* dist = malloc((size_t)(n + 1) * sizeof(*dist));
    assert(dist != NULL);
    for (int i = 0; i <= n; i += 1) {
        dist[i] = INT_MAX;
    }
    dist[k] = 0;

    for (int _steps = 0; _steps < n; _steps += 1) {
        bool is_updated = false;

        for (int i = 0; i < times_len; i += 1) {
            const int u = times[i][0];
            const int v = times[i][1];
            const int w = times[i][2];
            assert(u > 0 && v > 0 && u <= n && v <= n && w >= 0);

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                is_updated = true;
            }
        }

        if (!is_updated) { 
            break;
        }
    }

    int max_dist = 0;
    for (int i = 1; i <= n; i += 1) {
        if (dist[i] == INT_MAX) {
            max_dist = -1;
            goto cleanup;
        }

        if (dist[i] > max_dist) { 
            max_dist = dist[i];
        }
    }

cleanup:
    free(dist);
    return max_dist;
}
