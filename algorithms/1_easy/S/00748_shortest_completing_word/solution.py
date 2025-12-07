class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        freqs_p = [0] * 26
        words_len = len(words)
        curr_selected_index = words_len

        for ch in licensePlate:
            if ord(ch) >= ord('a') and ord(ch) <= ord('z'):
                freqs_p[ord(ch) - ord('a')] += 1

            if ord(ch) >= ord('A') and ord(ch) <= ord('Z'):
                freqs_p[ord(ch) - ord('A')] += 1

        for i in range(words_len):
            if curr_selected_index != words_len and len(words[curr_selected_index]) <= len(words[i]):
                continue

            freqs_w = [0] * 26

            for ch in words[i]:
                if ord(ch) >= ord('a') and ord(ch) <= ord('z'):
                    freqs_w[ord(ch) - ord('a')] += 1

            is_good = True

            for j in range(26):
                if freqs_p[j] > freqs_w[j]:
                    is_good = False
                    break

            if is_good:
                curr_selected_index = i

        return words[curr_selected_index]
