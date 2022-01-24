#! /usr/bin/env python

def partition(A, low, high):
    i = (low-1)
    pivot = A[high]
    for j in range(low, high):
        if A[j] <= pivot:
            i = i+1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[high] = A[high], A[i+1]
    return (i+1)


def quick_sort(A, low, high):
    if low < high:
        pi = partition(A, low, high)
        quick_sort(A, low, pi-1)
        quick_sort(A, pi+1, high)


if __name__ == "__main__":
    A = [4, 3, 2, 1]
    quick_sort(A, 0, len(A) - 1)
    print(A)
