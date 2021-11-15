#pragma once
#include <thread>
#include "TaskQueue.h"

class Handler
{
public:
	Handler(TaskQueue queue, int count);
	void startProcessing();

private:
	TaskQueue _queue;
	int _threadCount;

	static void threadFunction(TaskQueue queue, int count);
};
