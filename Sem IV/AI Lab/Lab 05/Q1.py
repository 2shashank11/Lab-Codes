class Graph:
	def __init__(self):
		self.adj = {}

	def add_edge(self,start,end,cost):
		if start not in self.adj:
			self.adj[start]=[]
		self.adj[start].append((end,cost))

	def ucs(self,start,goal):
		pqueue = [(0, start , [])]
		visited= []

		while pqueue:
			pqueue.sort()
			(cost , current ,path) = pqueue.pop(0)

			if current in visited:
				continue

			path = path + [(current,cost)]
			if (current == goal):
				return path

			visited.append(current)

			for neighbour , neighbour_cost in self.adj.get(current , []):
				if neighbour not in visited:
					pqueue.append((cost+neighbour_cost , neighbour , path))
		return None

g = Graph()
g.add_edge('S' , '1' , 2)
g.add_edge('S' , '3' , 5)
g.add_edge('3' , '1' , 5)
g.add_edge('1' , 'G' , 1)
g.add_edge('3' , 'G' , 1)
g.add_edge('2' , '1' , 4)
g.add_edge('3' , '4' , 2)
g.add_edge('4' , '2' , 4)
g.add_edge('G' , '4' , 7)
g.add_edge('5' , '2' , 6)
g.add_edge('4' , '5' , 3)

start_node = 'S'
goal_node = 'G'
result = g.ucs(start_node , goal_node)

if result:
	total_cost = result[-1][1]
	path_nodes = [node[0] for node in result]
	print(f"Uniform Cost Search from {start_node} to {goal_node}:")
	print(f"Path : {path_nodes}")
	print(f"Total cost : {total_cost}")
else:
	print("No path found")