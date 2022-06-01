#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//       +
//  *        +
//1	  4    16   25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  NULL, NULL };
TreeNode n3 = {'*', &n1, &n2};
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = {'+', &n4, &n5 };
TreeNode n7 = {'+', &n3, &n6 };
TreeNode *root = &n7;

int evaluate(TreeNode *root){
    /*평가 명세
    1. root가 null이면 0을 반환한다.
    2-1. 만일root의 left링크가 null이고, right링크가 null일 때 root의 data를 반환한다.
    2-2. 2-1이 아닌 경우는, root의 left링크에 있는 data와 right 링크에 있는 data를 root의 data에 있는 연산자를 활용헤 계산한다.(switch문 활용)
    */
    
    if(root == NULL)    return 0; //1
    if(root->left == NULL & root->right == NULL)    return root->data;//2-1
    else{
        int op1 = evaluate(root->left);
        int op2 = evaluate(root->right);
        printf("%d %c %d를 계산합니다.\n", op1,root->data,op2);
        switch(root->data){
            case'+':    return op1 + op2;
            case'-':    return op1 - op2;
            case'*':    return op1 * op2;
            case'/':    return op1 / op2;
        }
    }
}

int main() {
    printf("수식의 값은 %d입니다.\n", evaluate(root));
    return 0;
}