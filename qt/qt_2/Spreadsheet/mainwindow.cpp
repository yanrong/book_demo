#include <QtGui>

#include "mainwindow.h"
#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"
#include "spreadsheet.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
    spreadsheet=new Spreadsheet;
    setCentralWidget(spreadsheet);
    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();
    findDialog=0;

    setWindowIcon(QIcon(":/image/icon.png"));
    setCurrentFile("");
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open..."), this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing spreadsheet file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the spreadsheet to disk"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAction = new QAction(tr("Save &As..."), this);
    saveAsAction->setStatusTip(tr("Save the spreadsheet under a new ""name"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    for(int i=0;i<MaxRecentFiles;i++){
        recentFileActions=new QAction(this);
        recentFileActions->setVisible(true);
        connect(recentFileActions[i],SIGNAL(triggered()),this,SLOT(openRecentFile()));
    }

    exitAction=new QAction(tr("E&xit"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
    connect(selectAllAction,SIGNAL(triggered()),this,SLOT(close()));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/images/cut.png"));
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut the current selection's contents ""to the clipboard"));
    connect(cutAction, SIGNAL(triggered()), spreadsheet, SLOT(cut()));

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/images/copy.png"));
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy the current selection's contents ""to the clipboard"));
    connect(copyAction, SIGNAL(triggered()), spreadsheet, SLOT(copy()));

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setIcon(QIcon(":/images/paste.png"));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the clipboard's contents into ""the current selection"));
    connect(pasteAction, SIGNAL(triggered()),spreadsheet, SLOT(paste()));

    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setShortcut(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("Delete the current selection's ""contents"));
    connect(deleteAction, SIGNAL(triggered()),spreadsheet, SLOT(del()));

    selectRowAction = new QAction(tr("&Row"), this);
    selectRowAction->setStatusTip(tr("Select all the cells in the ""current row"));
    connect(selectRowAction, SIGNAL(triggered()),spreadsheet, SLOT(selectCurrentRow()));

    selectColumnAction = new QAction(tr("&Column"), this);
    selectColumnAction->setStatusTip(tr("Select all the cells in the ""current column"));
    connect(selectColumnAction, SIGNAL(triggered()),spreadsheet, SLOT(selectCurrentColumn()));

    selectAllAction = new QAction(tr("&All"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all the cells in the ""spreadsheet"));
    connect(selectAllAction, SIGNAL(triggered()),spreadsheet, SLOT(selectAll()));

    findAction = new QAction(tr("&Find..."), this);
    findAction->setIcon(QIcon(":/images/find.png"));
    findAction->setShortcut(QKeySequence::Find);
    findAction->setStatusTip(tr("Find a matching cell"));
    connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

    goToCellAction = new QAction(tr("&Go to Cell..."), this);
    goToCellAction->setIcon(QIcon(":/images/gotocell.png"));
    goToCellAction->setShortcut(tr("Ctrl+G"));
    goToCellAction->setStatusTip(tr("Go to the specified cell"));
    connect(goToCellAction, SIGNAL(triggered()),this, SLOT(goToCell()));

    recalculateAction = new QAction(tr("&Recalculate"), this);
    recalculateAction->setShortcut(tr("F9"));
    recalculateAction->setStatusTip(tr("Recalculate all the ""spreadsheet's formulas"));
    connect(recalculateAction, SIGNAL(triggered()),spreadsheet, SLOT(recalculate()));

    sortAction = new QAction(tr("&Sort..."), this);
    sortAction->setStatusTip(tr("Sort the selected cells or all the cells"));
    connect(sortAction, SIGNAL(triggered()), this, SLOT(sort()));

    showGridAction = new QAction(tr("&Show Grid"), this);
    showGridAction->setCheckable(true);
    showGridAction->setChecked(spreadsheet->showGrid());
    showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
    connect(showGridAction, SIGNAL(toggled(bool)),
            spreadsheet, SLOT(setShowGrid(bool)));
    #if QT_VERSION < 0x040102
        // workaround for a QTableWidget bug in Qt 4.1.1
        connect(showGridAction, SIGNAL(toggled(bool)),spreadsheet->viewport(), SLOT(update()));
    #endif

    autoRecalcAction = new QAction(tr("&Auto-Recalculate"), this);
    autoRecalcAction->setCheckable(true);
    autoRecalcAction->setChecked(spreadsheet->autoRecalculate());
    autoRecalcAction->setStatusTip(tr("Switch auto-recalculation on or off"));
    connect(autoRecalcAction, SIGNAL(toggled(bool)),spreadsheet, SLOT(setAutoRecalculate(bool)));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    fileMenu=menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction=fileMenu->addSeparator();

    for(int i=0;i<MaxRecentFiles;i++)
        fileMenu->addAction(recentFileActions[i]);

    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu=menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(deleteAction);

    selectSubMenu=editMenu()->addMenu(tr("&Select"));
    selectSubMenu->addAction(selectRowAction);
    selectSubMenu->addAction(selectColumnAction);
    selectSubMenu->addAction(selectAllAction);

    editMenu->addSeparator();
    editMenu->addAction(findAction);
    editMenu->addAction(goToCellAction);

    toolsMenu=menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(recalculateAction);
    toolsMenu->addAction(sortAction);

    optionsMenu=menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(showGridAction);
    optionsMenu->addAction(autoRecalcAction);

    menuBar()->addSeparator();

    helpMenu=menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu()
{
    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);
    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBar()
{
    fileToolBar=addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar=addToolBar(tr("&Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(findAction);
    editToolBar->addAction(goToCellAction);
}

void MainWindow::createStatusBar()
{
    locationLabel=new QLabel("W999 ");
    locationLabel->setAlignment(Qt::AlignCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel=new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel,1);

    connect(spreadsheet,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(updateStatusBar()));
    connect(spreadsheet,SIGNAL(modify()),this,SLOT(spreadsheetModified()));

    updateStatusBar();
}

void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadsheet->currentLocation);
    formulaLabel->setText(spreadsheet->currentFormula);
}

void MainWindow::spreadsheetModified()
{
    setWindowModality(true);
    updateStatusBar();
}

void MainWindow::newFile()
{
    if(okToContinue()){
        spreadsheet->clear();
        setCurrentFile("");
    }
}

bool MainWindow::okToContinue()
{
    if(isWindowModified()){
        int r=QMessageBox::warning(this,tr("Spreadsheet"),tr("The docment has been modified.\n"
                                                             "do you want save your changes?"),
                                   QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        if(r=QMessageBox::Yes)
            return save();
        else if(r=QMessageBox::Cancel)
            return false;
    }
    return true;
}

void MainWindow::open()
{
    if(okToContinue()){
        //.....
        QString fileName=QFileDialog::getOpenFileName(this,tr("Open Spreadsheet"),".",tr("Spreadsheet files(*.sp"));

        if(!fileName.isEmpty())
            loadFile(fileName);
    }
}

bool MainWindow::loadFile(const QString &fileName)
{
    if(!spreadsheet->readFile(fileName)){
        statusBar()->showMessage(tr("Loading canceled",2000));
        return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"),2000);
}

bool MainWindow::save()
{
    if(curFile.isEmpty()){
        return saveAs();
    }else{
        return saveFile(curFile);
    }
}

bool MainWindow::saveFile(const QString &fileName)
{
    if(!spreadsheet->writeFile(fileName)){
        statusBar()->showMessage(tr("Saving canceled"),2000);
        return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"),2000);
    return true;
}

bool MainWindow::saveAs()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save Spreadsheet"),
                                                  ".",tr("Spreadsheet file(*.sp)"));
    if(fileName.isEmpty())
        return false;
   return saveFile(fileName);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(okToContinue()){
        writeSettings();
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile=fileName;
    setWindowModified(false);

    QString shownName=tr("Untitled");
    if(!curFile.isEmpty()){
        shownName=strippedName(curFile);
        recentFiles.removeAll(curFile);
        recentFiles.prepend(curFile);
        updateRecentFileActions();
    }

    setWindowTitle(tr("%1[*] - %2").arg());
}

void MainWindow::updateRecentFileActions()
{
    QMutableStringListIterator i(recentFiles);

    if(i.hasNext()){
        if(!QFile::exists(i.next()))
            i.remove();
    }

    for(int j=0;j<MaxRecentFiles;j++){
        if(j<recentFiles.count()){
            QString text=tr("&%1 %2").arg(j+1).arg(strippedName(recentFiles[i]));
            recentFileActions[j]->setText(text);
            recentFileActions[j]->setData(recentFiles[j]);
            recentFileActions[j]->setVisible(true);
        }else{
            recentFileActions[j]->setVisible(false);
        }
    }
    separatorAction->setVisible(!recentFiles.isEmpty());
}

void MainWindow::openRecentFile()
{
    if(okToContinue()){
        QAction *action=new qobject_cast<QAction *>(sender());
        if(action)
            loadFile(action->data().toString());
    }
}

