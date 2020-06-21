#pragma once
// BinSrchTree.h : 이진 탐색 트리 클래스
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree {

public:
	BinSrchTree(void) { }
	~BinSrchTree(void) { }

	// 이진 탐색 트리의 탐색 연산
	BinaryNode* search(int key) {
	}
	BinaryNode* search(BinaryNode* n, int key) {

	}

	// 이진 탐색 트리의 삽입 연산
	void insert(BinaryNode* n) {

	}
	void insert(BinaryNode* r, BinaryNode* n) {

	}

	// 이진 탐색 트리의 삭제 연산
	void remove(int data) {

	}
	void remove(BinaryNode* parent, BinaryNode* node) {

	}

	

	// 키 값으로 노드를 탐색하는 함수 ("순환"적인 방법)
	BinaryNode* searchRecur(BinaryNode* n, int key) {
		if (n == NULL)										// n이 NULL
			return NULL;

		if (key == n->getData())							// 1) key == 현재노드의 data
			return n;
		else if (key < n->getData())						// 2) key < 현재 노드의 data
			return searchRecur(n->getLeft(), key);
		else												// 3) key > 현재 노드의 data			
			return searchRecur(n->getRight(), key);
	}

	// 키 값으로 노드를 탐색하는 함수 ("반복"적인 방법) 
	BinaryNode* searchIter(BinaryNode* n, int key) {
		while (n != NULL) {
			if (key == n->getData())
				return n;
			else if (key < n->getData())
				n = n->getLeft();
			else
				n = n->getRight();
		}

		return NULL;		// 탐색에 실패한 경우 NULL 반환
	}

};