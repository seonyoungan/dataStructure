#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
} TreeNode;

int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p){
    if(top < SIZE -1) //top이 full상태가 아니면
        stack[++top] = p; // 포인터를 올리고 p를 대입
}

TreeNode *pop(){
    TreeNode *p = NULL; //p에 NULL값 대입
    if(top >=0) //top이 공백상태가 아니면
        p = stack[top--]; // p에 stak[top]값을 대입하고 top포인터를 내린다.
    return p;
}

void inorder_iter(TreeNode *root){
    while(1){ //무한루프
        for(;root;root=root->left) //초기 조건없이(?)실행, root까지, root의왼쪽링크를 계속계속 타게끔..한거겟지..?
            push(root);
        root = pop();
        if(!root) break; //root가 아니면 반복문 빠져나옴
    printf("[%d]", root->data);
    root = root->right;
    }
}

//      15
//  4      20
//1	     16   25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;

int main(void){
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
	return 0;
}