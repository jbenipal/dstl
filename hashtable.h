#include<iostream>

template <typename T, typename U>
struct HashNode
{
    HashNode(T key, U value)
        : key(key)
        , value(value)
    { }

    T key;
    U value;
    HashNode<T,U> *next;
};
template struct HashNode<int,int>;
template struct HashNode<std::string,int>;

template <typename T, typename U>
class HashTable {
public:
    HashTable();
    ~HashTable();
    void insert(T key, U value);
    U get(T key);
private:
    int hashfunction(T key);
    static const int MAX_SIZE = 100;
    HashNode<T,U>* hashtable[MAX_SIZE];
};