class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groups_map = {}
        res = []
        for i in range(len(groupSizes)):
            g_size = groupSizes[i]
            if not g_size in  groups_map:
                groups_map[g_size] = [i]
            else:
                groups_map[g_size].append(i)

            if len(groups_map[g_size]) == g_size:
                res.append(groups_map[g_size])
                del groups_map[g_size]

        return res
