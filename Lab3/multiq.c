#include "multiq.h"

MULTIQ createMQ(int num) {
	MULTIQ mq = (MULTIQ)malloc(sizeof(struct multiq));
	mq -> queues = (QUEUE*)malloc(num * sizeof(QUEUE));
	mq -> num = num;
	for(int i = 0; i < num; ++i) {
		(mq -> queues)[i] = newQ();
	}
	return mq;
}

MULTIQ addMQ(MULTIQ mq, TASK t) {
	(mq -> queues)[t -> p - 1] = addQ((mq -> queues)[t -> p - 1], t);
	return mq;
}

TASK nextMQ(MULTIQ mq) {
	int i = mq -> num;
	while((mq -> queues)[i] -> count == 0 && i >= 0) {
		--i;
	}
	if (i >= 0) {
		return front((mq -> queues)[i]);
	}
	return NULL;
}

TASK delNextMQ(MULTIQ mq) {
	int i = mq -> num - 1;
	while(i >= 0 && (mq -> queues)[i] -> count == 0) {
		--i;
	}
	if (i >= 0) {
		TASK t = (TASK)malloc(sizeof(struct task));
		t = front((mq -> queues)[i]);
		delQ((mq -> queues)[i]);
		return t;
	}
	return NULL;
}

int isEmptyMQ(MULTIQ mq) {
	int i = mq -> num;
	while((mq -> queues)[i] -> count == 0 && i >= 0) {
		--i;
	}
	if (i >= 0) {
		return 0;
	}
	return 1;
}

int sizeMQ(MULTIQ mq) {
	int i = mq -> num;
	int sum = 0;
	for (; i>=0; --i) {
		sum += lengthQ((mq -> queues)[i]);
	}
	return sum;
}

int sizeMQbyPriority(MULTIQ mq, PRIORITY p) {
	return lengthQ((mq -> queues)[p-1]);
}

QUEUE getQueueFromMQ(MULTIQ mq, PRIORITY p) {
	return (mq -> queues)[p-1];
}

