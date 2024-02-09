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
g.add_edge('Feering' , 'Blaxhall' , 46)
g.add_edge('Blaxhall' , 'Dunwich' , 15)
g.add_edge('Dunwich' , 'Blaxhall' , 17)
g.add_edge('Harwich' , 'Blaxhall' , 40)
g.add_edge('Harwich' , 'Dunwich' , 53)
g.add_edge('Harwich' , 'Tiptree' , 31)
g.add_edge('Tiptree' , 'Feering' , 3)
g.add_edge('Feering' , 'Maldon' , 11)
g.add_edge('Maldon' , 'Tiptree' , 8)
g.add_edge('Tiptree' , 'Clacton' , 29)
g.add_edge('Clacton' , 'Harwich' , 17)
g.add_edge('Clacton' , 'Maldon' , 40)

start_node = 'Maldon'
goal_node = 'Dunwich'
result = g.ucs(start_node , goal_node)

if result:
	total_cost = result[-1][1]
	path_nodes = [node[0] for node in result]
	print(f"Uniform Cost Search from {start_node} to {goal_node}:")
	print(f"Path : {path_nodes}")
	print(f"Total cost : {total_cost}")
else:
	print("No path found")