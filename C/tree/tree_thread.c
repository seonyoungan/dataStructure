#include <stdio.h>
#define TRUE 1
#define FALSE 1

typedef struct TreeNode{
    int data; //부모노드의 데이터
    struct TreeNode *left, *right; //자식노드의 링크
    int is_thread; //스레드면 TRUE 아니면 FALSE
} TreeNode;

//		     G
//	     C		  F
//    A	   B   D     E

//전역변수로 노드 데터 입력하기
TreeNode n1 = {'A', NULL, NULL, 1};
TreeNode n2 = {'B', NULL, NULL, 1};
TreeNode n3 = {'C', &n1, &n2, 1};
TreeNode n4 = {'D', NULL, NULL, 1};
TreeNode n5 = {'E', NULL, NULL, 1};
TreeNode n6 = {'F', &n4, &n5, 1};
TreeNode n7 = {'G', &n3, &n6, 1};
TreeNode *root = &n7; //root는 n7의 주소값

TreeNode *find_successor(TreeNode *p){
    //q = p의 오른쪽 자식노드를 가리킨다.
    TreeNode *q = p->right;
    //오른쪽 자식노드가NULL이거나 스레드이면 오른쪽 포인터를 반환한다.
    if(q==NULL || p->is_thread ==TRUE)
        return q; //q를 반환해라
    //만일 오른쪽 자식이 있으면 가장 왼쪽노드로 이동해라
    while(q->left!=NULL) //q의 왼쪽자식이 null이 아닐때까지
        q = q->left; //q의 왼쪽자식으로 이동
    return q; //q를 반환
}

void thread_inorder(TreeNode *t){ //t는 메인함수에서 넘겨받은 매개변수
    TreeNode *q; //TreeNode타입의 q변수 선언
    q = t; //t를 q에 복사
    
    //가장 왼쪽노드로 이동
    while(q->left)//q의left가 있는 동안에
        q=q->left; //q의 left를 q에 복사
    do{
        printf("%c->", q->data); //q의 데이터 출력
        q = find_successor(q);
    } while(q); //q에 데이터가 있는 동안에
}

int main(void){
    	// 스레드 설정 
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	// 중위 순회
	thread_inorder(root);
	printf("\n");
    return 0;
}