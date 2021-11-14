#pragma once
#include <thread>
#include "TaskQueue.h"

class Handler
{
public:
	Handler(TaskQueue queue, int count);
	~Handler();

	void startProcessing();

private:
	TaskQueue _queue;
	int _threadCount;

	static void threadHandler(TaskQueue queue, int count);
};
