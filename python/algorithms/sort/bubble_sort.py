
def bubble_sort(nums):
    """Pure implementation of bubble sort algorithm in Python
    :param collection: some mutable ordered collection with heterogeneous
    comparable items inside
    :return: the same collection ordered by ascending
    Examples:
    >>> bubble_sort([0, 5, 2, 3, 2])
    [0, 2, 2, 3, 5]
    >>> bubble_sort([0, 5, 2, 3, 2]) == sorted([0, 5, 2, 3, 2])
    True
    >>> bubble_sort([]) == sorted([])
    True
    >>> bubble_sort([-2, -45, -5]) == sorted([-2, -45, -5])
    True
    >>> bubble_sort([-23, 0, 6, -4, 34]) == sorted([-23, 0, 6, -4, 34])
    True
    >>> bubble_sort(['d', 'a', 'b', 'e', 'c']) == sorted(['d', 'a', 'b', 'e', 'c'])
    True
    >>> import random
    >>> collection = random.sample(range(-50, 50), 100)
    >>> bubble_sort(collection) == sorted(collection)
    True
    >>> import string
    >>> collection = random.choices(string.ascii_letters + string.digits, k=100)
    >>> bubble_sort(collection) == sorted(collection)
    True
    """
    length = len(nums)
    for i in range(length-1):
        for j in range(i+1, 0, -1):
            if nums[j] < nums[j-1]:
                tmp = nums[j]
                nums[j] = nums[j-1]
                nums[j-1] = tmp
    return nums

if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True)

    user_input = input("numbers: ").strip()
    unsorted_nums = [int(num) for num in user_input.split(",")]
    sorted_nums = bubble_sort(unsorted_nums)
    print(sorted_nums)

