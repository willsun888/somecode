#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    struct Node* left;
    struct Node* right;
    char val;
};

struct Node* newNode(char val, struct Node* left, struct Node* right) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = left;
    node->right = right;
    node->val = val;
    return node;
}

int sumtree(struct Node* head) {
    if (!head) {
        return 0;
    }
    int left = 0;
    if (head->left) {
        left = sumtree(head->left);
    }
    int right = 0;
    if (head->right) {
        right = sumtree(head->right);
    }
    switch (head->val) {
        case '+':
            return left+right;
        case '-':
            return left-right;
        case '*':
            return left*right;
        case '/':
            return left/right;
        default:
            return head->val-'0';
    }
}

void testcase1()
{
    struct Node* head = newNode('*',
            newNode('+',
                newNode('3', NULL, NULL),
                newNode('2', NULL, NULL)
            ),
            newNode('+',
                newNode('4', NULL, NULL),
                newNode('5', NULL, NULL)
            )
        );
    int sum = sumtree(head);
    printf("sum:%d\n", sum);
}

void testcase2()
{
    struct Node* head = newNode('*',
            newNode('+',
                newNode('-',
                    newNode('3', NULL, NULL),
                    newNode('6', NULL, NULL)
                ),
                newNode('9', NULL, NULL)
            ),
            newNode('+',
                newNode('*',
                    newNode('2', NULL, NULL),
                    newNode('4', NULL, NULL)
                ),
                newNode('5', NULL, NULL)
            )
        );
    int sum = sumtree(head);
    printf("sum:%d\n", sum);

}

int main()
{
    testcase2();
    return 0;
}
