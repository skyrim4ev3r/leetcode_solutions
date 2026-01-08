impl Solution {
    fn dfs(
        arr: &Vec<i32>,
        len: usize,
        curr: usize,
        visited: &mut Vec<bool>,
        status: &mut bool
    ) {
        if *status || curr >= len || visited[curr] {
            return;
        }

        if arr[curr] == 0 {
            *status = true;
            return;
        }

        let offset = arr[curr] as usize;
        visited[curr] = true;
        Self::dfs(arr, len, curr - offset, visited, status);
        Self::dfs(arr, len, curr + offset, visited, status);
        visited[curr] = false;
    }

    pub fn can_reach(arr: Vec<i32>, start: i32) -> bool {
        let len = arr.len();
        let mut visited = vec![false; len];
        let mut status = false;

        Self::dfs(&arr, len, start as usize, &mut visited, &mut status);

        status
    }
}
