use std::collections::HashMap;

impl Solution {
    pub fn find_winners(matches: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut players_map : HashMap<i32, i32> = HashMap::new();

        for game in matches.into_iter() {
            players_map.entry(game[0]).or_insert(0);
            *players_map.entry(game[1]).or_insert(0) += 1;
        }

        let mut zero_lose_players: Vec<i32> = Vec::new();
        let mut one_lose_players: Vec<i32> = Vec::new();

        for (player, lose_count) in players_map.into_iter() {
            if lose_count == 1 {
                one_lose_players.push(player);
            } else if lose_count == 0 {
                zero_lose_players.push(player);
            }
        }

        zero_lose_players.sort_unstable();
        one_lose_players.sort_unstable();

        vec![zero_lose_players, one_lose_players]
    }
}
