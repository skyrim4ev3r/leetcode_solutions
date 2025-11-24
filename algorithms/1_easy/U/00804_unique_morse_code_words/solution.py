class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        codes = [ \
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---", \
            "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-", \
            "..-","...-",".--","-..-","-.--","--.." \
        ]
        hashset = set()

        for word in words:
            tmp = []

            for ch in word:
                tmp += codes[ord(ch) - ord('a')]

            hashset.add("".join(tmp))

        return len(hashset)
