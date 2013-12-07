#include <iostream>
#include <cstring>

#include "linkedlist.h"
#include "stack.h"
#include "binarytree.h"
#include "binaryheap.h"
#include "BST.h"
#include "hashtable.h"

using namespace dstl;

void testLL() 
{
    LinkedList<double> n;
    n.insert_at_beg(5.66);
    n.insert_at_end(89.90);
    n.printlist();
}

void testStack() 
{
    Stack<int> stack;
    int temp;
    stack.push(5);
    stack.pop(&temp);
    std::cout << temp;
}

void testbinarytree() 
{
    BinaryTree<int> bt;
    bt.createtree();
    //bt.preorder_r();
    //bt.inorder_r();
    //bt.postorder_r();
    //bt.preorder();
    //bt.inorder();
    //bt.levelorder();
    bt.postorder();
    //int path[10];
    //bt.printallpaths(path, 0);
    //std::cout << bt.checkpathsum2(7);
    //bt.levelorder();
    //bt.mirror2();
    //bt.levelorder();
    //int inorder[] = {4,2,5,1,6,3,7 };
    //int preorder[] = {1,2,4,5,3,6,7};
    //int size = sizeof(preorder)/sizeof(preorder[0]);
    //bt.setroot(bt.buildtree(inorder, preorder, 0, size));
}

void testheapsort()
{
    int a[] = {4,2,5,1,6,3,7};
    BinaryHeap<int> bh;
    bh.heapsort(a, 7);

    for(int i=0;i<7;++i)
        std::cout << a[i] << ",";
}

void testBST()
{
    BST<int> bst;
    BinaryNode<int> *root;
    bst.insert(5);
    bst.insert(9);
    bst.insert(8);
    bst.insert(7);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);

    std::cout << "Before:";
    bst.inorder();
    std::cout << std::endl;
    
    root = bst.getroot();
    if(root) std::cout << "Root:" << root->item << std::endl;
    
    bst.deleteitem(5);
    
    std::cout << "After:";
    bst.inorder();
    std::cout << std::endl;

    root = bst.getroot();
    if(root) std::cout << "Root:" << root->item << std::endl;
}

void testhashtable()
{
    HashTable<int,int> mp;
    //HashTable<std::string,int> mp1;
    mp.insert(30,40);
    std::cout << "Key 30:" << mp.get(30) << std::endl;
    mp.insert(130,50);
    mp.insert(30,140);
    std::cout << "Key 30:" << mp.get(30) << std::endl;
    std::cout << "Key 130:" << mp.get(130) << std::endl;
}

int main()
{
    testbinarytree();
    //testheapsort();
    //testBST();
    //testhashtable();
    getchar();
    return 0;
}

