class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        hashset = set()

        for email in emails:
            pos = email.find('@')
            unique = []

            for i in range(pos):
                if email[i] == '+':
                    break
                elif email[i] != '.':
                    unique.append(email[i]);

            unique += email[pos:]
            hashset.add(tuple(unique))

        return len(hashset)
