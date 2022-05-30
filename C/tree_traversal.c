#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
} TreeNode;
//      15
//   4     20
// 1      16  25
//위의 그림을 구현(연결)
TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6; //root노드는 n6이다.

//중위
void inorder(TreeNode *root){
    if(root != NULL){ //ROOT가 NULL이면 안되니까..
        inorder(root->left); //root의 왼쪽으로 순회(재귀사용 후
        printf("[%d]", root->data);//데이터를 출력합니다.
        inorder(root->right); //right로 순회합니다. (재귀사용)
    }
}

//전위
void preorder(TreeNode *root){
    if(root != NULL){
        printf("[%d]", root->data); //노드 방문
        preorder(root->left); //왼쪽서브트리 순회
        preorder(root->right); //오른쪽 서브트리 순회
    }
}

//후위
void postorder(TreeNode *root){
    if(root != NULL){
        preorder(root->left); //왼쪽서브트리 순회
        preorder(root->right); //오른쪽 서브트리 순회
        printf("[%d]", root->data); //노드 방문
    }
}


int main() {
    printf("중위순회 = ");
    inorder(root);
    printf("\n");

    printf("전위순회 = ");
    preorder(root);
    printf("\n");

    printf("후위순회 = ");
    postorder(root);
    printf("\n");
    return 0;
}