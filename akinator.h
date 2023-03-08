#include "head_aki.h"
// void CreateTree(Node** node)
// {
//     *node = (Node*) malloc (sizeof(Node));
//     (*node)->left = NULL;
//     (*node)->right = NULL;
//     printf("type your first question\n");
//     (*node)->text = (char *) malloc (MAXLEN * sizeof(char));
//     char buf[100] = "";
//     scanf("%s", buf);
//     FreeBuffer();
//     strcpy((*node)->text, buf);
    
//     printf("%s", (*node)->text);
// }
//==========================

void ConstructNode(Node* prevnode, Node** node)
{
    *node = (Node*) malloc(sizeof(Node));
    CHECK_ERR(*node == NULL, "problems with memory");

    (*node)->left   = NULL;
    (*node)->right  = NULL;
    (*node)->parent = prevnode;

    (*node)->text = (char*) malloc (MAXLEN * sizeof(char));
    CHECK_ERR((*node)->text == NULL, "problems with memory");
}

//==============================================================

void CreateDataStrings(DataStrings** data)
{
    *data = (DataStrings*) malloc(sizeof(DataStrings));
    CHECK_ERR(*data == NULL, "problems with memory");

    (*data)->buf = (char *) calloc(BUFLEN, sizeof(char));
    (*data)->SizeBuf         = 0;
    (*data)->NumberOfStrings = 0;
    (*data)->Second          = 0;
}

//================================================

void PreorderPrint(Node* node)
{
    if (node != NULL)
    {
        printf("%s\n", node->text);
        PreorderPrint(node->left);
        PreorderPrint(node->right);
    }

    return;
}

//===========================================

