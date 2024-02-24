#ifndef CONTAINERS_TREE_H
#define CONTAINERS_TREE_H

#include <algorithm>
#include <cstdio>
#include <initializer_list>

namespace s21 {
    template<class Key, class Value>
    class tree {
    protected:
        struct TreeNode;
    public:
        class Iterator;
        class ConstIterator;

        using key_type = Key;
        using value_type = Value;
        using reference = value_type&;
        using const_reference = const value_type&;
        using iterator = Iterator;
        using const_iterator = ConstIterator;
        using size_type = size_t;

        class Iterator {
        public:
            Iterator();
            Iterator(TreeNode* node, TreeNode* past_node = nullptr);
            iterator& operator++();
            iterator operator++(int);
            iterator& operator--();
            iterator operator--(int);
            reference operator*();
            bool operator==(const iterator& it);
            friend class tree<key_type, value_type>;
            bool operator!=(const iterator& it);
        protected:
            TreeNode* m_Iter_Node;
            TreeNode* m_Iter_Past_Node;
            TreeNode* moveFront(TreeNode* node);
            TreeNode* moveBack(TreeNode* node);
        };

        class ConstIterator : public Iterator {
            ConstIterator() : Iterator() {}
            const_reference operator*() const { return Iterator::operator*(); };
        };

        tree();
        tree(const tree& other);
        tree(tree&& other) noexcept;
        ~tree();

//        tree& operator=(tree&& other) noexcept;
//        tree& operator=(const tree& other);

//        iterator begin();
//        iterator end();

        bool empty();
        size_type size();
        size_type max_size();
        void clear();
//        std::pair<iterator, bool> insert(const Key& key);
//        void erase(iterator pos);
        void swap(tree& other);
//        void merge(tree& other);
        bool contains(const Key& key);

    protected:
        struct TreeNode {
            TreeNode(Key key, Value valueType);
            TreeNode(Key key, Value valueType, TreeNode* parent);

            Key m_Key;
            Value m_Value;
            TreeNode* m_Left = nullptr;
            TreeNode* m_Right = nullptr;
            TreeNode* m_Parent = nullptr;
            int m_Height = 0;
            friend class tree<Key, Value>;
        };
        TreeNode* m_Root;

        void freeNode(TreeNode* node);
        TreeNode* copyTree(TreeNode* node, TreeNode* parent);

        // Balance
        void balance(TreeNode* node); // <- that was a goal
        int getHeight(TreeNode *node);
        void autoSetHeight(TreeNode *node);
        int getBalance(TreeNode* node);
        void swapKeyValue(TreeNode* a, TreeNode* b);
        void rightRotate(TreeNode* node);
        void leftRotate(TreeNode* node);

        static TreeNode* getMin(TreeNode* node);
        static TreeNode* getMax(TreeNode* node);

        bool recursiveInsert(TreeNode* node, const Key& key, Value value);
        TreeNode* recursiveDelete(TreeNode *node, key_type key);
        size_type recursiveSize(TreeNode* node);
        TreeNode* binarySearch(TreeNode* node, const Key& key);
    };

}

#include "tree.tpp"

#endif // CONTAINERS_TREE_H
