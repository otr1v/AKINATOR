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
    char FirstObject[MAXLEN]  = "";
    char SecondObject[MAXLEN] = "";
    FILE* base = fopen("base.txt", "a+");
    CHECK_ERR(base == NULL, "didnot open");

    ReadBase(NULL, &node, base);

    printf("write down the first object:\n");
    scanf("%s", FirstObject);
    printf("write down the second object:\n");
    scanf("%s", SecondObject);

    WriteObjectsBase(node, FirstObject, SecondObject);
    WriteBuf(FirstData);

    FirstData->Text = (char**) calloc(FirstData->NumberOfStrings, sizeof(char*));
    CHECK_ERR(FirstData->Text == NULL, "problems with memory");

    CreateArrayOfPtr(FirstData);
    Compare(FirstData, FirstObject, SecondObject);
    DestroyAki(&node);
    fclose(base);
})


