#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include <QMainWindow>
#include <memory>
#include "signals_src.h"
#include "ui_main_view.h"

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = nullptr);

private:
    void onReady();
    void start();
    void stop();

private:
    Ui::MainView _ui;
    SignalsSrc _src;
    long long int _results{ 0 };
};

#endif // MAIN_VIEW_H
