impl Solution {
    fn dfs(rooms: &Vec<Vec<i32>>, visiteds: &mut Vec<bool>, curr_room: usize) {
        if visiteds[curr_room] {
            return;
        }

        visiteds[curr_room] = true;

        for &key in rooms[curr_room].iter() {
            Self::dfs(rooms, visiteds, key as usize);
        }
    }
    pub fn can_visit_all_rooms(rooms: Vec<Vec<i32>>) -> bool {
        let mut visiteds = vec![false; rooms.len()];

        Self::dfs(&rooms, &mut visiteds, 0);

        for is_visited in visiteds.into_iter() {
            if !is_visited {
                return false;
            }
        }

        true
    }
}
