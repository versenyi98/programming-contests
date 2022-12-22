class Solution(object):
    def sumOfDistancesInTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        self.connections = {idx: [] for idx in range(n)}
        for node1, node2 in edges:
            self.connections[node1].append(node2)
            self.connections[node2].append(node1)

        self.size = [-1] * n
        self.actual_dist = [-1] * n

        self.root_dist = 0
        self.get_size(0)
        self.actual_dist[0] = self.root_dist

        for other in self.connections[0]:
            self.get_actual_dist(other, self.actual_dist[0])

        return self.actual_dist

    def get_size(self, node, depth=0):
        self.size[node] = 1
        self.root_dist += depth
        for other in self.connections[node]:
            if self.size[other] == -1:
                self.get_size(other, depth + 1)
                self.size[node] += self.size[other]

    def get_actual_dist(self, node, parent_dist):
        self.actual_dist[node] = parent_dist + self.size[0] - 2 * self.size[node]

        for other in self.connections[node]:
            if self.actual_dist[other] == -1:
                self.get_actual_dist(other, self.actual_dist[node])