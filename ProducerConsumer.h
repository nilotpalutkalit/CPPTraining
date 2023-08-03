#pragma once

#include <mutex>
#include <condition_variable>
#include <queue>
#include <future>
#include <chrono>
#include <iostream>

using namespace std;

template<typename T>
class ProducerConsumer
{
private:
    std::condition_variable m_cv;
    std::mutex m_mutex;
    std::queue<T> m_data;
    bool exitCondition = false;

public:
    void Produce() {
        static double d = 0.0;
        if (!std::is_arithmetic<T>::value)
        {
            std::cout << "Value is " << std::is_arithmetic<T>::value << "\n";
            return;
        }
        while (!exitCondition)
        {
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                std::unique_lock<std::mutex> lock(m_mutex);
                if (m_data.size() >= 5)
                {
                    m_cv.notify_all();
                    continue;
                }
                //std::cout << "Lock Acquired By Producer " << std::this_thread::get_id() << endl;
                T t = static_cast<T>(++d);
                m_data.push(t);
                m_cv.notify_all();
            }
            //std::cout << "Lock Freed By Producer " << std::this_thread::get_id() << endl;
        }
    }

    void Consume() {
        while (!exitCondition)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            //m_cv.wait(lock); //Spurious Wake
            m_cv.wait(lock, [&]() { return !m_data.empty(); });
            std::cout << "Lock Acquired By Condition Variable Consumer " << std::this_thread::get_id() << endl;
            if (!m_data.empty())
            {
                std::cout << "Data Consume " << m_data.front() << " " << m_data.size() << "\n";
                m_data.pop();
            }
            else
            {
                std::cout << "Lock Acquired By Condition Variable when size is 0 Consumer " << std::this_thread::get_id() << endl;
            }
        }
    }

    void Execute()
    {
        std::packaged_task<bool()> task([&]() {
            int a;
            std::cin >> a;
            if (a == 1)
            {
                exitCondition = true;
                return true;
            }
            return false;
        });
        std::future<bool> result = task.get_future();
        std::thread resultThread(std::move(task));
        std::thread producerThread(&ProducerConsumer::Produce, this);
        std::thread producerThread2(&ProducerConsumer::Produce, this);
        std::thread producerThread3(&ProducerConsumer::Produce, this);
        std::thread producerThread4(&ProducerConsumer::Produce, this);
        std::thread producerThread5(&ProducerConsumer::Produce, this);
        std::thread producerThread6(&ProducerConsumer::Produce, this);
        std::thread consumerThread(&ProducerConsumer::Consume, this);
        std::thread consumerThread2(&ProducerConsumer::Consume, this);

        resultThread.detach();
        producerThread.join();
        producerThread2.join();
        producerThread3.join();
        producerThread4.join();
        producerThread5.join();
        producerThread6.join();
        consumerThread.join();
        consumerThread2.join();
        result.wait();

    }

};

