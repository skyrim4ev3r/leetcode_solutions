class Solution:
    def dfs(self, pool, is_visited, pool_id, node_id, al, node_id_to_pool_id):
        if is_visited[node_id]:
            return

        is_visited[node_id] = True
        node_id_to_pool_id[node_id] = pool_id
        pool.add(node_id)

        for other in al[node_id]:
            self.dfs(pool, is_visited, pool_id, other, al, node_id_to_pool_id)

    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        c += 1
        al = [[] for _ in range(c)]

        for connection in connections:
            al[connection[0]].append(connection[1])
            al[connection[1]].append(connection[0])

        is_visited = [False] * c
        is_online = [True] * c
        node_id_to_pool_id = [0] * c
        pools = []
        res = []

        for i in range(1, c):
            if not is_visited[i]:
                pool = SortedSet()
                pool_id = len(pools)
                self.dfs(pool, is_visited, pool_id, i, al, node_id_to_pool_id)
                pools.append(pool)

        for query in queries:
            curr_node_id = query[1]

            if query[0] == 2:
                is_online[curr_node_id] = False
                if curr_node_id in  pools[node_id_to_pool_id[curr_node_id]]:
                    pools[node_id_to_pool_id[curr_node_id]].remove(curr_node_id)
            else:
                if is_online[curr_node_id]:
                    res.append(curr_node_id)
                else:
                    if pools[node_id_to_pool_id[curr_node_id]]:
                        res.append(pools[node_id_to_pool_id[curr_node_id]][0])
                    else:
                        res.append(-1)

        return res
