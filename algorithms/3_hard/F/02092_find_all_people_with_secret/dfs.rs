use std::collections::{HashMap, HashSet};

impl Solution {
    fn dfs(
        ppl: usize,
        map_now: & HashMap<usize, Vec<usize>>,
        knows: &mut Vec<bool>,
        is_visited: &mut HashSet<usize>
    ) {
        if !is_visited.insert(ppl) {
            return;
        }

        if let Some(vec) = map_now.get(&ppl) {
            for other_ppl in vec.iter() {
                knows[*other_ppl] = true;
                Self::dfs(*other_ppl, map_now, knows, is_visited);
            }
        }
    }

    #[inline]
    fn check_current_state(
        map_now: &mut HashMap<usize, Vec<usize>>,
        knows: &mut Vec<bool>
    ) {
        let mut is_visited: HashSet<usize> = HashSet::with_capacity(map_now.len());
        for ppl in map_now.keys() {
            if knows[*ppl] {
                Self::dfs(*ppl, map_now, knows, &mut is_visited);
            }
        }

        map_now.clear();
    }

    pub fn find_all_people(n: i32, mut meetings: Vec<Vec<i32>>, first_person: i32) -> Vec<i32> {
        let mut knows = vec![false; n as usize];
        knows[0] = true;
        knows[first_person as usize] = true;
        let mut map_now: HashMap<usize, Vec<usize>> = HashMap::new();

        meetings.sort_unstable_by(|a, b| a[2].cmp(&b[2]));

        for i in 0..meetings.len() {
            let ppl1 = meetings[i][0] as usize;
            let ppl2 = meetings[i][1] as usize;

            if i > 0 && meetings[i][2] != meetings[i - 1][2] {
                Self::check_current_state(&mut map_now, &mut knows);
            }

            if knows[ppl1] {
                knows[ppl2] = true;
            } else if knows[ppl2] {
                knows[ppl1] = true;
            } else {
                map_now.entry(ppl1).or_insert(Vec::new()).push(ppl2);
                map_now.entry(ppl2).or_insert(Vec::new()).push(ppl1);
            }
        }

        Self::check_current_state(&mut map_now, &mut knows);

        let mut res: Vec<i32> = Vec::new();
        for (i, know) in knows.iter().enumerate() {
            if *know {
                res.push(i as i32);
            }
        }

        res
    }
}
