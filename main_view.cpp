#include "main_view.h"

MainView::MainView(QWidget *parent)
    : QMainWindow{ parent }
{
    _ui.setupUi(this);

    connect(_ui.start, &QPushButton::clicked, this, &MainView::start);
    connect(_ui.stop, &QPushButton::clicked, this, &MainView::stop);
    connect(&_src, &SignalsSrc::ready, this, &MainView::onReady, Qt::QueuedConnection);
}

void MainView::onReady()
{
    _results += 1;
    _ui.result->setText(QString::number(_results));
}

void MainView::start()
{
    _src.start();
}

void MainView::stop()
{
    _src.stop();
}
