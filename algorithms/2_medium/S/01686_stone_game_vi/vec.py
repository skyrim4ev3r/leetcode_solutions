class Solution:
    def stoneGameVI(self, alice_values: List[int], bob_values: List[int]) -> int:
        n = len(alice_values)
        vec = []

        for i in range(n):
            priority = alice_values[i] + bob_values[i]
            vec.append((priority, alice_values[i], bob_values[i]))

        vec.sort(key= lambda x: x[0], reverse= True)

        alice_turn = True
        alice_score = 0
        bob_score = 0

        for (_, alice_value, bob_value) in vec:
            if alice_turn:
                alice_score += alice_value
            else:
                bob_score += bob_value

            alice_turn = not alice_turn

        if bob_score > alice_score:
            return -1
        elif bob_score == alice_score:
            return 0
        else:
            return 1
