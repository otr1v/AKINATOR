#ifndef HEAD_AKI
#define HEAD_AKI

#include <stdio.h>
#include <stdlib.h>

#define CHECK_ERR(condition, message_error) \
                do{                                    \
                        if (condition){                 \
                            printf("%s", message_error); \
                        }                                 \
                } while(0)


typedef struct node
{
    char*        text;
    struct node* left;
    struct node* right;
    //char*        head;
}Node;

typedef struct 
{
    Node* r;
}Tree;

void AddNode(Node* node, char* text);
void PreorderPrint(Node* node);
void AddAnswer(Node* node, char* answer);
void SaveBase(FILE* base, Node* node, int amountspaces);
void FreeBuffer();
#endif
