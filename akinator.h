#include "head_aki.h"

//void CreateTree()
void AddNode(Node* node, char* text)
{
    // int counter = 0;
    if (node == NULL)
    {
        node = (Node*) malloc (sizeof(node));
        node->left = NULL;
        node->right = NULL;
        //printf("dkdk");
        //return;
        //counter++;
    }
    node->text = text;
    //if (counter == 1) return;
    
    printf("%s?\ntype y/n:\n", node->text);
    char ch = ' ';
    int f = scanf("%c", &ch);
    printf("%c", ch);
    char answer[] = "";

    //printf("%s", answer);
    
    if (ch == 'y')
    {
        AddAnswer(node, answer);

        FreeBuffer();
        AddNode(node->left, answer);
        
    }
    else if (ch == 'n')
    {
        AddAnswer(node, answer);

        FreeBuffer();
        AddNode(node->right, answer);
    }
    else
    {
        printf("retry answering only with y or n\n");
        // AddNode(node, text);
        return;
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

void AddAnswer(Node* node, char* answer)
{
    printf("type your answer without \"?\" and without any spaces\n");
    //char str[] = "";
    scanf("%s", answer);
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
