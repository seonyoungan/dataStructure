#include <stdio.h>
#include <stdlib.h>

//구조체 선언
typedef int element;
typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
} TreeNode;


TreeNode *search(TreeNode *node, int key){
    //순환적 탐색 메소드
    if(node == NULL)    return NULL;
    if(key==node->key)  return node; //부모노드랑 값이 같으면 부모
    else if(key<node->key)
        return search(node->left, key);//부모노드보다 작으면 왼쪽
    else
        return search(node->right,key); //부모노드보다 크면 오른쪽
        

}

//새 노드 메소드 -> 존재의 이유: 삽입시 null이면 새로 추가해주려고
TreeNode *new_node(int item){
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));//TreeNode타입의 temp변수에 메모리를 할당한다. 그런데 이제 사이즈는 TreeNode사이즈인..
    temp->key = item; //매개변수로 받은 아이템이 바로 템프의 키값이다.
    temp->left = temp->right = NULL;//템프의 왼쪽, 오른쪽 자식들은 다 null로 초기화해줌
    return temp; //이것을 반환하기
}
//노드 삽입 메소드
TreeNode*insert_node(TreeNode *node, int key){
    //노드가 널값이면 새 노드를 만들자
    if(node == NULL)    return new_node(key); 
    
    //그렇지 않으면 삽입하자
    //키값이 부모노드의 키보다 작으면 왼쪽에 삽입할건데...
    else if(key<node->key)
        node->left = insert_node(node->left, key); //부모노드의 왼쪽노드에 key값을..
        
    //키값이 부모노드의 키보다 크면 오른쪽에 삽입함
    else if(key>node->key)
        node->right = insert_node(node->right, key);
    
    //이제 반환하자
    return node;
}

//최소값 노드 메소드
TreeNode *min_value_node(TreeNode *node){
    TreeNode *current = node;
    
    //가장 왼쪽노드로 이동
    while(current->left!=NULL)
        current = current->left;
    return current;
}

//노드 삭제 메소드
//이진 탐색트리의 키가 주어지면 키에 저장된 노드를 삭제하고 새 루트노드를 반환
TreeNode *delete_node(TreeNode *root, int key){
    if(root== NULL) return root;
    
    //만약 키가 루트보다 작으면 왼쪽에 있음 (->순환으로 찾아가야함)
    if(key < root->key){
        root->left = delete_node(root->left, key);
    }
    //만약 키가 루트보다 크면 오른쪽에 있음 (->순환으로 찾아가야함)
    else if(key > root->key){
        root->right = delete_node(root->right, key);
    }
    //만약 키가 루트와 같으면 삭제하면됨
    else{
        //첫번째나 두번째(키가 작거나 크거나)
        if(root->left==NULL){
            TreeNode *temp = root->right; //temp에 root->right를 복사
        free(root); //메모리해제
        return temp; //temp반환 (root의 오른쪽 값이 들어있을거임)
        }
        
        if(root->right==NULL){
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }


        //세번째 경우
        TreeNode *temp = min_value_node(root->right);
        
        root->key = temp->key; //temp의 키값을 복사
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

//중위 순회 메소드
void inorder(TreeNode *root){
    if(root){ //루트가 null이 아니면
        inorder(root->left);//루트의 왼쪽노드를 호출
        printf("[%d]", root->key); //값 출력
        inorder(root->right); //루트의 오른쪽 노드로 이동
    }
}

//메인함수
int main(void)
{
	TreeNode * root = NULL;
	TreeNode * tmp = NULL;

    //노드 삽입
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	
	//저장됐던 노드 삭제
    root = delete_node(root, 20);
    
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30 발견함 \n");
	else
		printf("이진 탐색 트리에서 30 발견못함 \n");
	return 0;
}
