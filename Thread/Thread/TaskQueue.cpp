#include "TaskQueue.h"

std::mutex g_lock;

TaskQueue::TaskQueue()
{
    _taskQueue = new std::queue<std::function<void()>>;
}

bool TaskQueue::pushTask(std::function<void()> task)
{
    g_lock.lock();
    _taskQueue->push(task);
    g_lock.unlock();

    return 1;
}

std::function<void()> TaskQueue::popTask()
{
    std::function<void()> task;

    g_lock.lock();
    if (!_taskQueue->empty())
    {
        task = _taskQueue->front();
        _taskQueue->pop();
    }
    else
    {
        task = NULL;
    }
    g_lock.unlock();

    return task;
}
