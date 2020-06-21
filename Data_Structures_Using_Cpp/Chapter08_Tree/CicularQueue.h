#pragma once
// CircularQueue.h : 노드의 포인터를 저장하는 큐 클래스
#include "BinaryNode.h"
#include <stdlib.h>

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE 100

class CircularQueue {
	int front;							// 첫 번째 요소 앞의 위치
	int rear;							// 마지막 요소 위치

	BinaryNode* data[MAX_QUEUE_SIZE];	// 요소의 배열
public:
	CircularQueue() {
		front = rear = 0;
	}

	bool isEmpty() {
		return front == rear;
	}

	bool isFull() {
		return (rear + 1) % MAX_QUEUE_SIZE == front;
	}

	void enqueue(BinaryNode* n) {
		if (isFull())
			error(" Error : 큐가 포화상태입니다.\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}

	BinaryNode* dequeue() {
		if (isEmpty())
			error(" Error: 큐가 공백상태입니다.\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};