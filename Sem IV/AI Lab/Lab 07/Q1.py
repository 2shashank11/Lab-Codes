class Graph:
    def __init__(self):
        self.graph={
            'A': [('B', 6), ('F', 3)],
            'B': [('A', 6), ('C', 3), ('D', 2)],
            'C': [('B', 3), ('D', 1), ('E', 5)],
            'D': [('B', 2), ('C', 1), ('E', 8)],
            'E': [('C', 1), ('D', 8), ('I', 5), ('J', 5)],
            'F': [('A', 3), ('G', 1), ('H', 7)],
            'G': [('F', 1), ('I', 3)],
            'H': [('F', 7), ('I', 2)],
            'I': [('E', 5), ('G', 3), ('H', 2), ('J', 3)],
            'J': [('E', 5), ('I', 3)]
        }
        self.vertices=len(self.graph)

    def heuristic(self, v):
        H_dist = {
            'A': 10,
            'B': 8,
            'C': 5,
            'D': 7,
            'E': 3,
            'F': 6,
            'G': 5,
            'H': 3,
            'I': 1,
            'J': 0
        }
        return H_dist[v]

    def getNeighbours(self, v):
        if v in self.graph:
            return self.graph[v]
        else: 
            return None

    def aStarAlgo(self, start, stop):
        openSet=set(start)
        closedSet=set()
        g={}
        parents={}

        g[start]=0
        parents[start]=start

        while len(openSet)>0:
            n=None
            for v in openSet:
                if n== None or g[v] + self.heuristic(v) < g[n] + self.heuristic(n):
                    n=v
            
            if n == stop or self.graph[n] == None:
                pass
            else:
                for (m, weight) in self.getNeighbours(n): #neighbour
                    if m not in openSet and m not in closedSet:
                        openSet.add(m)
                        parents[m]=n
                        g[m]=g[n]+weight
                    else:
                        if g[m] > g[n] + weight:
                            g[m]=g[n]+weight
                            parents[m]=n

                            if m in closedSet:
                                closedSet.remove(m)
                                openSet.add(m)
                    
            if n == None:
                print('Path doesnot Exist!')
                return None

            if n == stop:
                path=[]
                while parents[n] != n:
                    path.append(n)
                    n=parents[n]

                path.append(start)
                path.reverse()
                print('Path found: {}'.format(path))
                return path
            openSet.remove(n)
            closedSet.add(n)
        print('Path doesnot Exis!')
        return None

g=Graph()
g.aStarAlgo('A', 'J')
