#ifndef HEAD_AKI
#define HEAD_AKI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define CHECK_ERR(condition, message_error) \
                do{                                    \
                        if (condition){                 \
                            printf("%s", message_error); \
                        }                                 \
                } while(0)


typedef struct node
{
    char*        text;
    struct node* parent;
    struct node* left;
    struct node* right;
}Node;


typedef struct 
{
    char* buf;
    char** Text;
    int NumberOfStrings;
    int SizeBuf;
    int Second;
}DataStrings;               // решил делать через массив указателей на строки


const int MAXLEN = 30;
const int BUFLEN = 1000;
//void CreateNode(Node** node);
void ConstructNode(Node* prevnode, Node** node);
void CreateDataStrings(DataStrings** data);
void PreorderPrint(Node* node);
void Aki(Node* node, DataStrings* FirstData);
void ReadBase(Node* prevnode, Node** node, FILE* input);
void SaveBase(FILE* base, Node* node, int amountspaces);
void AddNode(Node* node);
void CreateQuestion(Node* node);
void AddAnswer(Node* node);
void FreeBuffer();
void PlayAkinator(Node* node);
void GraphDump(Node* node );
void GraphTree(Node* node, FILE* dumpfile, int flag);
void ExistenceObject(Node* node, char* object, bool flag, bool printflag);
void PrintInfo(Node* node, char* tmp, bool printflag);
void CreateFileCharacters(Node* node, char buf[]);
int FileSize(FILE* fp);
void DestroyAki(Node** node);
void WriteBuf(DataStrings* data);
void CreateArrayOfPtr(DataStrings* data);
void Compare(DataStrings* data, char* first, char* second);
void WriteObjectsBase(Node* node, char* first, char* second);


#endif
