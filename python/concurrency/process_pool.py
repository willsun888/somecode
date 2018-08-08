#coding=utf-8

from multiprocessing import Pool
import time

def job(x):
    time.sleep(1)
    return x*x

def map_worker():
    pool = Pool(processes=8)
    res = pool.map(job, range(10))
    print(res)

def apply_worker():
    pool = Pool(processes=8)
    res = [pool.apply(job, (x,)) for x in range(10)]
    print(res)

# apply_async只能传一个值，要实现map的效果，需要迭代
def apply_async_worker():
    pool = Pool(processes=8)
    res = [pool.apply_async(job, (i,)) for i in range(10)]
    print([r.get() for r in res])

if __name__ == '__main__':
    map_worker()
    apply_worker()
    apply_async_worker()

