#include "signals_src.h"

SignalsSrc::SignalsSrc(QObject *parent)
    : QObject{ parent }
{
}

SignalsSrc::~SignalsSrc()
{
    stop();
}

void SignalsSrc::start()
{
    stop();

    _doStop = false;
    _thread = std::make_unique<std::thread>(&SignalsSrc::run, this);
}

void SignalsSrc::stop()
{
    _doStop = true;
    if (_thread != nullptr)
    {
        if (_thread->joinable())
            _thread->join();
        _thread.reset();
    }
}

void SignalsSrc::run()
{
    while(!_doStop)
    {
        emit ready();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
