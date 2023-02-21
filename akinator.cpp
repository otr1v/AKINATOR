
#include "akinator.h"


int main()
{
    char str[] = "human";
    Node*  node = NULL;
    FILE* base = fopen("base.txt", "w");
    CHECK_ERR(base == NULL, "didnot open");
    int count = 0;
    CreateTree(&node);
    printf("%p", node->text);
    printf("%s\n", node->text);
    AddNode(node);
    SaveBase(base, node, 4);
    return 0;
}
