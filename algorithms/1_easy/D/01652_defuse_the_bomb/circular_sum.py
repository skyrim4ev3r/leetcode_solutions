class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:

        code_len = len(code)

        if k == 0:
            return [0] * code_len

        res = []

        left = 0
        right = 0

        if k < 0:
            right = code_len - 1
            left = code_len - abs(k)
        else:
            right = k
            left = 1

        curr_sum = sum(code[left:right + 1])

        for i in range(code_len):
            res.append(curr_sum)

            curr_sum -= code[left]
            left += 1
            if left == code_len:
                left = 0

            right += 1
            if right == code_len:
                right = 0

            curr_sum += code[right]

        return res