void Aki(Node* node, DataStrings* FirstData)
{
    printf("WELCOME TO AKINATOR\nHERE YOU CAN GUESS YOUR HERO, ANSWERING QUESTIONS\n");
    printf("MENU:\nType your command: play, quit, comp(comparison of two objects), info about where the character is\n");
    char cmd[MAXLEN] = "";
    scanf("%s", cmd);
    #define DEF_CMD(num, name, code)           \
            if (strcasecmp(cmd, #name) == 0)    \
                code                             
                                       
    #include "cmd.h"
    #undef DEF_CMD
 
}


//==================================================

void ReadBase(Node* prevnode, Node** node, FILE* input)
{
    char bracket[] = "";
    fscanf(input, "%s", bracket);
    if (strcmp(bracket, "{") == 0)
    {
        ConstructNode(prevnode, node);
        //printf("node %p\n", node);
        fscanf(input, "%s", (*node)->text);
        //printf("node->text %s\n", (*node)->text);
        ReadBase(*node, &(*node)->left, input);
        ReadBase(*node, &(*node)->right, input);
    }
    else if (strcmp(bracket, "}") == 0)
    {
        ungetc('}', input);
        return;
    }
    fscanf(input, "%s", bracket);
    return;
}

//====================================

void SaveBase(FILE* base, Node* node, int amountspaces)
{
    CHECK_ERR(node == NULL, "node NULL pointer");
    CHECK_ERR(base == NULL, "File NULL pointer");

    char ch = '{';
    fprintf(base, "%*c %s", amountspaces, ch, node->text);
    if ((node->left == NULL) && (node->right == NULL))
    {   
        fprintf(base, " }\n");
        return;
    }
    if (node->left)
    {
        fprintf(base, "\n");
        SaveBase(base, node->left, amountspaces + 4);
    }
    if (node->right)
    {
        fprintf(base, "\n");
        SaveBase(base, node->right, amountspaces + 4);
    }
    if (node->right == NULL || node->left == NULL)  fprintf(base, "%*c\n", amountspaces, '}');

    if (node->right && node->left)                  fprintf(base, "%*c\n", amountspaces, '}');

    return;
}

//============================================

void AddNode(Node* node)
{
    char answer[3] = "";
    
    if (node->left == NULL && node->right == NULL)
    {
        printf("Your character is %s, YOU ARE WINNER\n", node->text);
        printf("Am I right?\n");
        scanf("%s", answer);
        if (strcmp(answer, "n") == 0) CreateQuestion(node); 
        return;
    }
    printf("%s?\ntype y/n:\n", node->text);
    
    scanf("%s", answer);
    FreeBuffer();
    if (strcmp(answer, "y") == 0)
    {
        AddNode(node->left);
    }
    else if (strcmp(answer, "n") == 0)
    {
        AddNode(node->right);
        // }
    }
    else
    {
        printf("what???\n");
    }
}

//=============================

void CreateQuestion(Node* node)
{
    FreeBuffer();
    char character[MAXLEN] = "";
    printf("type your character:\n");
    scanf("%s", character);

    char tmp[MAXLEN]    = "";
    strcpy(tmp, node->text);
    printf("what is the difference between %s and %s?(question where your character has answer no)\n", character, tmp);
    scanf("%s", node->text);
    
    ConstructNode(node, &node->left);
    
    printf("%s is ", tmp);
    strcpy(node->left->text, tmp);
    
    ConstructNode(node, &node->right);

    printf("%s is ", character);
    strcpy(node->right->text, character);
}

//============================================================

void AddAnswer(Node* node)
{
    printf("type your answer without \"?\" and without any spaces\n");
    scanf("%s", node->text);
    return;
}

//==============================================

void FreeBuffer()
{
    int x = 0;
    while ((x = getchar()) != EOF && x != '\n') 
        continue;
}

//===================================

void PlayAkinator(Node* node)
{
    FILE* base = fopen("base.txt", "a+");
    CHECK_ERR(base == NULL, "didnot open");

    ReadBase(NULL, &node, base);
    AddNode(node);
   
    fclose(base);
    FILE* output = fopen("base.txt", "w+");
    CHECK_ERR(output == NULL, "didnot open");

    GraphDump(node);
    SaveBase(output, node, 0);
    fclose(output);
}

//============================================

void GraphDump(Node* node)
{
    FILE* dumpfile = fopen("dumpfile.txt", "w");
    CHECK_ERR(dumpfile == NULL, "problems with opening file");
    fprintf(dumpfile, "digraph G {\n");
    GraphTree(node, dumpfile, 0);
    fprintf(dumpfile, "}");
    fclose(dumpfile);
}

//======================================

void GraphTree(Node* node, FILE* dumpfile, int flag)    // flag defines color of the box
{
                                                        //can be added a flag to make another color
    if ((node != NULL) && (flag == 0))
    {   
        fprintf(dumpfile, "%s\n", node->text);
        fprintf(dumpfile, "%s[shape = box, color = blue];\n", node->text);
    }
    else if ((node != NULL) && (flag == 1))
    {   
        fprintf(dumpfile, "%s\n", node->text);
        fprintf(dumpfile, "%s[shape = box, color = green];\n", node->text);
    }
    else if ((node != NULL) && (flag == 2))
    {   
        fprintf(dumpfile, "%s\n", node->text);
        fprintf(dumpfile, "%s[shape = box, color = red];\n", node->text);
    }
    if (node->left)
    {
        fprintf(dumpfile, "%s -> ", node->text);
        GraphTree(node->left, dumpfile, 1);
    }
    if (node->right)
    {
        fprintf(dumpfile, "%s -> ", node->text);
        GraphTree(node->right, dumpfile, 2);
    }
}

//=============================

void ExistenceObject(Node* node, char* object, bool flag, bool printflag) // if you want to print info about object, flag should be = 1
{                                                                           // printflag for PrintInfo
    if (node != NULL)
    {
        if (strcmp(object, node->text) == 0)
        {
            printf("%s is:\n", object);
            if (flag)   PrintInfo(node->parent, node->text, printflag);
        }
        else
        {
            //printf("object %s have not been found", object);
        }
        ExistenceObject(node->left,  object, flag, printflag);
        ExistenceObject(node->right, object, flag, printflag);
    }
    return;
}

//=====================================

void PrintInfo(Node* node, char* tmp, bool printflag)   //принтфлаг - нужно ли печатать в стдаут или в файл
{
    FILE* characterfile = fopen("text.txt", "a+");
    if (node)
    {
        if (printflag == false)
        {
            if      (strcmp(tmp, node->left->text) == 0)  printf("%s\n", node->text);
            else if (strcmp(tmp, node->right->text) == 0) printf("not %s\n", node->text);
        }
        else
        {
            
            if      (strcmp(tmp, node->left->text) == 0)  fprintf(characterfile, "%s\n", node->text);
            else if (strcmp(tmp, node->right->text) == 0) fprintf(characterfile, "not %s\n", node->text);
            
        }
        PrintInfo(node->parent, node->text, printflag);
    }
    fclose(characterfile);
}

//===============================================

void DestroyAki(Node** node)
{
    if (*node == NULL)
    {
        return;
    }     
    DestroyAki(&(*node)->left);
   
    DestroyAki(&(*node)->right);
    free((*node)->text);
    free(*node);
    
}

//============================================

void CreateFileCharacters(Node* node, char buf[])
{
    
    if (node)
    {
        FILE* file = fopen("text.txt", "a+");
        fprintf(file, "%s\n", node->text);
        CreateFileCharacters(node->left , buf);
        CreateFileCharacters(node->right, buf );
        fclose(file);

    }
}

//===============================================

int FileSize(FILE* fp)
{
    struct stat buffer = {};
    int res_fstat = fstat(fileno(fp), &buffer);
    CHECK_ERR(res_fstat == -1, "can't fill the structure stat");
    int size_buf = buffer.st_size;
    return size_buf;
}
//===============================

void WriteBuf(DataStrings* data)
{
    FILE* names = fopen("text.txt", "r");
    data->SizeBuf = FileSize(names);
    fread(data->buf, sizeof(char), data->SizeBuf + 2, names);
    for (int i = 0; i < data->SizeBuf; i++)
    {
        if (data->buf[i] == '\n')
        {
            data->buf[i] = '\0';
            data->NumberOfStrings++;
        }
    }
    fclose(names);
}

//========================================

void CreateArrayOfPtr(DataStrings* data)
{
    int CounterText = 0;
    for (int i = 0; i < data->SizeBuf; i++)
    {
        if (i == 0)
        {
            data->Text[0] = &(data->buf[0]);
            CounterText++;
        }
        if (data->buf[i] == '\0' && data->buf[i + 1] == '?') data->Second = CounterText;
        if (data->buf[i] == '\0')
        {
            data->Text[CounterText] = &data->buf[i + 1];
            CounterText++;
        }
    }
}

//=================================

void Compare(DataStrings* data, char* first, char* second)
{
    int CurrentLine = 0;
    printf("%d %d\n", data->NumberOfStrings, data->Second);
    for (CurrentLine; CurrentLine < data->Second; CurrentLine++)
    {
        if (CurrentLine + data->Second + 1 < data->NumberOfStrings)
        {
            if (strcmp(data->Text[CurrentLine], data->Text[CurrentLine + data->Second + 1]) == 0)
            {
                printf("The same characteristics are: %s\n", data->Text[CurrentLine]);
            }
            else
            {
                printf("different:\n%s is %s\n", first, data->Text[CurrentLine]);
                printf("%s is %s\n", second, data->Text[CurrentLine + data->Second + 1]);
            }
        }
        else
        {
            printf("different:\n%s is %s\n", first, data->Text[CurrentLine]);
        }
    }
    for (CurrentLine; CurrentLine + data->Second + 1 < data->NumberOfStrings; CurrentLine++)
    {
        printf("different:\n%s is %s\n", second, data->Text[CurrentLine + data->Second + 1]);
    }
}
//===============================

void WriteObjectsBase(Node* node, char* first, char* second)
{
    ExistenceObject(node, first , 1, 1);
    FILE* textfile = fopen("text.txt", "a+");
    fprintf(textfile, "?\n");
    fclose(textfile);
    ExistenceObject(node, second, 1, 1);
}
