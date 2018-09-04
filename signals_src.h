#ifndef SIGNALS_SRC_H
#define SIGNALS_SRC_H

#include <atomic>
#include <memory>
#include <thread>
#include <QObject>

class SignalsSrc : public QObject
{
    Q_OBJECT

public:
    explicit SignalsSrc(QObject *parent = nullptr);
    ~SignalsSrc() override;

    void start();
    void stop();

private:
    void run();

signals:
    void ready();

private:
    std::atomic<bool> _doStop{ false };
    std::unique_ptr<std::thread> _thread;
};

#endif // SIGNALS_SRC_H
