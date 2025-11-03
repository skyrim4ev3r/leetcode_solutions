impl Solution {
    pub fn count_matches(items: Vec<Vec<String>>, rule_key: String, rule_value: String) -> i32 {

        let mut count = 0;

        for item in items {

            if (rule_key == "type" && rule_value == item[0])
                || (rule_key == "color" && rule_value == item[1])
                || (rule_key == "name" && rule_value == item[2]) 
            {
                count += 1;
            }
        }

        count
    }
}
