#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{ //트리노드 구조체 생성
    int data; //노드
    struct TreeNode *left, *right; //링크 : 포인터로 표현
} TreeNode;

int main() {
    TreeNode *n1, *n2, *n3;
    
    n1 = (TreeNode *)malloc(sizeof(TreeNode)); //각각 메모리 할당
    n2 = (TreeNode *)malloc(sizeof(TreeNode));
    n3 = (TreeNode *)malloc(sizeof(TreeNode));
    
    n1->data = 10; //첫번째 노드에 10을 대입한다.
    n1->left = n2; //왼쪽 링크는 n2를 가리킨다.
    n1->right = n3; //오른쪽 링크는 n3를 가리킨다g.
    
    n2->data = 20; //첫번째 노드에 20을 대입한다.
    n2->left = NULL; //왼쪽 링크는 아무것도 가리키지 않음
    n2->right = NULL; //오른쪽 링크는 아무것도 가리키지 않음

    n3->data = 30; //첫번째 노드에 30을 대입한다.
    n3->left = NULL; //왼쪽 링크는 아무것도 가리키지 않음
    n3->right = NULL; //오른쪽 링크는 아무것도 가리키지 않음
    
    printf("data->%d (link-> %d)\n", n1->data, &(n1->data));
    printf("left->%d\n", n1->left);
    printf("right->%d\n\n", n1->right);
        
    printf("data->%d (link-> %d)\n", n2->data, &(n2->data));
    
    printf("left->%d\n", n2->left);
    printf("right->%d\n\n", n2->right);
        
    printf("data->%d (link-> %d)\n", n3->data, &(n3->data));
    printf("left->%d\n", n3->left);
    printf("right->%d\n\n", n3->right);
    
    free(n1); free(n2); free(n3); //메모리 해제
    
    return 0;
}