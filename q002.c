#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef bool (*removeNodeFuncT)(const struct ListNode *node);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    struct ListNode *list = NULL;
    struct ListNode *prev = NULL;
    struct ListNode *curr1 = l1;
    struct ListNode *curr2 = l2;
    int currVal = 0;
    int val = 0;
    while (curr1 && curr2) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        memset(node, '\0', sizeof(struct ListNode));
        if (!list) {
            list = node;
        }
        if (prev) {
            prev->next = node;
        }
        currVal = curr1->val + curr2->val + val;
        node->val = currVal % 10;
        val = currVal / 10;
        curr1 = curr1->next;
        curr2 = curr2->next;
        prev = node;
    }
    struct ListNode *curr = curr1 ?: curr2;
    while (val) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        memset(node, '\0', sizeof(struct ListNode));
        if (prev) {
            prev->next = node;
        }
        if (curr) {
            currVal = curr->val + val;
        } else {
            currVal = val;
        }
        node->val = currVal % 10;
        val = currVal / 10;
        if (curr) {
            curr = curr->next;
        }
        prev = node;
    }
    prev->next = curr;
    return list;
}

void printList(struct ListNode **head) {
    printf("list(%p):\n", *head);
    for (struct ListNode **curr = head; *curr; ) {
        struct ListNode *node = *curr;
        if (node) {
            printf("\tval: %d\n", node->val);
            curr = &node->next;
        }
    }
    printf("\n");
}

bool shouldRemoveNode(const struct ListNode *node) {
    // return (2 == node->val);
    return true;
}

void removeList(struct ListNode **head, removeNodeFuncT rm){
    for (struct ListNode **curr = head; *curr; ) {
        struct ListNode *node = *curr;
        if (rm(node)) {
            *curr = node->next;
            free(node);
        } else {
            curr = &node->next;
        }
    }
}

int main(int argc, const char *argv[]) {
    size_t size = sizeof(struct ListNode);
    /**
     * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
     * 输出：7 -> 0 -> 8
     * 原因：342 + 465 = 807
     */
    struct ListNode *list10 = malloc(size);
    memset(list10, '\0', size);
    
    struct ListNode *list11 = malloc(size);
    memset(list11, '\0', size);
    
    struct ListNode *list12 = malloc(size);
    memset(list12, '\0', size);
    
    list10->val = 2;
    list10->next = list11;
    
    list11->val = 4;
    list11->next = list12;
    
    list12->val = 3;
    list12->next = NULL;
    
    struct ListNode *list20 = malloc(size);
    memset(list20, '\0', size);
    
    struct ListNode *list21 = malloc(size);
    memset(list21, '\0', size);
    
    struct ListNode *list22 = malloc(size);
    memset(list22, '\0', size);
    
    list20->val = 5;
    list20->next = list21;
    
    list21->val = 6;
    list21->next = list22;
    
    list22->val = 4;
    list22->next = NULL;
    
    printList(&list10);
    printList(&list20);
    
    struct ListNode *ret = addTwoNumbers(list10, list20);
    printList(&ret);
    
    bool shouldRemoveReturnedList = (ret != list10 && ret != list20);
    
    removeList(&list10, &shouldRemoveNode);
    list10 = NULL;
    
    removeList(&list20, &shouldRemoveNode);
    list20 = NULL;
    
    if (shouldRemoveReturnedList) {
        removeList(&ret, &shouldRemoveNode);
        ret = NULL;
    }
    
    return EXIT_SUCCESS;
}
