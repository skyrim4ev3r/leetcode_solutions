class Solution:
    def findCommonResponse(self, responses: List[List[str]]) -> str:

        words_count = {}
        for response in responses:
            response_set = set(response)
            for word in response_set:
                if word in words_count:
                    words_count[word] += 1
                else:
                    words_count[word] = 1

        max_freq = 0
        max_str = ""
        for word, freq in words_count.items():
            if freq > max_freq:
                max_freq = freq
                max_str = word
            elif freq == max_freq and word < max_str:
                max_str = word

        return max_str
