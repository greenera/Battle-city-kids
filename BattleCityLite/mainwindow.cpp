#include "mainwindow.h"
#include "ui_mainwindow.h"

/*!
 * \brief MainWindow::MainWindow
 * \param parent
 * \details Should have one big field called Presented.
 * In Presented will be loaded:
 *  - menu (for choosing options)
 *  - reached level (in wich game will play)
 * This class should have information:
 *  -about first level widget
 *  -about menu widget
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/*!
 * \brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}
