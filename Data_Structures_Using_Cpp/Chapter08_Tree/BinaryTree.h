#pragma once
// BinaryTree.h : 이진트리 클래스
#include "BinaryNode.h"
#include "CicularQueue.h"

class BinaryTree {
	BinaryNode* root;

public:
	BinaryTree() : root(NULL) { }

	void setRoot(BinaryNode* node) {
		root = node;
	}

	BinaryNode* getRoot() {
		return root;
	}

	bool isEmpty() {
		return root == NULL;
	}

	// 이진트리의 순회 연산 : 8.5절에서 공부
	/*
	void inorder() {
		printf("\n inoder: ");
		inorder(root);
	}
	void inorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL)
				inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			if (node->getRight() != NULL)
				inorder(node->getRight());
		}
	}
	*/


	/* 노드클래스 순회의 구현 */
	void inorder() {
		printf("\n inorder: ");
		if (!isEmpty())
			root->inorder();
	}

	void preorder() {
		printf("\n preorder: ");
		preorder(root);
	}
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			printf(" [%c] ", node->getData());
			if (node->getLeft() != NULL)
				preorder(node->getLeft());
			if (node->getRight() != NULL)
				preorder(node->getRight());
		}
	}

	void postorder() {
		printf("\n postorder: ");
		postorder(root);
	}
	void postorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL)
				postorder(node->getLeft());
			if (node->getRight() != NULL)
				postorder(node->getRight());
			printf(" [%c] ", node->getData());
		}
	}

	void levelorder() {
		printf("\n levelorder: ");
		
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n != NULL) {
					printf(" [%c] ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}

	/* 이진트리의 추가 연산 : 8.6절에서 공부 */
	
	// 트리 노드의 개수를 구하는 함수
	int getCount() {
		return isEmpty() ? 0 : getCount(root);
	}
	// 순환 호출에 의해 node를 루트로 하는 서브트리의 노드 수 계산 함수
	int getCount(BinaryNode* node) {
		if (node == NULL)
			return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	// 트리의 높이를 구하는 함수
	int getHeight() {
		return isEmpty() ? 0 : getHeight(root);
	}
	// 순환 호출에 의해 node를 루트로 하는 서브트리의 높이 계산 함수
	int getHeight(BinaryNode* node) {
		if (node == NULL)
			return 0;

		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());

		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}


	// 트리의 단말노드 개수를 구하는 함수
	int getLeafCount() {
		return isEmpty() ? 0 : getLeafCount(root);
	}
	// 순환 호출에 의해 node를 루트로 하는 서브트리의 단말 노드 수 계산 함수
	int getLeafCount(BinaryNode* node) {
		if (node == NULL)
			return 0;

		if (node->isLeaf())			// node가 단말노드이면 1을 반환
			return 1;
		else
			return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	// 수식트리 계산 함수
	int evaluate() {
		return evaluate(root);
	}
	// 순환 호출에 의해 node를 루트로 하는 수식 트리의 계산 함수
	int evaluate(BinaryNode* node) {
		if (node == NULL)
			return 0;

		if (node->isLeaf())
			return node->getData();
		else {
			int op1 = evaluate(node->getLeft());
			int op2 = evaluate(node->getRight());
			switch (node->getData()) {
				case '+': return op1 + op2;
				case '-': return op1 - op2;
				case'*': return op1 * op2;
				case '/': return op1 / op2;
			}
			return 0;
		}
	}
};
