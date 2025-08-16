class Solution:
    def dfs(self, graph, course, path, visited) -> bool:
        if course in path:
            return False
        if course in visited:
            return True
        
        for prereq in graph[course]:
            if prereq in path:
                return False
            
            path.add(course)

            if not self.dfs(graph, prereq, path, visited):
                return False

            path.remove(course)
            visited.add(course)
        return True

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {i: [] for i in range(numCourses)}

        for course, prereq in prerequisites:
            graph[course].append(prereq)

        path = set()
        visited = set()

        for course in range(numCourses):
            if not self.dfs(graph, course, path, visited):
                return False
        return True