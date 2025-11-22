impl Solution {
    pub fn maximum_units(mut box_types: Vec<Vec<i32>>, mut truck_size: i32) -> i32 {
        let len = box_types.len();
        let mut count = 0_i32;
        box_types.sort_unstable_by(|a, b| b[1].cmp(&a[1]));

        let mut box_index = 0_usize;
        while truck_size > 0 && box_index < len {
            let curr = box_types[box_index][0].min(truck_size);
            truck_size -= curr;
            count += curr * box_types[box_index][1];
            box_index += 1;
        }

        count
    }
}
