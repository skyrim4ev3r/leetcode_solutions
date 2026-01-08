use std::collections::VecDeque;

impl Solution {
    pub fn can_reach(arr: Vec<i32>, start: i32) -> bool {
        let len = arr.len();
        let mut visited = vec![false; len];
        let mut q: VecDeque<usize> = VecDeque::with_capacity(1 + len / 2);
        q.push_back(start as usize);
        visited[start as usize] = true;

        while let Some(i) = q.pop_front() {
            if arr[i] == 0 {
                return true;
            }

            let offset = arr[i] as usize;

            if i + offset < len && !visited[i + offset] {
                visited[i + offset] = true;
                q.push_back(i + offset);
            }

            if i - offset < len && !visited[i - offset] {
                visited[i - offset] = true;
                q.push_back(i - offset);
            }
        }

        false
    }
}
