class Allocator:
    def __init__(self, n: int):
        self.memory = [0] * n
        self.allocated = [False] * n
        self.counter = {0: n}

    def allocate(self, size: int, mID: int) -> int:
        next_empty_idx = 0

        memory_to_use = self.memory
        allocated_to_use = self.allocated

        current_idx = 0

        if self.counter[0] < size:
            return -1

        while next_empty_idx >= 0:
            if 0 not in memory_to_use:
                return -1

            if True not in allocated_to_use:
                next_allocated_idx = len(memory_to_use)
            else:
                next_allocated_idx = allocated_to_use.index(True)

            next_empty_idx = memory_to_use.index(0)

            if next_empty_idx + size > next_allocated_idx:
                memory_to_use = memory_to_use[next_allocated_idx + 1:]
                allocated_to_use = allocated_to_use[next_allocated_idx + 1:]
                current_idx += next_allocated_idx + 1
                continue

            if next_empty_idx + size <= len(memory_to_use):
                current_idx += next_empty_idx
                self.allocated = [True if (current_idx <= idx < current_idx + size) else value for idx, value in enumerate(self.allocated)]
                self.memory = [mID if (current_idx <= idx < current_idx + size) else value for idx, value in enumerate(self.memory)]
                if mID not in self.counter:
                    self.counter[mID] = 0
                self.counter[mID] += size
                self.counter[0] -= size
                return current_idx
            else:
                return -1

    def free(self, mID: int) -> int:
        self.allocated = [False if self.memory[idx] == mID else original for idx, original in enumerate(self.allocated)]
        self.memory = [0 if item == mID else item for item in self.memory]

        ret = self.counter[mID] if mID in self.counter else 0

        self.counter[mID] = 0
        self.counter[0] += ret

        return ret
