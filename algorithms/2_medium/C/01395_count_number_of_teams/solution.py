class Solution:
    def numTeams(self, rating: List[int]) -> int:
        count = 0

        # use j for middle value
        for j in range(1, len(rating) - 1):

            #  count(rating[i]) < rating[j] < count(rating[k])
            count_smaller_i = sum(1 for i in range(j) if rating[i] < rating[j])
            count_bigger_k = sum(1 for k in range(j+1, len(rating)) if rating[j] < rating[k])

            # count(rating[i]) > rating[j] > count(rating[k])
            count_bigger_i = (j - 0) - count_smaller_i # (j - 0) is total numbers count on left side of j ==> its just for easier reading
            count_smaller_k= (len(rating) - (j + 1)) - count_bigger_k # (rating.len() - ( j + 1)) ==> total number on right side of j

            count += count_smaller_i * count_bigger_k + count_bigger_i * count_smaller_k

        return count
