#! /usr/bin/env python

def shell_sort(A):
    interval = len(A) // 2
    while interval > 0:
        for i in range(interval, len(A)):
            temp = A[i]
            j = i
            while j >= interval and A[j - interval] > temp:
                A[j] = A[j - interval]
                j -= interval
            A[j] = temp
        interval //= 2


if __name__ == "__main__":
    A = [4, 3, 2, 1]
    shell_sort(A)
    print(A)
