class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        keys = [0]
        visited = set([0])

        while keys:
            key = keys.pop()
            for new_key in rooms[key]:
                if new_key not in visited:
                    keys.append(new_key)
                    visited.add(new_key)
        return len(visited) == len(rooms)
