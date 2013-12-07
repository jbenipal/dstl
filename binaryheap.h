#include <iostream>

template <typename T>
class BinaryHeap {
public:
    void heapsort(T a[], int size);
private:
    void buildheap(T a[], int size);
    void heapify(T a[], int index, int heapsize);
    int Parentof(int i) { return (i-1)/2; }
    int leftchild(int i) { return 2*i + 1; }
    int rightchild(int i) { return 2*i + 2; }
};