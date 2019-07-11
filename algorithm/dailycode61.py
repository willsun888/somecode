
import sys

dict = {}

def _pow(x, y):
    if y == 1:
        return x
    if y in dict:
        print("hit %d" % y)
        return dict[y]

    n1, n2 = 1, 1
    t1, t2 = y//2, (y+1)//2

    if t1 in dict:
        n1 = dict[t1]
        print("hit %d" % t1)
    else:
        n1 = _pow(x, t1)
        dict[t1] = n1

    if t2 in dict:
        n2 = dict[t2]
        print("hit %d" % t2)
    else:
        n2 = _pow(x, t2)
        dict[t2] = n2

    dict[y] = n1*n2

    return n1*n2

def pow2(x, y):
    if y == 1:
        return x
    return pow(x, y//2) * pow(x, (y+1)//2)

def pow(x, y):
    return _pow(x, y)

if __name__ == "__main__":
    print(sys.argv)
    print(pow(int(sys.argv[1]), int(sys.argv[2])))
