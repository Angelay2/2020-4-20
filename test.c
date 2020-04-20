#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
	int val;
	struct ListNode* next;
	
}Node;

typedef struct sList{
	Node* _head;// ������ֻ��Ҫ��¼��һ��������ʼλ��
}sList;


// �������ʼ��, �ŵ��ǽṹ��(sList����Ҳ��Ҫ��һ���ṹ��)
void sListInit(sList* sl){
	// ������
	// �µ�ͷָ���µĽڵ� ָ��newNode ��ָ��ԭ���Ľڵ� ָ���µ�
	// �ȴ����½ڵ�
	sl->_head = NULL;// ��ͷָ��NULL(��Ч��ַ)
}

Node* createNode(int data){
	// ������ռ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = data;
	node->next = NULL;
	return node;
}

// ͷ��
// �õ������ͷ(sL->head)����ָ��ԭ���ĵ�һ�����, ��ָ��newNode ,��newNoded->nextָ��֮ǰ�ĵ�һ�����
void sListPushFront(sList* sl, int data){
	// ÿ����һ��node(�½��) next��ָ��NULL
	Node* node = createNode(data);

	// �ж�ԭʼ�����Ƿ�Ϊ�� ������������˳�ʼ��, ���Ե�һ�λ��if(Ҳֻ�е�һ�ν�if)
	// ���ԭʼ����Ϊ��, �����½��node��Ϊ���ǵ�ͷ(���ֻ��һ���ڵ������)
	if (sl->_head == NULL){
		sl->_head = node;
	}
	else{
		// ͷ��
		// sl->headԭ��ָ��ľ�������ĵ�һ����� �����½���next����ָ���µĽ��
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