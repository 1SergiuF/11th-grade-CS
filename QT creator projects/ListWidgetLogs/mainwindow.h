#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QEvent>

class MainWindow : public QWidget
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void CreateGUI();
    void CustomizeLayout();
    void CreateConnections();

private slots:
    void btnSend_clicked();
    void btnRemove_clicked();
    void btnClear_clicked();

private:
    QLineEdit *leText;
    QListWidget *lwWords;
    QListWidget *lwLogs;
    QPushButton *btnSend;
    QPushButton *btnRemove;
    QPushButton *btnClear;
};

#endif // MAINWINDOW_H
