# https://leetcode.com/problems/delete-duplicate-emails/

import pandas as pd

def delete_duplicate_emails(person: pd.DataFrame) -> None:
    person.sort_values("id", inplace=True)
    person.drop_duplicates("email", inplace=True)
