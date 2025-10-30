class Solution:
    def RLE(self, list_ch):

        len_list_ch = len(list_ch)
        start = 0
        end = 0
        res = []

        while end < len_list_ch:
            while end < len_list_ch and list_ch[start] == list_ch[end]:
                end += 1
            res += list(str(end - start))
            res.append(list_ch[start])
            start = end

        return res

    def countAndSay(self, n: int) -> str:
        res = ['1']

        for _ in range(2, n + 1):
            res = self.RLE(res)

        return "".join(res)
