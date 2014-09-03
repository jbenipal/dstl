#pragma once

#include <iostream>
#include <array>
#include <algorithm>
#include <memory>

namespace {
    const size_t MAX_ALPHABETS = 26;
}

namespace dstl {
    struct TrieNode {
        TrieNode(char value = ' ')
        : value_(value)
        , is_leaf_(false)
        {
            for_each(begin(children_), end(children_), [](std::shared_ptr<TrieNode> &child)
            {
                child = nullptr;
            });
        }

        char value_;
        bool is_leaf_;
        std::array<std::shared_ptr<TrieNode>, MAX_ALPHABETS> children_;
    };

    class Trie {
    public:
        Trie()
            : root(nullptr)
        {}
        void insert(std::string &key);
        bool exists(const std::string& key) const;
    private:
        std::shared_ptr<TrieNode> root;
    };

}