def BFS(a, b, target):
    visited = {}
    isSolvable = False
    path = []
    q = []
    q.append([0, 0])

    while (len(q) > 0):
        u = q.pop(0)
        if ((u[0], u[1]) in visited):
            continue
        if ((u[0] > a or u[1] > b or u[0] < 0 or u[1] < 0)):
            continue

        path.append([u[0], u[1]])
        visited[(u[0], u[1])] = 1

        if (u[0] == target or u[1] == target):
            isSolvable = True

            if (u[0] == target):
                if (u[1] != 0):
                    path.append([u[0], 0])
            else:
                if (u[0] != 0):
                    path.append([0, u[1]])

            sz = len(path)
            for i in range(sz):
                print("(", path[i][0], ",", path[i][1], ")")
            break

        # intermediate states to reach solution state
        q.append([u[0], b]) # Fill Jug2
        q.append([a, u[1]]) # Fill Jug1

        for ap in range(max(a, b) + 1):

            # Pour amount ap from Jug2 to Jug1
            c = u[0] + ap
            d = u[1] - ap

            # Check if this state is possible or not
            if (c == a or (d == 0 and d >= 0)):
                q.append([c, d])

            # Pour amount ap from Jug 1 to Jug2
            c = u[0] - ap
            d = u[1] + ap

            # Check if this state is possible or not
            if ((c == 0 and c >= 0) or d == b):
                q.append([c, d])

        # Empty Jug2
        q.append([a, 0])

        # Empty Jug1
        q.append([0, b])

    if (not isSolvable):
        print("No solution")


if __name__ == '__main__':

    Jug1, Jug2, target = 4, 3, 2
    print("Path from initial state to solution state:")

    BFS(Jug1, Jug2, target)
