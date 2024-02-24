#include "tree.h"

namespace s21 {
    template<class Key, class Value>
    tree<Key, Value>::TreeNode::TreeNode(Key key, Value valueType) : m_Key(key), m_Value(valueType) {}

    template<class Key, class Value>
    tree<Key, Value>::TreeNode::TreeNode(Key key, Value valueType, TreeNode* parent) : m_Key(key), m_Value(valueType), m_Parent(parent)  {}

    template<class Key, class Value>
    tree<Key, Value>::tree() : m_Root(nullptr) {}

    template<class Key, class Value>
    tree<Key, Value>::tree(const tree<Key, Value> &other) {
        m_Root = copyTree(other.m_Root, nullptr);
    }

    template<class Key, class Value>
    tree<Key, Value>::tree(tree<Key, Value> &&other)  noexcept {
        m_Root = other.m_Root;
        other.m_Root = nullptr;
    }

    template<class Key, class Value>
    tree<Key, Value>::~tree() {
        clear();
    }

    template <typename Key, typename Value>
    typename tree<Key, Value>::TreeNode *tree<Key, Value>::copyTree(tree::TreeNode *node, tree::TreeNode *parent) {
        if (node == nullptr) return nullptr;
        auto *new_node = new TreeNode(node->m_Key, node->m_Value, parent);
        new_node->m_Left = copyTree(node->m_Left, new_node);
        new_node->m_Right = copyTree(node->m_Right, new_node);
        return new_node;
    }

    template<class Key, class Value>
    void tree<Key, Value>::freeNode(TreeNode* node) {
        if(node != nullptr) {
            freeNode(node->m_Right);
            freeNode(node->m_Left);
            delete node;
        }
    }

    template<class Key, class Value>
    typename tree<Key, Value>::TreeNode *tree<Key, Value>::getMax(tree::TreeNode *node) {
        if (node != nullptr) return nullptr;
        if (node->m_Right == nullptr) return node;
        return getMax(node->m_Right);
    }

    template<class Key, class Value>
    typename tree<Key, Value>::TreeNode *tree<Key, Value>::getMin(tree::TreeNode *node) {
        if (node != nullptr) return nullptr;
        if (node->m_Left == nullptr) return node;
        return getMax(node->m_Left);
    }

    template<class Key, class Value>
    void tree<Key, Value>::swapKeyValue(tree::TreeNode *a, tree::TreeNode *b) {
        std::swap(a->m_Key, b->m_Key);
        std::swap(a->m_Value, b->m_Value);
    }

    template<class Key, class Value>
    int tree<Key, Value>::getHeight(tree::TreeNode *node) {
        return node == nullptr ? -1 : node->m_Height;
    }

    template<class Key, class Value>
    void tree<Key, Value>::autoSetHeight(tree::TreeNode *node) {
        node->m_Height = std::max(getHeight(node->m_Right), getHeight(node->m_Left)) + 1;
    }

    template<class Key, class Value>
    int tree<Key, Value>::getBalance(tree::TreeNode *node) {
        return node == nullptr ? 0 : getHeight(node->m_Right) - getHeight(node->m_Left);
    }

    template<class Key, class Value>
    void tree<Key, Value>::rightRotate(tree::TreeNode *node) {
        TreeNode *left_left_node = node->m_Left->m_Left;
        TreeNode *right_node = node->m_Right;
        TreeNode *left_right_node = node->m_Left->m_Right;

        swapKeyValue(node, node->m_Left);
        node->m_Right = node->m_Left;

        node->m_Left = left_left_node;
        if (node->m_Left) {
            node->m_Left->m_Parent = node;
        }

        node->m_Right->m_Left = left_right_node;
        if (node->m_Right->m_Left) {
            node->m_Right->m_Left->m_Parent = node->m_Right;
        }

        node->m_Right->m_Right = right_node;
        if (node->m_Right->m_Right) {
            node->m_Right->m_Right->m_Parent = node->m_Right;
        }

        autoSetHeight(node->m_Right);
        autoSetHeight(node);
    }

    template<class Key, class Value>
    void tree<Key, Value>::leftRotate(tree::TreeNode *node) {
        TreeNode *right_right_node = node->m_Right->m_Right;
        TreeNode *left_node = node->m_Left;
        TreeNode *right_left_node = node->m_Right->m_Left;

        swapKeyValue(node, node->m_Right);
        node->m_Left = node->m_Right;

        node->m_Right = right_right_node;
        if(node->m_Right) {
            node->m_Right->m_Parent = node;
        }

        node->m_Left->m_Right = right_left_node;
        if (node->m_Left->m_Right) {
            node->m_Left->m_Right->m_Parent = node->m_Left;
        }

        node->m_Left->m_Left = left_node;
        if (node->m_Left->m_Left) {
            node->m_Left->m_Left->m_Parent = node->m_Left;
        }

        autoSetHeight(node->m_Left);
        autoSetHeight(node);
    }

