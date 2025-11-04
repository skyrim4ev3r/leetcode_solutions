use std::collections::HashMap;

struct Spreadsheet {
    grid: HashMap<String, i32>,
}

impl Spreadsheet {
    fn new(_rows: i32) -> Self {
        Self { 
            grid: HashMap::new(),
         }
    }

    fn set_cell(&mut self, cell: String, value: i32) {
        // If the value is 0, it won't be added to the grid since 0 is the default
        if value != 0 {
            self.grid.insert(cell, value);
        }
    }

    fn reset_cell(&mut self, cell: String) {
        // Remove the cell is equal to set it to 0
        // If it doesn't exist, do nothing
        let _ = self.grid.remove(&cell);
    }

    fn get_value(&self, formula: String) -> i32 {
        let mut sum = 0;

        for part in formula[1..].split('+') {
            if let Ok(num) = part.parse::<i32>() {
                sum += num;
            } else if let Some(num) = self.grid.get(part) {
                sum += num;
            } //else { continue; } // No need to handle the case where the part is not found; it defaults to 0
        }

        sum
    }
}
