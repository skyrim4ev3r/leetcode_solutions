impl Solution {
    pub fn find_relative_ranks(score: Vec<i32>) -> Vec<String> {

        // Store original_index and score as tuples (i, s) into players
        let mut players: Vec<(usize, i32)> = score.iter().enumerate().map(|(o_i, &s)| (o_i, s)).collect();
        
        // Sort players based on scores in decreasing order
        players.sort_by(|a, b| b.1.cmp(&a.1));

        // Create a vector of empty strings to avoid using push()
        let mut res = vec![String::new(); score.len()];

        for (current_index, &(original_index, _)) in players.iter().enumerate() {
            // Calculate the rank
            let rank = current_index + 1;

            res[original_index] = match rank { 
                1 => String::from("Gold Medal"),
                2 => String::from("Silver Medal"),
                3 => String::from("Bronze Medal"),
                _ => rank.to_string(),
            };
        }

        res
    }
}
