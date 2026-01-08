class Solution {
    static void dfs(
        const vector<int>& arr,
        const size_t len,
        const size_t curr,
        vector<bool>& visited,
        bool& status
    ) {
        if (status || curr >= len || visited[curr]) {
            return;
        }

        if (arr[curr] == 0) {
            status = true;
            return;
        }

        const size_t offset {static_cast<size_t>(arr[curr])};
        visited[curr] = true;
        dfs(arr, len, curr - offset, visited, status);
        dfs(arr, len, curr + offset, visited, status);
        visited[curr] = false;
    }
public:
    static bool canReach(const vector<int>& arr, int start) {
        const size_t len {arr.size()};
        vector<bool> visited(len, false);
        bool status {false};

        dfs(arr, len, static_cast<size_t>(start), visited, status);

        return status;
    }
};
