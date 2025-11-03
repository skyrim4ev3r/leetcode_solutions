class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        s_len = len(s)
        half =  s_len / 2
        balance = 0

        for i in range(s_len):
            match s[i]:
                case 'a' | 'e' | 'i' | 'o' | 'u' | 'A' | 'E' | 'I' | 'O' | 'U':
                    if i < half:
                        balance += 1
                    else:
                        balance -= 1

        return balance == 0
