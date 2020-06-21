#pragma once
// BinSrchTree.h : ���� Ž�� Ʈ�� Ŭ����
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree {

public:
	BinSrchTree(void) { }
	~BinSrchTree(void) { }

	// ���� Ž�� Ʈ���� Ž�� ����
	BinaryNode* search(int key) {
	}
	BinaryNode* search(BinaryNode* n, int key) {

	}

	// ���� Ž�� Ʈ���� ���� ����
	void insert(BinaryNode* n) {

	}
	void insert(BinaryNode* r, BinaryNode* n) {

	}

	// ���� Ž�� Ʈ���� ���� ����
	void remove(int data) {

	}
	void remove(BinaryNode* parent, BinaryNode* node) {

	}

	

	// Ű ������ ��带 Ž���ϴ� �Լ� ("��ȯ"���� ���)
	BinaryNode* searchRecur(BinaryNode* n, int key) {
		if (n == NULL)										// n�� NULL
			return NULL;

		if (key == n->getData())							// 1) key == �������� data
			return n;
		else if (key < n->getData())						// 2) key < ���� ����� data
			return searchRecur(n->getLeft(), key);
		else												// 3) key > ���� ����� data			
			return searchRecur(n->getRight(), key);
	}

	// Ű ������ ��带 Ž���ϴ� �Լ� ("�ݺ�"���� ���) 
	BinaryNode* searchIter(BinaryNode* n, int key) {
		while (n != NULL) {
			if (key == n->getData())
				return n;
			else if (key < n->getData())
				n = n->getLeft();
			else
				n = n->getRight();
		}

		return NULL;		// Ž���� ������ ��� NULL ��ȯ
	}

};