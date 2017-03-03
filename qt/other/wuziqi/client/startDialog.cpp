//startDialog.cpp
#include "startDialog.h"

StartDialog::StartDialog(QWidget* parent)
    :QDialog(parent)
{
    hostLabel = new QLabel(tr("Server name:"));
    portLabel = new QLabel(tr("Server port:"));

    hostLineEdit = new QLineEdit("Localhost");
    portLineEdit = new QLineEdit;
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    hostLabel->setBuddy(hostLineEdit);
    portLabel->setBuddy(portLineEdit);

    statusLabel = new QLabel(QObject::tr("please ensure the server(black chess) already running"));

    startButton = new QPushButton(tr("&Start"));
    startButton->setDefault(true);
    startButton->setEnabled(false);

    quitButton = new QPushButton(tr("&Quit"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(hostLineEdit, SIGNAL(textChanged(const QString&)),this, SLOT(enableStartButton()));
    connect(portLineEdit, SIGNAL(textChanged(const QString&)),this,SLOT(enableStartButton()));
    connect(startButton, SIGNAL(clicked()),this, SLOT(doStart()));
    connect(quitButton, SIGNAL(clicked()),this, SLOT(doQuit()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(hostLineEdit, 0, 1);
    mainLayout->addWidget(portLabel, 1, 0);
    mainLayout->addWidget(portLineEdit, 1, 1);
    mainLayout->addWidget(statusLabel, 2, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(QObject::tr("Client: white chess"));
    portLineEdit->setFocus();
}

void StartDialog::doStart()
{
    emit start(hostLineEdit->text(), portLineEdit->text());
    accept();
}

void StartDialog::enableStartButton()
{
    startButton->setEnabled(!hostLineEdit->text().isEmpty()
                            && !portLineEdit->text().isEmpty());
}

void StartDialog::doQuit()
{
    emit quitClient();
    close();
}
