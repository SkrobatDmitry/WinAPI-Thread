#pragma once
#include <mutex>
#include <queue>
#include <functional>

class TaskQueue
{
public:
	TaskQueue();

	bool pushTask(std::function<void()> task);
	std::function<void()> popTask();

private:
	std::queue<std::function<void()>>* _taskQueue;
};

