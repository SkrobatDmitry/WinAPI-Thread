#include "TaskQueue.h"

std::mutex g_lock;

TaskQueue::TaskQueue()
{
    taskQueue = new std::queue<std::function<void()>>;
}

TaskQueue::~TaskQueue()
{
    delete taskQueue;
}

bool TaskQueue::pushTask(std::function<void()> task)
{
    g_lock.lock();
    taskQueue->push(task);
    g_lock.unlock();

    return 1;
}

std::function<void()> TaskQueue::popTask()
{
    std::function<void()> task;

    g_lock.lock();
    if (!taskQueue->empty())
    {
        task = taskQueue->front();
        taskQueue->pop();
    }
    else
    {
        task = NULL;
    }
    g_lock.unlock();

    return task;
}
