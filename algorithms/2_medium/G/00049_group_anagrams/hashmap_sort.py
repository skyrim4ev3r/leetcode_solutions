class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}
        res = []

        for word in strs:

            sorted_word_list = list(word)
            sorted_word_list.sort()
            sorted_word = "".join(sorted_word_list)

            val = hashmap.get(sorted_word)

            if val != None:
                res[val].append(word)
            else:
                hashmap[sorted_word] = len(res)
                res.append([word])

        return res
