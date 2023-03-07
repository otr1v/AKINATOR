DEF_CMD(1, play, 
{
    PlayAkinator(node);
    DestroyAki(&node);
})

DEF_CMD(2, quit, 
{
    printf("BYE BYE");
    return;
})

DEF_CMD(3, info, 
{
    FILE* base = fopen("base.txt", "a+");
    CHECK_ERR(base == NULL, "didnot open");
    ReadBase(NULL, &node, base);
    char object[MAXLEN] = "";
    printf("what object do you want to find?\n");
    scanf("%s", object);
    ExistenceObject(node, object, 1, 0);
    DestroyAki(&node);
    fclose(base);
})

DEF_CMD(4, comp,
{
    // char* buf = (char *)calloc (BUFLEN, sizeof(char));
    // CHECK_ERR(buf == NULL, "can't give memory");
    char FirstObject[MAXLEN]  = "";
    char SecondObject[MAXLEN] = "";
    FILE* base = fopen("base.txt", "a+");
    CHECK_ERR(base == NULL, "didnot open");
    ReadBase(NULL, &node, base);
    printf("write down the first object:\n");
    scanf("%s", FirstObject);
    printf("write down the second object:\n");
    scanf("%s", SecondObject);
    CompareObjects(node, FirstObject, SecondObject);
    FirstData->FirstNumStrings  = WriteBuf(buf, &SizeBuf);
    SecondData->SecondNumStrings = WriteBuf(buf, &SizeBuf);
    // CreateFileCharacters(node, buf);
    // int NumberStrings = WriteBuf(buf, &SizeBuf);
    char ** text1 = (char **) calloc(NumberStrings, sizeof(char*));
    // CreateArrayOfPtr(buf, text, &SizeBuf);
})

