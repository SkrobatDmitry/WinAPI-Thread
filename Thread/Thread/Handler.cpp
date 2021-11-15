#include "Handler.h"

Handler::Handler(TaskQueue queue, int count)
{
	_queue = queue;
	_threadCount = count;
}

void Handler::threadFunction(TaskQueue queue, int count)
{
	std::vector<std::thread> vec;
	while (count) {
		std::function<void()> task = queue.popTask();
		if (task != NULL) {
			std::thread thr(task);
			vec.push_back(move(thr));
			count--;
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		vec[i].join();
	}
}

void Handler::startProcessing()
{
	std::thread thr(threadFunction, _queue, _threadCount);
	thr.join();
}
