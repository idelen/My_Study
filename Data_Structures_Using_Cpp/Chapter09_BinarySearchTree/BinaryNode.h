#pragma once
// BinaryNode.h : 이진트리를 위한 노드 클래스
#include <cstdio>
class BinaryNode {
protected:
	int data;			// 트리에 저장할 데이터
	BinaryNode* left;	// 왼쪽 자식 노드의 포인터
	BinaryNode* right;	// 오른쪽 자식 노드의 포인터

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
	/* 노드 클래스에서 순회의 구현 */
	/* =========================== */

	void inorder() {
		if (left != NULL)
			left->inorder();
		printf(" [%c] ", data);
		if (right != NULL)
			right->inorder();
	}


	/* =========================== */
	/* 9장. 이진탐색트리		   */
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