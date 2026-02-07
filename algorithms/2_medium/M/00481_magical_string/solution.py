class Solution:
    def magicalString(self, target_len: int) -> int:
        if target_len <= 3:
            return 1

        res = [1, 2, 2]
        index = 2
        curr_num = 1

        while len(res) < target_len:
            res.append(curr_num)

            if res[index] == 2 and len(res) < target_len:
                res.append(curr_num)

            curr_num = 1 if curr_num == 2 else 2
            index += 1

        return res.count(1)
