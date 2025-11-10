# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zig_zag_helper_search(self, curr, curr_zig_zag_len, should_call_left, max_zig_zag_len):
        if curr == None:
            return

        max_zig_zag_len[0] = max(max_zig_zag_len[0], curr_zig_zag_len)

        if should_call_left:
            self.zig_zag_helper_search(curr.left, curr_zig_zag_len + 1, not should_call_left, max_zig_zag_len)
            self.zig_zag_helper_search(curr.right, 1, True, max_zig_zag_len)
        else:
            self.zig_zag_helper_search(curr.left, 1, False, max_zig_zag_len)
            self.zig_zag_helper_search(curr.right, curr_zig_zag_len + 1, not should_call_left, max_zig_zag_len)

    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        max_zig_zag_len = [0]
        self.zig_zag_helper_search(root, 0, False, max_zig_zag_len)
        return max_zig_zag_len[0]
