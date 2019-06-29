import sys
def is_perfect_ten(num):
    sum = 0
    while num > 0:
        sum += num%10
        num = num//10

    return sum == 10

def get_perfect_ten(n):
    base = 10
    while n > 0:
        base += 9
        if is_perfect_ten(base):
            n = n-1
    return base

if __name__ == "__main__":
    print(sys.argv)
    print(get_perfect_ten(int(sys.argv[1])))
