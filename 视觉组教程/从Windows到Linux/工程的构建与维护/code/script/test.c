#include <stdio.h>
#include <stdlib.h>

#define MALLOC_N(ptr, n) (typeof(ptr))malloc(n * sizeof(*ptr))

struct ListNodeInt {
    struct ListNodeInt* next;
    int data;
};

struct ListNodeInt* CreateListNode(int data) {
    struct ListNodeInt* node = MALLOC_N(node, 1);
    node->data = data;
    return node;
}

int ListPushFrontNewNode(struct ListNodeInt** head, int data) {
    if (!*head) return -1;
    struct ListNodeInt* new_head = CreateListNode(data);
    new_head->next = *head;
    *head = new_head;
    return 0;
}

int ListPushFrontNode(struct ListNodeInt** head, struct ListNodeInt* new_head) {
    if (!*head) return -1;
    new_head->next = *head;
    *head = new_head;
    return 0;
}

int ListPushNextNewNode(struct ListNodeInt* node, int data) {
    if (!node) return -1;
    struct ListNodeInt* next_node = CreateListNode(data);
    node->next = next_node;
    return 0;
}

int ListPushNextNode(struct ListNodeInt* node, struct ListNodeInt* next_node) {
    if (!node) return -1;
    node->next = next_node;
    return 0;
}

int ListRemoveNode(struct ListNodeInt** head) {
    if (!*head) return -1;
    struct ListNodeInt* new_head = (*head)->next;
    free(*head);
    *head = new_head;
    return 0;
}

int ListRemoveNextNode(struct ListNodeInt* head) {
    if (!head) return -1;
    struct ListNodeInt* new_next = head->next->next;
    free(head->next);
    head->next = new_next;
    return 0;
}

void ListForEach(struct ListNodeInt* head,
                 void (*func)(struct ListNodeInt* head)) {
    struct ListNodeInt* ptr = head;
    while (ptr) {
        func(ptr);
        ptr = ptr->next;
    }
    return;
}

void FreeList(struct ListNodeInt** head_ptr) {
    struct ListNodeInt* ptr = *head_ptr;
    while (ptr) {
        struct ListNodeInt* next_node = ptr->next;
        free(ptr);
        ptr = next_node;
    }
    *head_ptr = NULL;
    return;
}

void PrintListNodeInfo(struct ListNodeInt* node) {
    printf("(this node address->%p;next address->%p;data->%d.)|", node,
           node->next, node->data);
    return;
}

int main() {
    printf("{\n[init]|");
    struct ListNodeInt* head = NULL;
    struct ListNodeInt* last_head = CreateListNode(12);
    struct ListNodeInt* last_next = CreateListNode(123);
    ListForEach(head, PrintListNodeInfo);
    printf("\n}\n");

    printf("{\n[create head node]|");
    head = CreateListNode(1234);
    ListForEach(head, PrintListNodeInfo);
    printf("\n}\n");

    printf("{\n[push next new nodes]|");
    ListPushNextNewNode(head, 12345);
    ListPushNextNewNode(head->next, 123456);
    ListForEach(head, PrintListNodeInfo);
    printf("\n}\n");

    printf("{\n[push front new nodes]|");
    ListPushFrontNewNode(&head, 123);
    ListPushFrontNewNode(&head, 12);
    ListForEach(head, PrintListNodeInfo);
    printf("\n}\n");

    printf("{\n[remove next head]|");
    ListRemoveNextNode(head);
    ListForEach(head, PrintListNodeInfo);
    printf("\n}\n");

    printf("{\n[remove head]|");
    ListRemoveNode(&head);
    ListForEach(head, PrintListNodeInfo);
    printf("\n}\n");

    printf("{\n[push next node]|");
    last_next->next = head->next;
    ListPushNextNode(head, last_next);
    //  ListPushNextNode(last_next, head); /* this is loop */
    ListForEach(head, PrintListNodeInfo);
    printf("\n}\n");

    printf("{\n[push front node]|");
    ListPushFrontNode(&head, last_head);
    ListForEach(head, PrintListNodeInfo);
    printf("\n}\n");

    printf("{\n[free]|");
    FreeList(&head);
    ListForEach(head, PrintListNodeInfo);
    printf("\n}\n");

    return 0;
}
