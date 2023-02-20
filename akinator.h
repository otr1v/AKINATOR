#include "head_aki.h"
void CreateTree(Node* node)
{
    if (node == NULL)
    {
        node = (node*) malloc (sizeof(node*));
        node->left = NULL;
        node->right = NULL;
        printf("type your first question\n");
        scanf("%s", node->text);
        // node->text = "";
    }
}

//============================================

void PreorderPrint(Node* node)
{
    if (!node)    return;
    printf("%s\n", node->text);

    if (node->left)
    {
        PreorderPrint(node->left);
    }
    if (node->right)   
    {
        PreorderPrint(node->right);
    }
   
}

//============================================================

void AddAnswer(Node* node)
{
    printf("type your answer without \"?\" and without any spaces\n");
    scanf("%s", node->text);
    return;
    //printf("%s", str);
}

//==================================================

void SaveBase(FILE* base, Node* node, int amountspaces)
{
    char ch = '{';
    //  fprintf(base, "fhfh");
    fprintf(base, "%*c %s", amountspaces, ch, node->text);
    if ((node->left == NULL) && (node->right == NULL))  fprintf(base, " }\n");
    else if (node->left)
    {
        fprintf(base, "\n");
        SaveBase(base, node->left, amountspaces + 4);
    }
    else if (node->right)
    {
        fprintf(base, "\n");
        SaveBase(base, node->right, amountspaces + 4);
    }
}

//============================================

void CreateQuestion(Node* node, char* text)
{
    node->text = text;
}

//========================

void FreeBuffer()
{
    int x = 0;
    while ((x = getchar()) != EOF && x != '\n') 
        ;
}

//===================================

int Akinator(Node* node)
{

}
                                    //рассмотрим случай, когда мы должны путешествовать по дереву, тогда 
                                    // мы просто должны перемещаться дальше, а аргумент мы должны получать из читалки файла нашего
                                    // добавлять новые узлы когда новая игра 
                                    //спрашивать пользователя надо ли ему добавить новый узел
                                    //так как персонаж не подошел
//============================================

void AddNode(Node* node)
{
    //node->text = text;
    char ch = ' ';
    if (node->left == NULL && node->right == NULL)
    {
        printf("do you want to add an answer or a question?\n");
        scanf("%c", &ch);
                   // спросить хочет ли пользователь добавить новый вопрос или ответ
        if (ch == 'y') AddQuestion(node); 
        return;
    }
    printf("%s?\ntype y/n:\n", node->text);
    
    scanf("%c", &ch);
    FreeBuffer();
    if (ch == 'y')
    {
        AddNode(node->left);
    }
    else if (ch == 'n')
    {
        AddNode(node->right);
    }
    else
    {
        printf("what???\n");
    }
}

//=============================

void AddQuestion(Node* node)
{
    //if (node->)
    printf("%s?\n", node->text);
    char ch = ' ';
    int f = scanf("%c", &ch);
    if (ch == 'y')
    {
        //AddQuestion(node->left);
        // node = node->left;
        AddAnswer(node->left);              //переподвязку узла добавить( то есть так чтобы ответ был)
                                            // новый ответ добавить и новый вопрос соответвственно(как их различить два персонажа, если на старом месте стоял уже ответ)
    }
    else if (ch == 'n')
    {
        // node = node->right;
        AddAnswer(node->right);
    }
    else
    {
        printf("smth bad have happened\n");
    }
    //printf("%s?\n", node->text);
}

//==========================

void ReadBase(Node* node, FILE* input)
{
    char bracket[] = "";
    fscanf(input, "%s", bracket);
    if (!strcmp(bracket, "{"))
    {
        ConstructNode(node);
        ReadBase(node->left, input);
        ReadBase(node->right, input);
    }
    else if (!strcmp(bracket, "}"))
    {
        ungetc('}', input);
        return;
    }
    fscanf(input, "%s", bracket);
    return;
}

//====================================

void ConstructNode(Node* node)
{
    node = (node*) malloc(sizeof(node*));
    node->left  = NULL;
    node->right = NULL;
    node->text = (char*) malloc (MAXLEN * sizeof(char));
}
