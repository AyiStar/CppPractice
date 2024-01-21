// https://leetcode.com/problems/implement-trie-prefix-tree
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <unordered_map>


class Trie {

private:
    struct TrieNode {
        bool is_word;
        std::unordered_map<char, TrieNode*> children;
    };

public:
    Trie() {
        root_ = new TrieNode();
    }
    
    void insert(std::string word) {
        TrieNode *p = root_;
        for (char c: word) {
            if (auto it = p->children.find(c); it != p->children.end()) {
                p = it->second;
            } else {
                auto child = new TrieNode();
                p->children.insert({c, child});
                p = child;
            }
        }
        p->is_word = true;
    }
    
    bool search(std::string word) {
        TrieNode *p = root_;
        for (char c: word) {
            if (auto it = p->children.find(c); it != p->children.end()) {
                p = it->second;
            } else {
                return false;
            }
        }
        return (p->is_word);
    }
    
    bool startsWith(std::string prefix) {
        TrieNode *p = root_;
        for (char c: prefix) {
            if (auto it = p->children.find(c); it != p->children.end()) {
                p = it->second;
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode *root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


TEST_CASE("EXAMPLE") {
    Trie *obj = new Trie();
    obj->insert("apple");
    REQUIRE(obj->search("apple"));
    REQUIRE(!obj->search("app"));
    REQUIRE(obj->startsWith("app"));
    obj->insert("app");
    REQUIRE(obj->search("app"));
}