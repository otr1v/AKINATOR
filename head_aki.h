#ifndef HEAD_AKI
#define HEAD_AKI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int          size;
}Node;

typedef struct 
{
    Node* r;
}Tree;


const int MAXLEN = 30;

void AddNode(Node* node);
void PreorderPrint(Node* node);
void AddAnswer(Node* node);
void SaveBase(FILE* base, Node* node, int amountspaces);
void FreeBuffer();
void AddQuestion(Node* node);
void ReadBase(Node* node, FILE* input);
void ConstructNode(Node* node);
#endif
