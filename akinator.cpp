#include "head_aki.h"

int main()
{
    Node*  node = NULL;
    DataStrings* FirstData = {};
    DataStrings* SecondData = {};
    CreateDataStrings(&FirstData);
    
    Aki(node, FirstData);

    // Explore (node);
    
    return 0;
}
