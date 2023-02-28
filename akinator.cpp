
#include "akinator.h"

int main()
{
    Node*  node = NULL;
    FILE* base = fopen("base.txt", "a+");
    CHECK_ERR(base == NULL, "didnot open");
    int count = 0;
    Aki(node);
    return 0;
}
