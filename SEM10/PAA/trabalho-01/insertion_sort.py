#! /usr/bin/env python

def insertion_sort(A):
    for j in range(len(A)):
        key = A[j]
        i = j - 1
        while i >= 0 and A[i] > key:
            A[i + 1] = A[i]
            i -= 1
        A[i + 1] = key


if __name__ == "__main__":
    A = [4, 3, 2, 1]
    insertion_sort(A)
    print(A)
