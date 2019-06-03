from collections import deque

def max_of_subarrays(lst, k):
    q = deque()
    for i in range(k):
        while q and lst[i] >= lst[q[-1]]:
            q.pop()
        q.append(i)

    for i in range(k, len(lst)):
        print(lst[q[0]])
        while q and i-k >= q[0]:
            q.popleft()
        while q and lst[i] >= lst[q[-1]]:
            q.pop()
        q.append(i)
    print(lst[q[0]])

if __name__ == "__main__":
    print("hello")
    lst = [10, 5, 9, 7, 8, 7, 5, 6, 9]
    max_of_subarrays(lst, 3)
