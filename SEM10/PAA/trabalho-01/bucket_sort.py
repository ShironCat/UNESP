#! /usr/bin/env python

from insertion_sort import insertion_sort


def bucket_sort(A):
    max_value = max(A)
    size = max_value/len(A)

    buckets_list = []
    for i in range(len(A)):
        buckets_list.append([])

    for i in range(len(A)):
        j = int(A[i] / size)
        if j != len(A):
            buckets_list[j].append(A[i])
        else:
            buckets_list[len(A) - 1].append(A[i])

    for z in range(len(A)):
        insertion_sort(buckets_list[z])

    final_output = []
    for i in range(len(A)):
        final_output = final_output + buckets_list[i]
    for i in range(len(final_output)):
        A[i] = final_output[i]


if __name__ == "__main__":
    A = [4, 3, 2, 1]
    bucket_sort(A)
    print(A)
