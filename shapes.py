
row1 = [1, 1, 0, 0]
row2 = [0, 0, 1, 1]
row3 = [1, 1, 0, 0]
row4 = [0, 1, 0, 1]

grid = [row1, row2, row3, row4]

for i in range(4):
    s = ''
    for j in range(4):
        s += str(grid[i][j])
        s += ' '
    print s

shape_num = 0

for i in range(4):
    for j in range(4):
        if(grid[i][j] < 1):
            continue
        # if we have connections and the shape has a number > 1 then this is
        # part of an existing shape. if we don't have connections or the
        # connection  == 1 then this is a new shape
        if(i > 0 and grid[i-1][j] > 0):
            grid[i][j] = grid[i-1][j]
        elif(j > 0 and grid[i][j-1] > 0):
            grid[i][j] = grid[i][j-1]
        else:
            shape_num += 1
            grid[i][j] = shape_num


print(' ')

for i in range(4):
    s = ''
    for j in range(4):
        s += str(grid[i][j])
        s += ' '
    print s

print("grid has " + str(shape_num) + " shapes")
