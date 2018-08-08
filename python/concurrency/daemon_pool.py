#coding=utf-8

from multiprocessing import Pool
import time

def job(x):
    time.sleep(5)
    return x*x

def map_worker():
    pool = Pool(processes=8,maxtasksperchild=1)
    res = pool.map(job, range(10))
    print(res)

if __name__ == '__main__':
    map_worker()
    print("finish")
    time.sleep(100)
