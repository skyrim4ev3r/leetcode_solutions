class Solution:
    def maxBalancedShipments(self, weight: List[int]) -> int:
        count = 0
        index = 1
        weight_len = len(weight)

        while index < weight_len:

            # last parcel should strictly less than the maximum weight.
            # to get maximum number, just need to count subarrs as fast as they meet condition
            # which is this simple comparison
            if weight[index - 1] > weight[index]:
                count += 1

                # Next iter should not check this index any more by:  weight[index - 1]
                index += 2
            else:
                index += 1

        return count