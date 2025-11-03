class Solution:
    def countMatches(self, items: List[List[str]], rule_key: str, rule_value: str) -> int:
        count = 0

        for item in items:

            if (rule_key == "type" and rule_value == item[0]) \
                or (rule_key == "color" and rule_value == item[1]) \
                or (rule_key == "name" and rule_value == item[2]):

                count += 1

        return count
