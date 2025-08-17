class Solution:

    def dfs(self, node, time_so_far, visited, graph, path):
        if node in path:
            return
        if node in visited and time_so_far >= visited[node]:
            return
        path.add(node)
        visited[node] = time_so_far

        for pair in graph.get(node, []):
            self.dfs(pair[0], time_so_far + pair[1], visited, graph, path)
        path.remove(node)

    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        visited = {}
        graph = {}
        path = set()

        # Build the Dict
        for i in range(len(times)):
            graph.setdefault(times[i][0], []).append((times[i][1], times[i][2]))

        start_node = k
        time_so_far = 0
        
        self.dfs(start_node, time_so_far, visited, graph, path)

        if len(visited) < n:
            return -1
        else:
            return max(visited.values())
        