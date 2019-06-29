
def findSum(s, k):
    p = [[0 for _ in range(k+1)] for _ in range(len(s)+1) ]
    return _findSum(s, k, p)

def _findSum(s, k, p):
    if k == 0:
        return []
    if k < 0 or (k > 0 and len(s) == 0):
        return None

    if k-s[0] < 0:
        return None

    ts = s[1:]

    if p[len(ts)][k-s[0]] <= 1:
        r1 =  _findSum(ts, k-s[0], p)
        if r1 is not None:
            p[len(ts)][k-s[0]] = 2
            return [s[0]]+r1
        p[len(ts)][k-s[0]] = 1

    if p[len(ts)][k] <= 1:
        r2 = _findSum(ts, k, p)
        if r2 is not None:
            p[len(ts)][k] = 2
            return r2
        p[len(ts)][k] = 1


if __name__ == "__main__":
    s = [12, 1, 61, 5, 9, 2]
    k = 24
    r = findSum(s, k)
    print(r)
