
def findSum(s, k):
    r = [[]]
    if _findSum(s, k, r):
        return r[0]
    return []

def _findSum(s, k, r):
    if k == 0:
        return True
    if k < 0 or len(s) == 0:
        return False

    r1 = [r[0][:]]
    r1[0].append(s[0])
    if _findSum(s[1:], k-s[0], r1):
        r[0] = r1[0]
        return True

    r2 = [r[0][:]]
    if _findSum(s[1:], k, r2):
        r[0] = r2[0]
        return True

    return False

if __name__ == "__main__":
    s = [12, 1, 61, 5, 9, 2]
    k = 66
    r = findSum(s, k)
    print(r)
