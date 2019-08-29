#include<stdio.h>
#include<stdlib.h>
//created by small small su

typedef struct BTNode{
	char data;
	struct BTNode *lChild;
	struct BTNode *rChild;
}BiTNode;

//前序创建二叉树
void CreateBiTree(BiTNode **T){
	char ch;
	scanf("%c",&ch);
	getchar();
	if(ch== '-'){
		*T = NULL;
		return;
	}else{
		*T = (BiTNode *)malloc( sizeof(BiTNode));
		(*T)->data = ch;
		printf("输入%c 的左子树节点:\n",ch);
		CreateBiTree(&((*T)->lChild));
		printf("输入%c 的右子树节点:\n",ch);
		CreateBiTree((&(*T)->rChild));
	}
	return ;
}
//前序遍历二叉树
void PreOrderBiTree(BiTNode *T){
	if(T == NULL)
		return;
	else{
		printf("%c ",T->data);
		PreOrderBiTree(T->lChild);
		PreOrderBiTree(T->rChild);
	}
}

//中序遍历二叉树
void MiddleOrderBiTree(BiTNode *T){
	if(T==NULL){
		return ;
	}else{
		MiddleOrderBiTree(T->lChild);
		printf("%c  ",T->data);
		MiddleOrderBiTree(T->rChild);
	}
}


//后序遍历
void PostOrderBiTree(BiTNode *T){
	if(T == NULL){
		return ;
	}else{
		PostOrderBiTree(T->lChild);
		PostOrderBiTree(T->rChild);
		printf("%c  ",T->data);
	}
}

//树的深度
int TreeDeep(BiTNode *T){
	int deep = 0;
	if(T != NULL){
		int leftdeep = TreeDeep(T->lChild);
		int rightdeep = TreeDeep(T->rChild);
		deep = leftdeep>=rightdeep?leftdeep+1:rightdeep+1;
	}
	return deep;
}

//叶子节点个数
int count = 0;
void LeafCount(BiTNode *T){
	if(T!=NULL){
		LeafCount(T->lChild);
		LeafCount(T->rChild);
		if(T->lChild == NULL && T->rChild == NULL ){
			count ++;
		}
	}
}

//中序遍历非递归算法
#define M 50
void inOrder(BiTNode *T){
	BiTNode STACK[M],*p =  T;
	int top = -1;
	do{
		while(p!=NULL){
			STACK[++top] = *p;
			p = p->lChild;
		}
		p = &STACK[top--];
		
		printf(" %c ", p->data);
		p = p->rChild;
	}while(p!=NULL||top!=-1);

}



//主函数
int main(int argc,const char *argv[]){
	BiTNode *T;
	int depth,leafCount = 0;
	printf("请输入第一个节点的值，'-' 表示没有叶节点：\n");
	CreateBiTree(&T);

	printf("先序遍历二叉树：");
	PreOrderBiTree(T);
	printf("\n");

	printf("中序遍历二叉树：");
	MiddleOrderBiTree(T);
	printf("\n");

	printf("后续遍历二叉树：");
	PostOrderBiTree(T);
	printf("\n");

	depth = TreeDeep(T);
	printf("树的深度为：%d\n",depth);

	LeafCount(T);
	printf("叶子节点个数:%d\n",count);

	printf("中序遍历，非递归算法\n");
	inOrder(T);

	return 0;
}
