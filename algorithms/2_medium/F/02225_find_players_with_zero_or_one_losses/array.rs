impl Solution {
    const MAX_PLAYERS: usize = 10_usize.pow(5) + 1;

    pub fn find_winners(matches: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut lose_counts = [-1_i32; Self::MAX_PLAYERS];
    
        for game in matches.into_iter() {
            let p1 = game[0] as usize;
            let p2 = game[1] as usize;

            if lose_counts[p1] == -1 {
                lose_counts[p1] = 0;
            }

            if lose_counts[p2] == -1 {
                lose_counts[p2] = 1;
            } else {
                lose_counts[p2] += 1;
            }
        }

        let mut zero_lose_players: Vec<i32> = Vec::new();
        let mut one_lose_players: Vec<i32> = Vec::new();

        for (i, lose_count) in lose_counts.into_iter().enumerate() {
            if lose_count == 1 {
                one_lose_players.push(i as i32);
            } else if lose_count == 0 {
                zero_lose_players.push(i as i32);
            }
        }

        vec![zero_lose_players, one_lose_players]
    }
}
