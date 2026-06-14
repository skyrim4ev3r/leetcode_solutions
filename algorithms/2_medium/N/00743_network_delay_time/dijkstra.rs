use std::collections::{BinaryHeap, HashMap};
use std::cmp::Reverse;

impl Solution {
    pub fn network_delay_time(times: Vec<Vec<i32>>, n: i32, k: i32) -> i32 {
        debug_assert!(n > 0 && k > 0 && k <= n);
        let mut min_heap: BinaryHeap::<Reverse::<(i32, i32)>> = BinaryHeap::with_capacity(2 * n as usize);
        let mut adj = vec![Vec::<(i32, i32)>::default(); n as usize + 1];
        for t in times {
            adj[t[0] as usize].push((t[1], t[2]));
        }
        let mut costs: Vec::<i32> = vec![i32::MAX; n as usize + 1];
        min_heap.push(Reverse((0, k)));
        
        while let Some(Reverse((path_cost, node))) = min_heap.pop() {
            if path_cost > costs[node as usize] {
                continue;
            }
            
            costs[node as usize] = path_cost;
            
            for &(other_node, edge_cost) in adj[node as usize].iter() {
                let new_path_cost = edge_cost + path_cost;
                if new_path_cost < costs[other_node as usize] {
                    costs[other_node as usize] = new_path_cost;
                    min_heap.push(Reverse((new_path_cost, other_node)));
                }
            }
        }
        
        let max_dist = *costs[1..].into_iter().max().unwrap();
        
        if max_dist == i32::MAX { -1 } else { max_dist }
    }
}
