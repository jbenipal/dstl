#include "trie.h"

namespace dstl {

void
Trie::insert(std::string &key)
{
    if (root == nullptr) {
        root = std::shared_ptr<TrieNode>(new TrieNode());;
    }

    std::shared_ptr<TrieNode> curr_node = root;
    for (const auto &c : key) {
        if (curr_node->children_[int(c) - 97] == nullptr) {
            curr_node->children_[int(c) - 97] = std::shared_ptr<TrieNode>(new TrieNode(c));
        }
        curr_node = curr_node->children_[int(c) - 97];
    }

    curr_node->is_leaf_ = true;
}

bool
Trie::exists(const std::string &key) const
{
    std::shared_ptr<TrieNode> curr_node = root;
    if (curr_node == nullptr)
        return false;
    for (auto c : key) {
        if (curr_node->children_[int(c) - 97])
            curr_node = curr_node->children_[int(c) - 97];
        else
            return false;
    }
    return curr_node->is_leaf_;
}
}