    template<class Key, class Value>
    void tree<Key, Value>::balance(tree::TreeNode *node) {
        int balance = getBalance(node);
        if (balance == -2) {
            if (getBalance(node->m_Right) == 1) {
                leftRotate(node->m_Left);
            } else {
                rightRotate(node);
            }
        } else if (balance == 2) {
            if (getBalance(node->m_Right) == -1) {
                rightRotate(node->m_Right);
            } else {
                leftRotate(node);
            }
        }
    }

    template<class Key, class Value>
     typename tree<Key, Value>::size_type tree<Key, Value>::recursiveSize(tree::TreeNode *node) {
        if (node == nullptr) return 0;
        size_type left_size = recursiveSize(node->m_Left);
        size_type right_size = recursiveSize(node->m_Right);
        return left_size + right_size + 1;
     }

    template<class Key, class Value>
    typename tree<Key, Value>::TreeNode *tree<Key, Value>::binarySearch(tree::TreeNode *node, const Key &key) {
        if (node == nullptr || node->m_Key == key) return key;
        if (key > node->m_Key) {
            return binarySearch(node->m_Right, key);
        } else {
            return binarySearch(node->m_Left, key);
        }
    }

    template<class Key, class Value>
    bool tree<Key, Value>::recursiveInsert(tree::TreeNode *node, const Key &key, Value value) {
        bool inserted = false;
        if (key < node->m_Key) {
            if (node->m_Left == nullptr) {
                auto new_node = new TreeNode(key, value, node);
                inserted = true;
            } else {
                inserted = recursiveInsert(node->m_Left, key, value);
            }
        } else if (key > node->m_Key) {
            if (node->m_Right == nullptr) {
                auto new_node = new TreeNode(key, value, node);
                inserted = true;
            } else {
                inserted = recursiveInsert(node->m_Right, key, value);
            }
        } else if (key == node->m_Key) {
            return inserted;
        }
        autoSetHeight(node);
        balance(node);
        return inserted;
    }

    template<class Key, class Value>
    typename tree<Key, Value>::TreeNode *tree<Key, Value>::recursiveDelete(tree::TreeNode *node, tree::key_type key) {
        if (node == nullptr) return nullptr;
        if (key < node->m_Key) {
            node->m_Left = recursiveDelete(node->m_Left, key);
        } else if (key > node->m_Key) {
            node->m_Right = recursiveDelete(node->m_Right, key);
        } else {
            if (node->m_Left == nullptr || node->m_Right == nullptr) {
                auto node_right = node->m_Right;
                auto node_left = node->m_Left;
                auto node_parent = node->m_Parent;

                delete node;
                if (node->m_Left == nullptr) {
                    node = node_right;
                } else {
                    node = node_left;
                }
                if (node != nullptr) node->m_Parent = node_parent;
            } else {
                TreeNode* min_in_right = getMin(node->m_Right);
                node->m_Key = min_in_right->m_Key;
                node->m_Value = min_in_right->m_Value;
                node->m_Right = recursiveDelete(node->m_Right, min_in_right->m_Key);
            }
        }
        if (node != nullptr) {
            autoSetHeight(node);
            balance(node);
        }
        return node;
    }

    template<class Key, class Value>
    bool tree<Key, Value>::empty() {
        return m_Root == nullptr;
    }

    template<class Key, class Value>
    typename tree<Key, Value>::size_type tree<Key, Value>::size() {
        return recursiveSize(m_Root);
    }

    template<class Key, class Value>
    typename tree<Key, Value>::size_type tree<Key, Value>::max_size() {
        return std::numeric_limits<size_type>::max() / sizeof(typename tree<Key, Value>::TreeNode);
    }

    template<class Key, class Value>
    void tree<Key, Value>::clear() {
        if (m_Root != nullptr) freeNode(m_Root);
        m_Root = nullptr;
    }

    template<class Key, class Value>
    void tree<Key, Value>::swap(tree<Key, Value> &other) {
        std::swap(this->m_Root, other.m_Root);
    }

    template<class Key, class Value>
    bool tree<Key, Value>::contains(const Key &key) {
        auto containsNode = binarySearch(m_Root, key);
        return containsNode != nullptr;
    }

    template<class Key, class Value>
    tree<Key, Value>::Iterator::Iterator() : m_Iter_Node(nullptr), m_Iter_Past_Node(nullptr) {}

    template<class Key, class Value>
    tree<Key, Value>::Iterator::Iterator(tree::TreeNode *node, tree::TreeNode *past_node) : m_Iter_Node(node), m_Iter_Past_Node(past_node) {}

    template<class Key, class Value>
    tree<Key, Value>::Iterator::
}