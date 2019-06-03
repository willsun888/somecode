#include<iostream>

using namespace std;

struct Node {
    int childLockNum;
    bool locked;
    Node* parent;
    Node* left;
    Node* right;
};

bool is_locked(Node* node) {
    return node->locked;
}

bool is_child_can_lock(Node* node) {
    if (node == NULL) {
        return true;
    }
    if (node->locked) {
        return false;
    }
    if (!is_child_can_lock(node->left)) {
        return false;
    }
    if (!is_child_can_lock(node->right)) {
        return false;
    }
    return true;
}

bool canLockOrUnlock(Node* node) {
    Node* n = node;
    while (n) {
        if (n->locked) {
            return false;
        }
        n = n->parent;
    }
    if (node && node->childLockNum) {
        return false;
    }
    return true;
}

bool lock(Node* node) {
    if (node->locked) {
        return false;
    }
    if (!canLockOrUnlock(node)) {
        return false;
    }
    node->locked = true;
    Node* n = node->parent;
    while (n) {
        n->childLockNum++;
        n = n->parent;
    }
    return true;
}

bool unlock(Node* node) {
    if (!node->locked) {
        return false;
    }
    if (!canLockOrUnlock(node)) {
        return false;
    }
    node->locked = false;
    Node* n = node->parent;
    while (n) {
        n->childLockNum--;
        n = n->parent;
    }
    return true;
}

int main()
{

    return 0;
}
