#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for BFS
struct Pair {
    struct Node* node;
    int hd;
};

struct Pair queue[1000];
int front = 0, rear = 0;

void push(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct Pair pop() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[1000];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (f < r && i < n) {
        struct Node* curr = q[f++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    int minHD = 0, maxHD = 0;

    // temporary storage
    int map[2000][100];
    int count[2000] = {0};

    push(root, 0);

    while (!isEmpty()) {
        struct Pair p = pop();
        struct Node* node = p.node;
        int hd = p.hd;

        int index = hd + 1000; // shift to avoid negative index

        map[index][count[index]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            push(node->left, hd - 1);

        if (node->right)
            push(node->right, hd + 1);
    }

    // print result
    for (int i = minHD; i <= maxHD; i++) {
        int index = i + 1000;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", map[index][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}
