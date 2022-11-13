#include "mainwindow.h"
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QListWidgetItem>
#include <QWidget>
#include <QMessageBox>
#include <QKeyEvent>
#include <QEvent>

int cnt, cnt2, removed;
void MainWindow::CreateGUI()
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(leText, 0, 0);
    grid->addWidget(lwWords, 1, 0);
    grid->addWidget(lwLogs, 1, 1);
    grid->addWidget(btnSend, 0, 1);
    grid->addWidget(btnRemove, 2, 0);
    grid->addWidget(btnClear, 2, 1);

    setLayout(grid);
}

void MainWindow::CustomizeLayout()
{
    leText->setPlaceholderText("Type a word or a sentence . . .");
    btnSend->setStyleSheet("QPushButton {color: green}");
    btnRemove->setStyleSheet("QPushButton {color: red}");
    btnClear->setStyleSheet("QPushButton {color: blue}");
}

void MainWindow::btnSend_clicked()
{
    QListWidgetItem* itm = new QListWidgetItem();
    QListWidgetItem* log_itm = new QListWidgetItem();

    itm->setText(leText->text());
    if (leText->text() != "")
    {
        ++cnt;
        ++cnt2;
        lwWords->addItem(itm);
        QString str = QString::number(cnt + removed);
        QString text = leText->text();
        str.append(". ");
        str.append('"' + text + '"');
        str.append("successfully added to the list widget ✔");
        log_itm->setText(str);
        lwLogs->addItem(log_itm);
    }

    else
    {
        log_itm->setText("! Can't perform this action");
        lwLogs->addItem(log_itm);
    }

    leText->setText("");
}

void MainWindow::btnRemove_clicked()
{
    if (lwWords->count())
    {
        ++removed;
        QListWidgetItem* text_item = lwWords->takeItem(cnt2 - 1);
        QString text = text_item->text();
        lwWords->removeItemWidget(lwWords->item(cnt2 - 1));

        QListWidgetItem* log_itm_r = new QListWidgetItem();
        QString str = QString::number(cnt + removed);

        str.append(". ");
        str.append('"' + text + '"');
        str.append("was removed from the list widget");

        log_itm_r->setText(str);
        lwLogs->addItem(log_itm_r);

        --cnt2;
    }

      else
        QMessageBox::critical(this, tr("Error"), tr("The list widget is empty !"));
}

void MainWindow::btnClear_clicked()
{
    cnt2 = 0;
    QListWidgetItem* cleared = new QListWidgetItem;
    QString str = "The List widget was succesfully cleared !";
    cleared->setText(str);

    if (lwWords->count())
    {
        lwWords->clear();
        lwLogs->addItem(cleared);
    }

    else
        QMessageBox::warning(this, "Warning", "The list widget is empty !");
}

void MainWindow::CreateConnections()
{
    connect(btnSend, SIGNAL(clicked()),
            this, SLOT(btnSend_clicked()));

    connect(btnRemove, SIGNAL(clicked()),
            this, SLOT(btnRemove_clicked()));

    connect(btnClear, SIGNAL(clicked()),
            this, SLOT(btnClear_clicked()));
}

MainWindow::MainWindow(QWidget *parent) :
    QWidget {parent},
    leText {new QLineEdit},
    lwWords {new QListWidget},
    lwLogs {new QListWidget},
    btnSend {new QPushButton(tr("Send"))},
    btnRemove {new QPushButton(tr("Remove"))},
    btnClear {new QPushButton(tr("Clear"))}
{
    CreateGUI();
    CustomizeLayout();
    CreateConnections();
}
