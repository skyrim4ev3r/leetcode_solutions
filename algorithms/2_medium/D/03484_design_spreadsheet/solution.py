class Spreadsheet:

    def __init__(self, rows: int):
        self.grid = {}

    def setCell(self, cell: str, value: int) -> None:
        if value != 0:
            self.grid[cell] = value

    def resetCell(self, cell: str) -> None:
        if cell in self.grid:
            del self.grid[cell]

    def getValue(self, formula: str) -> int:
        res = 0

        parts =  formula[1:].split('+')

        for part in parts:
            if ord(part[0]) >= ord('0') and ord(part[0]) <= ord('9'):
                res += int(part)
            elif part in self.grid:
                res += self.grid[part]

        return res
