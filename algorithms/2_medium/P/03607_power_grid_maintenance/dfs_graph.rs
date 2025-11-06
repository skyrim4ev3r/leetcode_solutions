use std::collections::BTreeSet;

impl Solution {
    fn dfs(
        pool: &mut BTreeSet<i32>,
        is_visited: &mut Vec<bool>,
        pool_id: usize,
        node_id: usize,
        al: &Vec<Vec<i32>>,
        node_id_to_pool_id: &mut Vec<usize>,
    ) {
        if is_visited[node_id] {
            return;
        }

        is_visited[node_id] = true;
        node_id_to_pool_id[node_id] = pool_id;
        pool.insert(node_id as i32);

        for other in al[node_id].iter() {
            Self::dfs(pool, is_visited, pool_id, (*other) as usize, al, node_id_to_pool_id);
        }
    }

    pub fn process_queries(c: i32, connections: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut c_usize = c as usize + 1;
        let mut al = vec![Vec::<i32>::new(); c_usize];

        for connection in connections.into_iter() {
            al[connection[0] as usize].push(connection[1]);
            al[connection[1] as usize].push(connection[0]);
        }

        let mut is_visited = vec![false; c_usize];
        let mut is_online = vec![true; c_usize];
        let mut node_id_to_pool_id = vec![0_usize; c_usize];
        let mut pools: Vec<BTreeSet<i32>> = Vec::new();
        let mut res: Vec<i32> = Vec::new();

        for i in 1..c_usize {
            if !is_visited[i] {
                let mut pool: BTreeSet<i32> = BTreeSet::new();
                let pool_id = pools.len();
                Self::dfs(&mut pool, &mut is_visited, pool_id, i, &al, &mut node_id_to_pool_id);
                pools.push(pool);
            }
        }

        for query in queries.into_iter() {
            let curr_node_id = query[1] as usize;
            let curr_node = query[1];

            if query[0] == 2 {
                is_online[curr_node_id] = false;
                pools[node_id_to_pool_id[curr_node_id]].remove(&curr_node);
            } else {
                if is_online[curr_node_id] {
                    res.push(curr_node);
                } else {
                    if let Some(val) = pools[node_id_to_pool_id[curr_node_id]].iter().next() {
                        res.push(*val);
                    } else {
                        res.push(-1);
                    }
                }
            }
        }

        res
    }
}
