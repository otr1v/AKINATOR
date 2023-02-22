#include "head_aki.h"
void CreateTree(Node** node)
{
    // if (node == NULL)
    // {
        *node = (Node*) malloc (sizeof(Node));
        (*node)->left = NULL;
        (*node)->right = NULL;
        printf("type your first question\n");
        (*node)->text = (char *) malloc (MAXLEN * sizeof(char));
        char buf[100] = "";
        scanf("%s", buf);
        FreeBuffer();
        strcpy((*node)->text, buf);
        // node->text = "";
    
    printf("%s", (*node)->text);
}

//============================================

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

//============================================================

void AddAnswer(Node* node)
{
    printf("type your answer without \"?\" and without any spaces\n");
    printf("%p", node->text);
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
    if ((node->left == NULL) && (node->right == NULL))
    {   
        fprintf(base, " }\n");
        //return;
        // return;
    }
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
    if (amountspaces != 0)
    {
        fprintf(base, "%*c\n ", amountspaces - 4, '}');
        amountspaces -= 4 ;
        printf("alo");
    }
    return;
    
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
        continue;
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
    char answer[3] = "";
    if (!node)
    {
        printf("do you want to add an answer or a question?(y/n)\n");
        scanf("%s", answer);
                   // спросить хочет ли пользователь добавить новый вопрос или ответ
        if (strcmp(answer, "y") == 0) AddRightNode(node); 
        return; 
    }
    if (node->left == NULL && node->right == NULL)
    {
        printf("do you want to add an answer or a question?(y/n)\n");
        scanf("%s", answer);
                   // спросить хочет ли пользователь добавить новый вопрос или ответ
        if (strcmp(answer, "y") == 0) AddQuestion(node); 
        //SaveBase()
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
    FreeBuffer();
    printf("%s?\n", node->text);
    char answer[MAXLEN] = "";
    scanf("%s", answer);
    if (strcmp(answer, "y") == 0)
    {
        //AddQuestion(node->left);
        // node = node->left;
        ConstructNode(&node->left);
        AddAnswer(node->left);              //переподвязку узла добавить( то есть так чтобы ответ был)
                                            // новый ответ добавить и новый вопрос соответвственно(как их различить два персонажа, если на старом месте стоял уже ответ)
    }
    else if (strcmp(answer, "n") == 0)
    {
        // node = node->right;
        ConstructNode(&node->right);
        AddAnswer(node->right);
    }
    else
    {
        printf("smth bad have happened\n");
    }
    //printf("%s?\n", node->text);
}

//==========================

void ReadBase(Node** node, FILE* input)
{
    char bracket[] = "";
    fscanf(input, "%s", bracket);
    if (strcmp(bracket, "{") == 0)
    {
        ConstructNode(node);
        printf("node %p\n", node);
        fscanf(input, "%s", (*node)->text);
        printf("node->text %s\n", (*node)->text);
        ReadBase(&(*node)->left, input);
        ReadBase(&(*node)->right, input);
    }
    else if (strcmp(bracket, "}") == 0)
    {
        ungetc('}', input);
        return;
    }
    //printf("%s\n", bracket);
    fscanf(input, "%s", bracket);
    return;
}

//====================================

void ConstructNode(Node** node)
{
    *node = (Node*) malloc(sizeof(Node));
    (*node)->left  = NULL;
    (*node)->right = NULL;
    (*node)->text = (char*) malloc (MAXLEN * sizeof(char));
}

//=====================================

void AddRightNode(Node* node)
{
    FreeBuffer();
    ConstructNode(&node);
    AddAnswer(node);
}
