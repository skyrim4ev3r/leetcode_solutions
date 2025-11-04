class Solution:
    def dfs(self, graph, curr_index, target_index, curr_vec, res):
        curr_vec.append(curr_index)

        if curr_index == target_index:
            res.append(curr_vec[:])
        else:
            for next_index in graph[curr_index]:
                self.dfs(graph, next_index, target_index, curr_vec, res)

        curr_vec.pop()

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        res = []
        temp = []
        target_index = len(graph) - 1
        start_index = 0

        self.dfs(graph, start_index, target_index, temp, res)

        return res
