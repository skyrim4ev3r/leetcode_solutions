class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        hashmap = {}
        for k in knowledge:
            hashmap[k[0]] = k[1]

        res = []
        i = 0
        n = len(s)

        while i < n:
            if s[i] == '(':
                temp_list = []
                i += 1

                while i < n and s[i] != ')':
                    temp_list.append(s[i])
                    i += 1

                temp_str = "".join(temp_list)
                res.append(hashmap.get(temp_str, '?'))
            else:
                res.append(s[i])

            i += 1

        return "".join(res)
