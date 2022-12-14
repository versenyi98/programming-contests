def calc_max(is_pos, idx, start_idx, first_neg_idx, last_neg_idx):
    current_max = 0
    if is_pos:
        current_max = max(current_max, idx - start_idx + 1)
    else:
        if last_neg_idx is not None:
            current_max = max(current_max, last_neg_idx - start_idx)
        if first_neg_idx is not None:
            current_max = max(current_max, idx - first_neg_idx)
    return current_max


class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        is_pos = first_neg_idx = last_neg_idx = start_idx = None
        current_max = 0

        for idx, val in enumerate(nums):
            if val == 0:
                if is_pos is None:
                    continue
                current_len = calc_max(is_pos, idx - 1, start_idx, first_neg_idx, last_neg_idx)
                current_max = max(current_max, current_len)
                is_pos = first_neg_idx = last_neg_idx = start_idx = None
            else:
                if is_pos is None:
                    is_pos = True
                    start_idx = idx
                if val < 0:
                    is_pos = not is_pos
                    last_neg_idx = idx
                    if first_neg_idx is None:
                        first_neg_idx = idx
        current_len = calc_max(is_pos, len(nums) - 1, start_idx, first_neg_idx, last_neg_idx)

        current_max = max(current_max, current_len)
        return current_max
