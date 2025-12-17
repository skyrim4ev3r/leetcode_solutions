# https://leetcode.com/problems/friend-requests-ii-who-has-the-most-friends/

import pandas as pd

def most_friends(request_accepted: pd.DataFrame) -> pd.DataFrame:
    user_friends_counts = pd.concat(
        [request_accepted['requester_id'], request_accepted['accepter_id']]
    ).value_counts()

    max_friends_count = user_friends_counts.max()
    users_with_max_friends = user_friends_counts[user_friends_counts == max_friends_count]
    result_df = users_with_max_friends.reset_index()
    result_df.columns = ["id", "num"]

    return result_df
