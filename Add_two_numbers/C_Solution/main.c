#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;

        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = sum % 10;
        current->next->next = NULL;
        current = current->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    if (carry > 0) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = carry;
        current->next->next = NULL;
    }

    struct ListNode* result = dummyHead->next;
    free(dummyHead);
    return result;
}

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d", node->val);
        if (node->next != NULL) {
            printf(" -> ");
        }
        node = node->next;
    }
    printf("\n");
}

int main(int *argc , int **argv) {
    struct ListNode* l1 = newNode(2);
    l1->next = newNode(4);
    l1->next->next = newNode(3);

    struct ListNode* l2 = newNode(5);
    l2->next = newNode(6);
    l2->next->next = newNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);

    while (result != NULL) {
        struct ListNode* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
