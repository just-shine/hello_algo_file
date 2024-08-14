#include<stdio.h>
#include<uthash.h>

/* 哈希表 */
typedef struct {
    int key;
    int val;
    UT_hash_handle hh; // 基于 uthash.h 实现
} HashTable;

/* 线性阶 */
void linear(int n) {
    // 长度为 n 的数组占用 O(n) 空间
    int *nums = malloc(sizeof(int) * n);
    free(nums);

    // 长度为 n 的列表占用 O(n) 空间
    ListNode **nodes = malloc(sizeof(ListNode *) * n);
    for (int i = 0; i < n; i++) {
        nodes[i] = newListNode(i);
    }
    // 内存释放
    for (int i = 0; i < n; i++) {
        free(nodes[i]);
    }
    free(nodes);

    // 长度为 n 的哈希表占用 O(n) 空间
    HashTable *h = NULL;
    for (int i = 0; i < n; i++) {
        HashTable *tmp = malloc(sizeof(HashTable));
        tmp->key = i;
        tmp->val = i;
        HASH_ADD_INT(h, key, tmp);
    }

    // 内存释放
    HashTable *curr, *tmp;
    HASH_ITER(hh, h, curr, tmp) {
        HASH_DEL(h, curr);
        free(curr);
    }
}