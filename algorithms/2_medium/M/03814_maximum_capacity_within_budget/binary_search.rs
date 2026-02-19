use std::cmp::Ordering;

impl Solution {

    #[inline(always)]
    fn create_zip_costs_capacity(costs: Vec<i32>, capacity: Vec<i32>, budget: i32) -> Vec<(i32, i32)> {
        let mut arr = costs.into_iter()
                               .zip(capacity.into_iter())
                               .filter(|x| x.0 < budget)
                               .collect::<Vec<_>>();

        arr.sort_unstable_by_key(|x| x.0);

        arr
    }

    #[inline(always)]
    fn create_prefix_max_capacity(arr: &Vec<(i32, i32)>, len: usize) -> Vec<i32> {
        let mut prefix_max_capacity = vec![0_i32; len];
        prefix_max_capacity[0] = arr[0].1;

        for i in 1..len {
            prefix_max_capacity[i] = prefix_max_capacity[i - 1].max(arr[i].1);
        }

        prefix_max_capacity
    }

    pub fn max_capacity(costs: Vec<i32>, capacity: Vec<i32>, budget: i32) -> i32 {
        let arr = Self::create_zip_costs_capacity(costs, capacity, budget);
        let len = arr.len();

        if len == 0 {
            return 0;
        }

        let mut prefix_max_capacity = Self::create_prefix_max_capacity(&arr, len);
        let mut max = 0_i32;

        for i in 0..len {
            let other_cost = budget - arr[i].0 - 1;
            let upper_bound_pos = arr[0..i].binary_search_by(|x| match x.0.cmp(&other_cost) {
                Ordering::Less => Ordering::Less,
                Ordering::Equal => Ordering::Less,
                Ordering::Greater => Ordering::Greater,
            }).unwrap_or_else(|x| x);

            if upper_bound_pos > 0 {
                max = max.max(prefix_max_capacity[upper_bound_pos - 1] + arr[i].1);
            } else {
                max = max.max(arr[i].1);
            } 
        }

        max
    }
}
