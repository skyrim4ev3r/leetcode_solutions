class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        players_map = defaultdict(int)

        for game in matches:
            players_map[game[0]]
            players_map[game[1]] += 1

        zero_lose_players = []
        one_lose_players = []

        for (player, lose_count) in players_map.items():
            if lose_count == 1:
                one_lose_players.append(player)
            elif lose_count == 0:
                zero_lose_players.append(player)

        zero_lose_players.sort()
        one_lose_players.sort()

        return [zero_lose_players, one_lose_players]
