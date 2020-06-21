#pragma once
// BinaryNode.h : ����Ʈ���� ���� ��� Ŭ����
#include <cstdio>
class BinaryNode {
protected:
	int data;			// Ʈ���� ������ ������
	BinaryNode* left;	// ���� �ڽ� ����� ������
	BinaryNode* right;	// ������ �ڽ� ����� ������

public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) { }

	void setData (int val) {
		data = val;
	}

	void setLeft(BinaryNode* l) {
		left = l;
	}

	void setRight(BinaryNode* r) {
		right = r;
	}

	int getData() {
		return data;
	}

	BinaryNode* getLeft() {
		return left;
	}

	BinaryNode* getRight() {
		return right;
	}

	bool isLeaf() {
		return left == NULL && right == NULL;
	}

	/* =========================== */
	/* ��� Ŭ�������� ��ȸ�� ���� */
	/* =========================== */

	void inorder() {
		if (left != NULL)
			left->inorder();
		printf(" [%c] ", data);
		if (right != NULL)
			right->inorder();
	}

};