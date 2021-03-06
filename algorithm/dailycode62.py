import sys

def get_ways(n, m):
    if n == 1 or m == 1:
        return 1
    return get_ways(n-1, m) + get_ways(n, m-1)

def _get_ways2(n, m, arr):
    if n == 0 or m == 0:
        return 0
    if n == 1 or m == 1:
        return 1
    if arr[n][m] != 0:
        return arr[n][m]
    t1 = 0
    if arr[n-1][m] != 0:
        t1 = arr[n-1][m]
    else:
        t1 = _get_ways2(n-1, m, arr)
        arr[n-1][m] = t1

    t2 = 0
    if arr[n][m-1] != 0:
        t2 = arr[n][m-1]
    else:
        t2 = _get_ways2(n, m-1, arr)
        arr[n][m-1] = t2

    return t1+t2

def get_ways2(n, m):
    arr = [[0 for _ in range(m)] for _ in range(n)]

    for i in range(0, n):
        arr[i][0] = 1

    for j in range(0, m):
        arr[0][j] = 1

    for i in range(1, n):
        for j in range(1, m):
            arr[i][j] = arr[i-1][j]+arr[i][j-1]

    return arr[-1][-1]

if __name__ == "__main__":
    num = get_ways2(int(sys.argv[1]), int(sys.argv[2]))
    print(num)
