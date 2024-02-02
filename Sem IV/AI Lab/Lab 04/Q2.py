
class Graph:
	def __init__(self,vertices):
		self.graph = {}
		self.V = vertices
		self.n =0
		while(self.n<vertices):
			self.graph[self.n]=[]
			self.n = self.n+1 
	
	def addEdge(self,u,v):
		self.graph[u].append(v)

def isCycleExist(n,graph):

	in_degree=[0]*n

	for i in range(n):
		for j in graph[i]:
			in_degree[j]+=1
	
	queue=[]
	for i in range(len(in_degree)):
		if in_degree[i]==0:
			queue.append(i)
	
	cnt=0

	while(queue):
 
		nu=queue.pop(0)
 
		for v in graph[nu]:
			in_degree[v]-=1

			if in_degree[v]==0:
				queue.append(v)
		cnt+=1

	if cnt==n:
		return False
	else:
		return True
		

if __name__=='__main__':

	g=Graph(4)
	g.addEdge(0,1)
	g.addEdge(1,2)
	g.addEdge(2,3)
	g.addEdge(2,0)
	g.addEdge(3,3)
	g.addEdge(0,2)
	
	if isCycleExist(g.V,g.graph):
		print("Yes, graph has cycles")
	else:
		print("No, graph doesnt have cycles")
