#if 0
#include <iostream>
#include <cstring>

#include "linkedlist.h"
#include "stack.h"
#include "binarytree.h"
#include "binaryheap.h"
#include "BST.h"

using namespace dstl;

void testLL() 
{
    LinkedList<double> n;
    n.push_front(5.66);
    n.push_back(89.90);
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

int main()
{
    testbinarytree();
    //testheapsort();
    //testBST();
    getchar();
    return 0;
}
#endif

#include "gtest/gtest.h"
#include "hashtable.h"
#include "trie.h"

TEST(TrieTest, WorksCorrectly)
{
    dstl::Trie trie;
    trie.insert(std::string("hello"));
    trie.insert(std::string("hell"));
    EXPECT_FALSE(trie.exists(std::string("bye")));
    EXPECT_TRUE(trie.exists(std::string("hello")));
    EXPECT_FALSE(trie.exists(std::string("helloj")));
    EXPECT_FALSE(trie.exists(std::string("hel")));
    EXPECT_TRUE(trie.exists(std::string("hell")));
}

TEST(HashTableTest, WorksCorrectly)
{
    dstl::HashTable<int, int> mp;
    //HashTable<std::string,int> mp1;
    mp.insert(30, 40);
    ASSERT_EQ(mp.get(30), 40);
    mp.insert(130, 50);
    mp.insert(30, 140);
    ASSERT_EQ(mp.get(130), 50);
    ASSERT_EQ(mp.get(30), 140);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    std::getchar(); // keep console window open until Return keystroke
}

