#pragma once
#include <iostream>

template<typename T>
class TreeNode {
public:
    TreeNode(const T& value) : data(value), parent(nullptr), children(nullptr), childrenCount(0) {}
    ~TreeNode() {
        deleteChildren();
    };

    const T& getData() const {
        return data;
    }

    TreeNode<T>* getParent() {
        return parent;
    }

    size_t getChildrenCount() const {
        return childrenCount;
    }

    TreeNode<T>* getChild(size_t index) {
        return children[index];
    }

    void addChild(TreeNode<T>* child) {
        child->setParent(this);
        TreeNode<T>** newChildren = new TreeNode<T>*[childrenCount + 1];
        for (size_t i = 0; i < childrenCount; ++i) {
            newChildren[i] = children[i];
        }
        newChildren[childrenCount] = child;
        ++childrenCount;
        delete[] children;
        children = newChildren;
    }

    void removeChild(TreeNode<T>* child) {
        size_t childIndex = 0;
        while (childIndex < childrenCount && children[childIndex] != child) {
            ++childIndex;
        }
        if (childIndex == childrenCount) {
            return; // Child not found
        }
        delete child;
        for (size_t i = childIndex; i < childrenCount - 1; ++i) {
            children[i] = children[i + 1];
        }
        --childrenCount;
    }

    void sortChildren(bool (*compare)(const T&, const T&) = nullptr) {
        for (size_t i = 0; i < childrenCount - 1; ++i) {
            for (size_t j = i + 1; j < childrenCount; ++j) {
                if (compare ? compare(children[i]->getData(), children[j]->getData()) : children[i]->getData() > children[j]->getData()) {
                    TreeNode<T>* temp = children[i];
                    children[i] = children[j];
                    children[j] = temp;
                }
            }
        }
    }

    TreeNode<T>* findNode(const T& value, bool (*equals)(const T& lhs, const T& rhs) = nullptr) {
        if ((equals && equals(data, value)) || (!equals && data == value)) {
            return this;
        }
        for (size_t i = 0; i < childrenCount; ++i) {
            TreeNode<T>* found = children[i]->findNode(value, equals);
            if (found) {
                return found;
            }
        }
        return nullptr;
    }

private:
    T data;
    TreeNode<T>* parent;
    TreeNode<T>** children;
    size_t childrenCount;

    void deleteChildren() {
        for (size_t i = 0; i < childrenCount; ++i) {
            delete children[i];
        }
        delete[] children;
    }

    void setParent(TreeNode<T>* p) {
        parent = p;
    }
};

template<typename T>
class Tree {
public:
    Tree() : root(nullptr) {}
    ~Tree() {
        delete root;
    }

    TreeNode<T>* getRoot() {
        return root;
    }

    void addNode(TreeNode<T>* parent, const T& value) {
        TreeNode<T>* newNode = new TreeNode<T>(value);
        if (!parent) {
            root = newNode;
        } else {
            parent->addChild(newNode);
        }
    }

    void removeNode(TreeNode<T>* node) {
        if (!node) {
            return;
        }
        if (!node->getParent()) {
            delete root;
            root = nullptr;
        } else {
            node->getParent()->removeChild(node);
        }
    }

    TreeNode<T>* getNode(TreeNode<T>* parent, size_t index) {
        return parent ? parent->getChild(index) : nullptr;
    }

    void insertNode(TreeNode<T>* parent, const T& value, size_t index) {
        if (parent) {
            TreeNode<T>* newNode = new TreeNode<T>(value);
            parent->addChild(newNode);
        }
    }

    size_t countNodes(TreeNode<T>* node) const {
        return node ? node->getChildrenCount() + 1 : 0;
    }

    TreeNode<T>* find(const T& value, bool(*equals)(const T& lhs, const T& rhs) = nullptr) {
        return root ? root->findNode(value, equals) : nullptr;
    }

    void sort(TreeNode<T>* node, bool (*compare)(const T&, const T&) = nullptr) {
        if (node) {
            node->sortChildren(compare);
        }
    }

private:
    TreeNode<T>* root;
};
