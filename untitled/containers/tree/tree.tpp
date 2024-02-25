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
        if (node == nullptr) return nullptr;
        if (node->m_Left == nullptr) return node;
        return getMin(node->m_Left);
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
        if (node == nullptr || node->m_Key == key) return node;
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
                node->m_Left = new TreeNode(key, value, node);
                inserted = true;
            } else {
                inserted = recursiveInsert(node->m_Left, key, value);
            }
        } else if (key > node->m_Key) {
            if (node->m_Right == nullptr) {
                node->m_Right = new TreeNode(key, value, node);
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
    typename tree<Key, Value>::TreeNode *tree<Key, Value>::Iterator::moveFront(tree::TreeNode *node) {
        if (node->m_Right != nullptr) {
            return getMin(node->m_Right);
        }
        auto parent = node->m_Parent;
        while (parent != nullptr && node == parent->m_Right) {
            node = parent;
            parent = parent->m_Parent;
        }
        return parent;
    }

    template<class Key, class Value>
    typename tree<Key, Value>::TreeNode *tree<Key, Value>::Iterator::moveBack(tree::TreeNode *node) {
        if (node->m_Left != nullptr) {
            return GetMax(node->m_Left);
        }
        auto *parent = node->m_Parent;
        while (parent != nullptr && node == parent->m_Left) {
            node = parent;
            parent = node->m_Parent;
        }
        return parent;
    }

    template<class Key, class Value>
    typename tree<Key, Value>::iterator &tree<Key, Value>::Iterator::operator++() {
        TreeNode* tmp;
        if (m_Iter_Node != nullptr) {
            tmp = getMax(m_Iter_Node);
        }
        m_Iter_Node = moveFront(m_Iter_Node);
        if (m_Iter_Node == nullptr) {
            m_Iter_Past_Node = tmp;
        }
        return *this;
    }

    template<class Key, class Value>
    typename tree<Key, Value>::iterator tree<Key, Value>::Iterator::operator++(int) {
        auto tmp = *this;
        operator++();
        return tmp;
    }

    template<class Key, class Value>
    typename tree<Key, Value>::iterator &tree<Key, Value>::Iterator::operator--() {
        if (m_Iter_Node == nullptr && m_Iter_Past_Node != nullptr) {
            *this = m_Iter_Past_Node;
        }
        m_Iter_Node = moveBack(m_Iter_Node);
        return *this;
    }

    template<class Key, class Value>
    typename tree<Key, Value>::iterator tree<Key, Value>::Iterator::operator--(int) {
        auto tmp = *this;
        operator--();
        return tmp;
    }

    template<class Key, class Value>
    typename tree<Key, Value>::reference tree<Key, Value>::Iterator::operator*() {
        if (m_Iter_Node == nullptr) {
            static Value fake_value{};
            return fake_value;
        }
        return m_Iter_Node->m_Key;
    }

    template<class Key, class Value>
    bool tree<Key, Value>::Iterator::operator==(const tree::iterator &it) {
        return this->m_Iter_Node == it.m_Iter_Node;
    }

    template<class Key, class Value>
    bool tree<Key, Value>::Iterator::operator!=(const tree::iterator &it) {
        return this->m_Iter_Node != it.m_Iter_Node;
    }

    template<class Key, class Value>
    tree<Key, Value> &tree<Key, Value>::operator=(const tree<Key, Value> &other) {
        if (this != &other) {
            m_Root = copyTree(other.m_Root, nullptr);
        }
        return *this;
    }

    template<class Key, class Value>
    tree<Key, Value> &tree<Key, Value>::operator=(tree<Key, Value> &&other) noexcept {
        if (&other != nullptr) {
            this->m_Root = other.m_Root;
            other.m_Root = nullptr;
        }
        return *this;
    }

    template<class Key, class Value>
    typename tree<Key, Value>::iterator tree<Key, Value>::begin() {
        return Iterator(getMin(m_Root));
    }

    template<class Key, class Value>
    typename tree<Key, Value>::iterator tree<Key, Value>::end() {
        if (m_Root == nullptr) return begin();

        auto last_node = getMax(m_Root);
        Iterator test(nullptr, last_node);
        return test;
    }

    template<class Key, class Value>
    void tree<Key, Value>::merge(tree<Key, Value> &other) {
        tree const_tree(other);

        for (auto it = const_tree.begin(); it != const_tree.end(); ++it) {
            std::pair<Iterator, bool>pr = insert(*it);
            if (pr.second) other.erase(pr.first);
        }
    }


    template<class Key, class Value>
    typename tree<Key, Value>::iterator tree<Key, Value>::find(const Key &key) {
        auto element = binarySearch(m_Root, key);
        return element;
    }

    template<class Key, class Value>
    std::pair<typename tree<Key, Value>::iterator, bool> tree<Key, Value>::insert(const Key &key) {
        std::pair<Iterator, bool> result;
        if (m_Root == nullptr) {
            m_Root = new TreeNode(key, key);
            result.first = Iterator(m_Root);
            result.second = true;
        } else {
            bool check_insert = recursiveInsert(m_Root, key, key);
            result.first = find(key);
            result.second = check_insert;
        }
        return result;
    }

    template<class Key, class Value>
    void tree<Key, Value>::erase(tree::iterator pos) {
        if (m_Root == nullptr || pos.m_Iter_Node == nullptr) return;
        m_Root = recursiveDelete(m_Root, pos);
    }
}