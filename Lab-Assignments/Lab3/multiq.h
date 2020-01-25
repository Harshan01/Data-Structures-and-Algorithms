#include "que.h"

struct multiq {
	QUEUE* queues;
	int num;
};
typedef struct multiq* MULTIQ;

MULTIQ createMQ(int num);

MULTIQ addMQ(MULTIQ mq, TASK t);

TASK nextMQ(MULTIQ mq);

TASK delNextMQ(MULTIQ mq);

int isEmptyMQ(MULTIQ mq);

int sizeMQ(MULTIQ mq);

int sizeMQbyPriority(MULTIQ mq, PRIORITY p);

QUEUE getQueueFromMQ(MULTIQ mq, PRIORITY p);

