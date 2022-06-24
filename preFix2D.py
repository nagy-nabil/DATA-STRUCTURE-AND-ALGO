def preFix(matrix):
        #the corners first with two loops
        for i in range(1,len(matrix)):
            matrix[i][0]+=matrix[i-1][0]
        for i in range(1,len(matrix[0])):
            matrix[0][i]+=matrix[0][i-1]
        #then each item with the formula to not add somthing twice the formula[a+=(a[r][c-1]//the above+a[r-1][c]//left data-a[r-1][c-1]//remove what we added twice)]
        for r in range(1,len(matrix)):
            for c in range(1,len(matrix[0])):
                matrix[r][c]+=(matrix[r][c-1]+matrix[r-1][c]-matrix[r-1][c-1])


matrix=[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]
preFix(matrix)
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        print(f"{matrix[i][j]} ",end="")
    print("")