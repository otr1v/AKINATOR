
#include "akinator.h"

int main()
{
    char str[] = "human";
    Node node = {};
    FILE* base = fopen("base.txt", "w");
    CHECK_ERR(base == NULL, "didnot open");
    // printf ("%*c", 4, "am");
    int count = 0;
    AddNode(&node, str);
    FreeBuffer();
    AddNode(&node, "fdkdfl");

    // AddNode(&node, str);

    SaveBase(base, &node, 4);
    //PreorderPrint(&node);
    return 0;
}
