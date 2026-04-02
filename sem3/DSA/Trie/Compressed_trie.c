#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct radixNode {
    char *label;                    // edge label
    int EOW;                        // end of word
    struct radixNode *child;        // first child
    struct radixNode *sibling;      // next sibling
} NODE;

/* ---------- Utility ---------- */

NODE *newNode(const char *label) {
    NODE *n = malloc(sizeof(NODE));
    n->label = strdup(label);
    n->EOW = 0;
    n->child = NULL;
    n->sibling = NULL;
    return n;
}

int commonPrefixLen(const char *a, const char *b) {
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i])
        i++;
    return i;
}

/* ---------- Insert ---------- */

void insert(NODE **root, const char *word) {
    if (*root == NULL) {
        *root = newNode(word);
        (*root)->EOW = 1;
        return;
    }

    NODE *cur = *root;
    NODE *prev = NULL;

    while (cur) {
        int l = commonPrefixLen(cur->label, word);

        if (l == 0) {
            prev = cur;
            cur = cur->sibling;
            continue;
        }

        /* Exact match */
        if (l == strlen(cur->label) && l == strlen(word)) {
            cur->EOW = 1;
            return;
        }

        /* Node label is prefix of word */
        if (l == strlen(cur->label)) {
            insert(&cur->child, word + l);
            return;
        }

        /* Partial match → split node */
        NODE *split = newNode(cur->label + l);
        split->child = cur->child;
        split->EOW = cur->EOW;

        cur->label[l] = '\0';
        cur->child = split;
        cur->EOW = 0;

        if (l == strlen(word)) {
            cur->EOW = 1;
        } else {
            insert(&cur->child, word + l);
        }
        return;
    }

    prev->sibling = newNode(word);
    prev->sibling->EOW = 1;
}

/* ---------- Search ---------- */

int search(NODE *root, const char *word) {
    NODE *cur = root;

    while (cur) {
        int l = commonPrefixLen(cur->label, word);

        if (l == strlen(cur->label)) {
            if (l == strlen(word))
                return cur->EOW;
            return search(cur->child, word + l);
        }
        cur = cur->sibling;
    }
    return 0;
}

/* ---------- Display ---------- */

void display(NODE *root, char *buffer) {
    if (!root) return;

    strcat(buffer, root->label);
    if (root->EOW)
        printf("%s\n", buffer);

    display(root->child, buffer);
    buffer[strlen(buffer) - strlen(root->label)] = '\0';

    display(root->sibling, buffer);
}

/* ---------- Prefix Display ---------- */

void displayPrefix(NODE *root, const char *prefix, char *buffer) {
    NODE *cur = root;

    while (cur) {
        int l = commonPrefixLen(cur->label, prefix);

        if (l == strlen(cur->label)) {
            strcat(buffer, cur->label);
            if (l == strlen(prefix)) {
                if (cur->EOW)
                    printf("%s\n", buffer);
                display(cur->child, buffer);
                return;
            }
            displayPrefix(cur->child, prefix + l, buffer);
            return;
        }
        cur = cur->sibling;
    }
    printf("No words with given prefix\n");
}

/* ---------- Delete ---------- */

int deleteWord(NODE **root, const char *word) {
    if (*root == NULL) return 0;

    NODE *cur = *root;
    NODE *prev = NULL;

    while (cur) {
        int l = commonPrefixLen(cur->label, word);

        if (l == strlen(cur->label)) {
            if (l == strlen(word)) {
                cur->EOW = 0;
            } else {
                deleteWord(&cur->child, word + l);
            }

            if (!cur->EOW && cur->child == NULL) {
                if (prev)
                    prev->sibling = cur->sibling;
                else
                    *root = cur->sibling;
                free(cur->label);
                free(cur);
            }
            return 1;
        }

        prev = cur;
        cur = cur->sibling;
    }
    return 0;
}

/* ---------- Main ---------- */

int main() {
    NODE *root = NULL;
    int ch;
    char word[100], prefix[100], buffer[200];

    while (1) {
        printf("\n1.Insert\n2.Display\n3.Display Prefix\n4.Delete\n5.Search\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter word: ");
                scanf("%s", word);
                insert(&root, word);
                break;

            case 2:
                buffer[0] = '\0';
                printf("\nWords:\n");
                display(root, buffer);
                break;

            case 3:
                printf("Enter prefix: ");
                scanf("%s", prefix);
                buffer[0] = '\0';
                displayPrefix(root, prefix, buffer);
                break;

            case 4:
                printf("Enter word to delete: ");
                scanf("%s", word);
                deleteWord(&root, word);
                break;

            case 5:
                printf("Enter word to search: ");
                scanf("%s", word);
                if (search(root, word))
                    printf("FOUND\n");
                else
                    printf("NOT FOUND\n");
                break;
        }
    }
}

