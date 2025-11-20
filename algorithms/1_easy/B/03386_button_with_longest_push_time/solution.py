class Solution:
    def buttonWithLongestTime(self, events: List[List[int]]) -> int:
        max_duration = events[0][1]
        pressed_btn = events[0][0]

        for i in range(1, len(events)):
            curr_duration = events[i][1] - events[i - 1][1]

            if curr_duration > max_duration:
                max_duration = curr_duration
                pressed_btn = events[i][0]
            elif curr_duration == max_duration:
                pressed_btn = min(pressed_btn, events[i][0])

        return pressed_btn
