#include "binaryheap.h"

namespace dstl {
    template <typename T>
    void
        BinaryHeap<T>::buildheap(T a[], int size)
    {
            for (int i = size / 2; i >= 0; --i) {
                heapify(a, i, size);
            }
        }

    //max heap
    template <typename T>
    void
        BinaryHeap<T>::heapify(T a[], int i, int heapsize)
    {
            int largest = i;
            int left = leftchild(i);
            int right = rightchild(i);

            if (left<heapsize && a[left] > a[largest]) largest = left;
            if (right<heapsize && a[right] > a[largest]) largest = right;

            if (largest != i) {
                std::swap(a[largest], a[i]);
                heapify(a, largest, heapsize);
            }
        }

    template <typename T>
    void
        BinaryHeap<T>::heapsort(T a[], int size)
    {
            buildheap(a, size);
            int n = size;
            for (int i = size - 1; i >= 0; --i) {
                std::swap(a[0], a[i]);
                heapify(a, 0, --n);
            }
        }

    template class BinaryHeap<int>;
}