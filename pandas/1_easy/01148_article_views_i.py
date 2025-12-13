# https://leetcode.com/problems/article-views-i/

import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    filter1 = views["viewer_id"] == views["author_id"]
    res = views[filter1].drop_duplicates("author_id")
    res = res[["author_id"]].rename(columns={"author_id": "id"})
    res.sort_values(by="id", inplace=True)

    return  res
