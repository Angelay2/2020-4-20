#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
	int val;
	struct ListNode* next;
	
}Node;

typedef struct sList{
	Node* _head;// 单链表只需要记录第一个结点的起始位置
}sList;


// 单链表初始化, 放的是结构体(sList本身也需要给一个结构体)
void sListInit(sList* sl){
	// 空链表
	// 新的头指向新的节点 指向newNode 不指向原来的节点 指向新的
	// 先创建新节点
	sl->_head = NULL;// 让头指向NULL(无效地址)
}

Node* createNode(int data){
	// 先申请空间
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = data;
	node->next = NULL;
	return node;
}

// 头插
// 让单链表的头(sL->head)不在指向原来的第一个结点, 而指向newNode ,让newNoded->next指向之前的第一个结点
void sListPushFront(sList* sl, int data){
	// 每创建一个node(新结点) next都指向NULL
	Node* node = createNode(data);

	// 判断原始链表是否为空 由于链表进行了初始化, 所以第一次会进if(也只有第一次进if)
	// 如果原始链表为空, 就让新结点node作为我们的头(变成只有一个节点的链表)
	if (sl->_head == NULL){
		sl->_head = node;
	}
	else{
		// 头插
		// sl->head原来指向的就是链表的第一个结点 赋给新结点的next后再指向新的结点
		node->next = sl->_head;
		sl->_head = node;
	}
}

Node* sListFind(sList* sl, int data){
	Node* cur = sl->_head;
	while (cur){
		if (cur->val == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

int removeNode(Node* pNode) {
	if (pNode == NULL || pNode->next == NULL)
		return 0;
	else{
		Node* cur = pNode;
		if (cur){
			Node* next = cur->next;
			free(pNode);
			cur = next->next;
			return 1;
		}
	}
	return 0;
}

int main(){
	sList sl;
	sListInit(&sl);
	sListPushFront(&sl, 1);
	sListPushFront(&sl, 2);
	sListPushFront(&sl, 3);
	sListPushFront(&sl, 5);
	sListPushFront(&sl, 4);
	sListPushFront(&sl, 6);
	Node* pNode;
	pNode = sListFind(&sl, 6);

	printf("%d\n", removeNode(pNode));

	system("pause");
	return 0;
}