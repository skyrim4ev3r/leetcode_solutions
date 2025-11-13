class Solution:
    def backtrack(self, digits, temp, curr_idx):
        if curr_idx == self.digits_len:
            self.res.append("".join(temp))
            return

        num_to_chars_idx = ord(digits[curr_idx]) - ord('2')

        for char in self.map_digit_to_char[num_to_chars_idx]:
            temp.append(char)
            self.backtrack(digits, temp, curr_idx + 1)
            temp.pop()

    def letterCombinations(self, digits: str) -> List[str]:
        self.map_digit_to_char = [
            ['a','b','c'],
            ['d','e','f'],
            ['g','h','i'],
            ['j','k','l'],
            ['m','n','o'],
            ['p','q','r', 's'],
            ['t','u','v'],
            ['w','x','y', 'z'],
        ]

        temp = []
        self.res = []
        self.digits_len = len(digits)

        self.backtrack(digits, temp, 0)

        return self.res
