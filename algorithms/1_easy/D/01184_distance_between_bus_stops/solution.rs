impl Solution {
    pub fn distance_between_bus_stops(distance: Vec<i32>, start: i32, destination: i32) -> i32 {
        let len = distance.len();
        let mut min_distance = i32::MAX;

        let mut curr_distance = 0_i32;
        let mut curr_index = start as usize;
        let dest_index = destination as usize; 

        while curr_index != dest_index {
            curr_distance += distance[curr_index];
            curr_index += 1;
            if curr_index >= len {
                curr_index = 0;
            }
        }

        min_distance = min_distance.min(curr_distance);

        curr_distance = 0;
        curr_index = start as usize;

        while curr_index != dest_index {
            curr_index -= 1;
            if curr_index >= len {
                curr_index = len - 1;
            }
            curr_distance += distance[curr_index];            
        }

        min_distance = min_distance.min(curr_distance);

        min_distance
    }
}
