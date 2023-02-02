#include <iostream>

int C;
char quadTree[1'001];
char ret[1'001];
int cursor;

struct Node
{
    char cur; // 'x' or 'w' or 'b'
    Node *c1;
    Node *c2;
    Node *c3;
    Node *c4;
};

Node *makeTree();
void printTree(Node *node);

int main()
{
    std::cin >> C;
    for (int c = 0; c < C; c++)
    {
        std::cin >> quadTree;
        cursor = 0;
        Node *root = makeTree();
        cursor = 0;
        printTree(root);
        ret[cursor] = 0;
        std::cout << ret << std::endl;
    }

    return 0;
}

Node *makeTree()
{
    Node *n = new Node;
    n->cur = quadTree[cursor++];
    if (n->cur == 'x')
    {
        n->c1 = makeTree();
        n->c2 = makeTree();
        n->c3 = makeTree();
        n->c4 = makeTree();
    }

    return n;
}
void printTree(Node *node)
{
    ret[cursor++] = node->cur;
    if (node->cur != 'x')
        return;

    printTree(node->c3);
    printTree(node->c4);
    printTree(node->c1);
    printTree(node->c2);
}