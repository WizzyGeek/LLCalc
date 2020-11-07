#include<stdlib.h>
#include<string.h>
#include<stdio.h>
// A linked list Node
struct listNode {
    short int value;
    struct listNode* next;
};

// A function to create a Node
// returns a pointer to the Node
struct listNode* initNode(short int data){
    struct listNode* node = (struct listNode *) malloc(sizeof(struct listNode));
    node->value = data;
    node->next = NULL;
    return node;
};

short int chtoi(char d){
    return (short int) d - '0';
};
/**
 * Create a Linked List from a C string.
 */
struct listNode* createLL(char NumStr[]){
    int pos, i;
    struct listNode *Node, *preNode, *Head;
    pos = 0;
    if (NumStr[0] == '-' || NumStr[0] == '+'){
        pos = 1;
    };
    preNode = initNode((short int) chtoi(NumStr[pos]));
    // printf("Conv %hd", (short int) NumStr[pos]);
    Head = preNode;
    for(i = pos + 1; i <  strlen(NumStr); i++){
        Node = initNode((short int) chtoi(NumStr[i]));
        // printf("Conv %hd", atoi(NumStr[pos]));
        preNode->next = Node;
        preNode = Node;
    };
    return Head;
};

/**
 * To print a long long int
 * printf("%ulld\n", Num);
 */

// This assumes 321 is 3->2->1
long long int toInt(struct listNode* node){
    long long int val = 0;
    while (node){
        // printf("%hu|%lld\n", node->value, val);
        // printf("%lld\n", (long long int) node->value);  
        val = (val * 10) + (long long int) node->value;
        node = node->next;
    };
    return val;
};

// This assumes 321 is 1->2->3
// long long int toIntCo_var(struct listNode* node){
//     long long int val, temp = 1; // This takes up 128 bits, too bad.
//     while (node){
//         val += (long long int) node->value * temp
//         temp *= 10;
//         node = node->next
//     };
//     return val;
// };

long long int multiList(struct listNode* pNum1, struct listNode* pNum2){
    return toInt(pNum1) * toInt(pNum2);
};

long long int divList(struct listNode* pNum1, struct listNode* pNum2){
    return toInt(pNum1) / toInt(pNum2);
};

long long int addList(struct listNode* pNum1, struct listNode* pNum2){
    return toInt(pNum1) + toInt(pNum2);
};

long long int subList(struct listNode* pNum1, struct listNode* pNum2){
    return toInt(pNum1) - toInt(pNum2);
};

int main(){
    char num1[20], num2[20];
    unsigned short int op;
    printf("1. Add\n2. Sub\n3. Multi\n4. Div\n");
    scanf("%19s", num1);
    scanf("%19s", num2);
    scanf("%hu", &op);
    printf("Input Format: \"num1 num2 operation\"\nExample:\n11 12 1\nFor adding 11 and 12\n=============\n");
    // printf("%lld\n", toInt(createLL(num1)));
    struct listNode* Num1, Num2;
    switch (op){
        case 1:
            printf("%lld\n", addList(createLL(num1), createLL(num2)));
            break;
        case 2:
            printf("%lld\n", subList(createLL(num1), createLL(num2)));
            break;
        case 3:
            printf("%lld\n", multiList(createLL(num1), createLL(num2)));
            break;
        case 4:
            printf("%lld\n", divList(createLL(num1), createLL(num2)));
            break;
        default:
            printf("Not Found!\n");
            break;
    };
    return 0;
}