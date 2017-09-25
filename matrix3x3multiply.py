from math import sqrt, pow

def multiply(mat1, mat2):
    result = [[0,0,0], [0,0,0], [0,0,0]]
    for i in range(3):
        for j in range(3):
            for k in range(3):
                result[i][j] += (mat1[i][k] * mat2[k][j])
    return result

def multiplyVec(mat, vec):
    resultVec = [0, 0, 0]
    for i in range(3):
        for j in range(3):
            resultVec[i] += (mat[i][j] * vec[j])
    return resultVec

def diagonalPow(dMat, n):
    result = [[0,0,0], [0,0,0], [0,0,0]]
    for i in range(3):
        result[i][i] = pow(dMat[i][i], n)
    return result

sqroot2 = sqrt(2)

p = [
    [9, -2 * sqroot2 + 3, 2 * sqroot2 + 3],
    [3, 1 - sqroot2, 1 + sqroot2],
    [1, 1, 1]
]

diagonalMat = [
    [3, 0, 0],
    [0, 1 - sqroot2, 0],
    [0, 0,  1 + sqroot2]
]

pInv = [
    [0.5, -1, -0.5],
    [(sqroot2 - 1)/4, (2 - 3 * sqroot2)/4, 0.75],
    [-1*((1 + sqroot2)/4), (3 + sqroot2)/(2*sqroot2), 0.75]
]

pd = multiply(p, diagonalPow(diagonalMat, 5))
a = multiply(pd, pInv)
print(multiplyVec(a, [40, 10, 2]))