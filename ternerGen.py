def isIn(string):
    return '00' in string or '11' in string

n = 6

def terner(current):
    add = 0
    if isIn(current) and len(current) == n:
        add = 1
        print(current)
    if len(current) >= n:
        return add
    for i in range(3):
        add += terner(current + str(i))
    return add

print(terner(''))