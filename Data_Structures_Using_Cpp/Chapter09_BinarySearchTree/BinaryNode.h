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

	void setData(int val) {
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


	/* =========================== */
	/* 9��. ����Ž��Ʈ��		   */
	/* =========================== */
	BinaryNode* search(int key) {
		if (key == data)
			return this;
		else if (key < data && left != NULL)
			return left->search(key);
		else if (key > data&& right != NULL)
			return right->search(key);
		else
			return NULL;
	}
};