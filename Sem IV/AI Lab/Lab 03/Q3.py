
class graph:
    def __init__(self,n):
        self.list={}

    def add_edge(self, src , des):
        self.list[src]=des

    def display(self):

        print(self.list)

def maze_dfs( g , start ,end):

    stack=[start]
    visited=[]
    path=[]
    while (len(stack)>0):

        if stack[-1] not in path:
            path.append(stack[-1])

        if (stack[-1] not in g.list ):
            item=[]
        else:
            item=g.list[stack[-1]]

        visited.append(stack[-1])

        if stack[-1]==end:
            print("Finshed")
            return path
          

        for ele in item :
            if ele not in visited:
                stack.append(ele)
            else :
                item.remove(ele)


        if len(item)==0:
            path.remove(stack[-1])
            stack.pop()


g=graph(21)
g.list={ 2:[1,3] ,3:[2,8], 8:[3,7], 1:[2,6], 6:[1,11], 11:[6,12], 12:[11,17] , 17:[16,18],16:[17],18:[17,19] , 19:[14,18], 14:[9,13,19],9:[14,10], 10:[5,9,15], 15:[10,20] , 20:[15] ,5:[10,4], 4:[5] }
print(maze_dfs(g,2,20))
