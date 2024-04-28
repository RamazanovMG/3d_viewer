/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QOpenGLWidget *openGLWidget;
    QWidget *widgetControlPanel;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *layoutControlPanelMain;
    QGridLayout *gridLayout;
    QPushButton *buttonOpen;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *buttonJpg;
    QPushButton *buttonBmp;
    QPushButton *buttonGif;
    QCheckBox *checkBoxOrtho;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QRadioButton *radioButtonStripple;
    QFrame *frameLineColor;
    QPushButton *buttonLineColor;
    QRadioButton *radioButtonSolid;
    QSpinBox *spinBoxLineWidth;
    QPushButton *buttonPointColor;
    QFrame *framePointColor;
    QRadioButton *radioButtonPoint;
    QSpinBox *spinBoxPointWidth;
    QCheckBox *checkBoxRound;
    QGroupBox *groupBox_2;
    QPushButton *buttonBGColor;
    QFrame *frameBFColor;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonMove;
    QRadioButton *radioButtonRotate;
    QRadioButton *radioButtonZoom;
    QSpinBox *spinBoxStep;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayoutDirection;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *buttonUp;
    QPushButton *buttonRight;
    QPushButton *buttonDown;
    QPushButton *buttonLeft;
    QPushButton *buttonZ1;
    QPushButton *buttonZ2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 622);
        MainWindow->setMinimumSize(QSize(1000, 622));
        MainWindow->setMaximumSize(QSize(1000, 622));
        MainWindow->setAutoFillBackground(false);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionOpen->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName("openGLWidget");
        openGLWidget->setGeometry(QRect(0, 0, 800, 600));
        widgetControlPanel = new QWidget(centralwidget);
        widgetControlPanel->setObjectName("widgetControlPanel");
        widgetControlPanel->setGeometry(QRect(791, -10, 221, 621));
        verticalLayout_5 = new QVBoxLayout(widgetControlPanel);
        verticalLayout_5->setObjectName("verticalLayout_5");
        layoutControlPanelMain = new QVBoxLayout();
        layoutControlPanelMain->setObjectName("layoutControlPanelMain");
        layoutControlPanelMain->setSizeConstraint(QLayout::SetDefaultConstraint);
        layoutControlPanelMain->setContentsMargins(10, 10, 10, 10);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        buttonOpen = new QPushButton(widgetControlPanel);
        buttonOpen->setObjectName("buttonOpen");
        buttonOpen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));

        gridLayout->addWidget(buttonOpen, 0, 0, 1, 1);


        layoutControlPanelMain->addLayout(gridLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        buttonJpg = new QPushButton(widgetControlPanel);
        buttonJpg->setObjectName("buttonJpg");
        buttonJpg->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));

        horizontalLayout_5->addWidget(buttonJpg);

        buttonBmp = new QPushButton(widgetControlPanel);
        buttonBmp->setObjectName("buttonBmp");
        buttonBmp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));

        horizontalLayout_5->addWidget(buttonBmp);

        buttonGif = new QPushButton(widgetControlPanel);
        buttonGif->setObjectName("buttonGif");
        buttonGif->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));

        horizontalLayout_5->addWidget(buttonGif);


        layoutControlPanelMain->addLayout(horizontalLayout_5);

        checkBoxOrtho = new QCheckBox(widgetControlPanel);
        checkBoxOrtho->setObjectName("checkBoxOrtho");
        checkBoxOrtho->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"    width: 9px;\n"
"    height: 9px;\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: 2px solid #000000;\n"
"}\n"
""));

        layoutControlPanelMain->addWidget(checkBoxOrtho);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutControlPanelMain->addItem(verticalSpacer);

        groupBox = new QGroupBox(widgetControlPanel);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(180, 167));
        groupBox->setMaximumSize(QSize(182, 167));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: transparent;\n"
"    border: 2px solid #383838; /* \320\246\320\262\320\265\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 */\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    margin-top: 10px;\n"
"}\n"
"\n"
"QGroupBox:title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    left: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\273\320\265\320\262\320\260 \320\276\321\202 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260 */\n"
"    padding: 1px 10px;\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260 */\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260 */\n"
"    border: 2px solid #383838; /* \320\246\320\262\320\265"
                        "\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260 */\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QGroupBox:hover {\n"
"    border: 2px solid #1976D2; /* \320\246\320\262\320\265\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QGroupBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    background-color: #2196F3; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\320\260 */\n"
"    border: 2px solid #2196F3; /* \320\246\320\262\320\265\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\320\260 */\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QGroupBox::indicator:checked {\n"
"    backgr"
                        "ound-color: #1976D2; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\320\260 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: 2px solid #1976D2; /* \320\246\320\262\320\265\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\320\260 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"}\n"
""));
        radioButtonStripple = new QRadioButton(groupBox);
        radioButtonStripple->setObjectName("radioButtonStripple");
        radioButtonStripple->setGeometry(QRect(82, 28, 79, 23));
        radioButtonStripple->setMinimumSize(QSize(0, 0));
        radioButtonStripple->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 9px;\n"
"    height: 9px;\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:pressed {\n"
"    background-color: #ffe500; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
""));
        frameLineColor = new QFrame(groupBox);
        frameLineColor->setObjectName("frameLineColor");
        frameLineColor->setGeometry(QRect(80, 62, 20, 20));
        frameLineColor->setMinimumSize(QSize(0, 0));
        frameLineColor->setMaximumSize(QSize(1000, 1000));
        frameLineColor->setFrameShape(QFrame::NoFrame);
        frameLineColor->setFrameShadow(QFrame::Raised);
        buttonLineColor = new QPushButton(groupBox);
        buttonLineColor->setObjectName("buttonLineColor");
        buttonLineColor->setGeometry(QRect(110, 57, 60, 30));
        buttonLineColor->setMinimumSize(QSize(60, 30));
        buttonLineColor->setMaximumSize(QSize(60, 30));
        buttonLineColor->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        radioButtonSolid = new QRadioButton(groupBox);
        radioButtonSolid->setObjectName("radioButtonSolid");
        radioButtonSolid->setGeometry(QRect(10, 28, 65, 23));
        radioButtonSolid->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 9px;\n"
"    height: 9px;\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:pressed {\n"
"    background-color: #ffe500; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
""));
        radioButtonSolid->setChecked(true);
        spinBoxLineWidth = new QSpinBox(groupBox);
        spinBoxLineWidth->setObjectName("spinBoxLineWidth");
        spinBoxLineWidth->setGeometry(QRect(10, 60, 60, 25));
        spinBoxLineWidth->setMaximumSize(QSize(16777215, 16777215));
        spinBoxLineWidth->setStyleSheet(QString::fromUtf8("QSpinBox {     background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}"));
        spinBoxLineWidth->setAlignment(Qt::AlignCenter);
        spinBoxLineWidth->setMinimum(1);
        spinBoxLineWidth->setMaximum(10);
        buttonPointColor = new QPushButton(groupBox);
        buttonPointColor->setObjectName("buttonPointColor");
        buttonPointColor->setGeometry(QRect(110, 123, 60, 30));
        buttonPointColor->setMinimumSize(QSize(60, 30));
        buttonPointColor->setMaximumSize(QSize(60, 30));
        buttonPointColor->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        framePointColor = new QFrame(groupBox);
        framePointColor->setObjectName("framePointColor");
        framePointColor->setGeometry(QRect(80, 128, 20, 20));
        framePointColor->setMinimumSize(QSize(0, 0));
        framePointColor->setMaximumSize(QSize(1000, 1000));
        framePointColor->setFrameShape(QFrame::NoFrame);
        framePointColor->setFrameShadow(QFrame::Raised);
        radioButtonPoint = new QRadioButton(groupBox);
        radioButtonPoint->setObjectName("radioButtonPoint");
        radioButtonPoint->setGeometry(QRect(10, 94, 79, 23));
        radioButtonPoint->setMinimumSize(QSize(0, 0));
        radioButtonPoint->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 9px;\n"
"    height: 9px;\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:pressed {\n"
"    background-color: #ffe500; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
""));
        spinBoxPointWidth = new QSpinBox(groupBox);
        spinBoxPointWidth->setObjectName("spinBoxPointWidth");
        spinBoxPointWidth->setGeometry(QRect(10, 126, 60, 25));
        spinBoxPointWidth->setMaximumSize(QSize(16777215, 16777215));
        spinBoxPointWidth->setStyleSheet(QString::fromUtf8("QSpinBox {     background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}"));
        spinBoxPointWidth->setAlignment(Qt::AlignCenter);
        spinBoxPointWidth->setMinimum(1);
        spinBoxPointWidth->setMaximum(10);
        checkBoxRound = new QCheckBox(groupBox);
        checkBoxRound->setObjectName("checkBoxRound");
        checkBoxRound->setGeometry(QRect(83, 94, 92, 23));
        checkBoxRound->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"    width: 9px;\n"
"    height: 9px;\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: 2px solid #000000;\n"
"}\n"
""));

        layoutControlPanelMain->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widgetControlPanel);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(180, 68));
        groupBox_2->setMaximumSize(QSize(182, 68));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: transparent;\n"
"    border: 2px solid #383838; /* \320\246\320\262\320\265\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 */\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    margin-top: 10px;\n"
"}\n"
"\n"
"QGroupBox:title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    left: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\273\320\265\320\262\320\260 \320\276\321\202 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260 */\n"
"    padding: 1px 10px;\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260 */\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260 */\n"
"    border: 2px solid #383838; /* \320\246\320\262\320\265"
                        "\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260 */\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QGroupBox:hover {\n"
"    border: 2px solid #1976D2; /* \320\246\320\262\320\265\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QGroupBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    background-color: #2196F3; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\320\260 */\n"
"    border: 2px solid #2196F3; /* \320\246\320\262\320\265\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\320\260 */\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QGroupBox::indicator:checked {\n"
"    backgr"
                        "ound-color: #1976D2; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\320\260 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: 2px solid #1976D2; /* \320\246\320\262\320\265\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\320\260 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"}\n"
""));
        buttonBGColor = new QPushButton(groupBox_2);
        buttonBGColor->setObjectName("buttonBGColor");
        buttonBGColor->setGeometry(QRect(110, 25, 60, 30));
        buttonBGColor->setMinimumSize(QSize(60, 30));
        buttonBGColor->setMaximumSize(QSize(60, 30));
        buttonBGColor->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        frameBFColor = new QFrame(groupBox_2);
        frameBFColor->setObjectName("frameBFColor");
        frameBFColor->setGeometry(QRect(80, 30, 20, 20));
        frameBFColor->setMinimumSize(QSize(20, 20));
        frameBFColor->setMaximumSize(QSize(20, 20));
        frameBFColor->setFrameShape(QFrame::NoFrame);
        frameBFColor->setFrameShadow(QFrame::Raised);

        layoutControlPanelMain->addWidget(groupBox_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutControlPanelMain->addItem(verticalSpacer_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        radioButtonMove = new QRadioButton(widgetControlPanel);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(radioButtonMove);
        radioButtonMove->setObjectName("radioButtonMove");
        radioButtonMove->setMinimumSize(QSize(0, 24));
        radioButtonMove->setMaximumSize(QSize(16777215, 24));
        radioButtonMove->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 9px;\n"
"    height: 9px;\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:pressed {\n"
"    background-color: #ffe500; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
""));
        radioButtonMove->setChecked(true);

        verticalLayout_3->addWidget(radioButtonMove);

        radioButtonRotate = new QRadioButton(widgetControlPanel);
        buttonGroup->addButton(radioButtonRotate);
        radioButtonRotate->setObjectName("radioButtonRotate");
        radioButtonRotate->setMinimumSize(QSize(0, 24));
        radioButtonRotate->setMaximumSize(QSize(16777215, 24));
        radioButtonRotate->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 9px;\n"
"    height: 9px;\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:pressed {\n"
"    background-color: #ffe500; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
""));

        verticalLayout_3->addWidget(radioButtonRotate);

        radioButtonZoom = new QRadioButton(widgetControlPanel);
        buttonGroup->addButton(radioButtonZoom);
        radioButtonZoom->setObjectName("radioButtonZoom");
        radioButtonZoom->setMinimumSize(QSize(0, 24));
        radioButtonZoom->setMaximumSize(QSize(16777215, 24));
        radioButtonZoom->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 9px;\n"
"    height: 9px;\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QRadioButton::indicator:pressed {\n"
"    background-color: #ffe500; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"    border: 2px solid #000000;\n"
"	border-radius: 3px;\n"
"}\n"
""));

        verticalLayout_3->addWidget(radioButtonZoom);

        spinBoxStep = new QSpinBox(widgetControlPanel);
        spinBoxStep->setObjectName("spinBoxStep");
        spinBoxStep->setMaximumSize(QSize(60, 16777215));
        spinBoxStep->setStyleSheet(QString::fromUtf8("QSpinBox {     background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}"));
        spinBoxStep->setAlignment(Qt::AlignCenter);
        spinBoxStep->setMinimum(1);
        spinBoxStep->setMaximum(999);
        spinBoxStep->setValue(100);

        verticalLayout_3->addWidget(spinBoxStep);


        horizontalLayout_9->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        gridLayoutDirection = new QGridLayout();
        gridLayoutDirection->setObjectName("gridLayoutDirection");
        horizontalSpacer_4 = new QSpacerItem(27, 27, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayoutDirection->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(27, 27, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayoutDirection->addItem(horizontalSpacer_6, 4, 2, 1, 1);

        buttonUp = new QPushButton(widgetControlPanel);
        buttonUp->setObjectName("buttonUp");
        buttonUp->setMinimumSize(QSize(27, 27));
        buttonUp->setMaximumSize(QSize(27, 27));
        buttonUp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));

        gridLayoutDirection->addWidget(buttonUp, 1, 1, 1, 1);

        buttonRight = new QPushButton(widgetControlPanel);
        buttonRight->setObjectName("buttonRight");
        buttonRight->setMinimumSize(QSize(27, 27));
        buttonRight->setMaximumSize(QSize(27, 27));
        buttonRight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        buttonRight->setCheckable(false);
        buttonRight->setFlat(false);

        gridLayoutDirection->addWidget(buttonRight, 2, 2, 1, 1);

        buttonDown = new QPushButton(widgetControlPanel);
        buttonDown->setObjectName("buttonDown");
        buttonDown->setMinimumSize(QSize(27, 27));
        buttonDown->setMaximumSize(QSize(27, 27));
        buttonDown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));

        gridLayoutDirection->addWidget(buttonDown, 4, 1, 1, 1);

        buttonLeft = new QPushButton(widgetControlPanel);
        buttonLeft->setObjectName("buttonLeft");
        buttonLeft->setMinimumSize(QSize(27, 27));
        buttonLeft->setMaximumSize(QSize(27, 27));
        buttonLeft->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));

        gridLayoutDirection->addWidget(buttonLeft, 2, 0, 1, 1);

        buttonZ1 = new QPushButton(widgetControlPanel);
        buttonZ1->setObjectName("buttonZ1");
        buttonZ1->setMinimumSize(QSize(27, 27));
        buttonZ1->setMaximumSize(QSize(27, 27));
        buttonZ1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        buttonZ1->setCheckable(false);
        buttonZ1->setFlat(false);

        gridLayoutDirection->addWidget(buttonZ1, 1, 2, 1, 1);

        buttonZ2 = new QPushButton(widgetControlPanel);
        buttonZ2->setObjectName("buttonZ2");
        buttonZ2->setMinimumSize(QSize(27, 27));
        buttonZ2->setMaximumSize(QSize(27, 27));
        buttonZ2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #383838; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 262626*/\n"
"    color: #ffffff; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0a27; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        buttonZ2->setCheckable(false);
        buttonZ2->setFlat(false);

        gridLayoutDirection->addWidget(buttonZ2, 4, 0, 1, 1);


        horizontalLayout_9->addLayout(gridLayoutDirection);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        layoutControlPanelMain->addLayout(horizontalLayout_9);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutControlPanelMain->addItem(verticalSpacer_3);

        label = new QLabel(widgetControlPanel);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 85));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-color: #383838;\n"
"	border: 2px solid #383838; /* \320\246\320\262\320\265\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260 */\n"
"    border-radius: 5px;\n"
"}\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icon/image6.jpeg")));

        layoutControlPanelMain->addWidget(label);


        verticalLayout_5->addLayout(layoutControlPanelMain);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        buttonRight->setDefault(false);
        buttonZ1->setDefault(false);
        buttonZ2->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        buttonOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        buttonJpg->setText(QCoreApplication::translate("MainWindow", "JPG", nullptr));
        buttonBmp->setText(QCoreApplication::translate("MainWindow", "BMP", nullptr));
        buttonGif->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        checkBoxOrtho->setText(QCoreApplication::translate("MainWindow", "Parallel projection", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Lines", nullptr));
        radioButtonStripple->setText(QCoreApplication::translate("MainWindow", "Stripple", nullptr));
        buttonLineColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        radioButtonSolid->setText(QCoreApplication::translate("MainWindow", "Solid", nullptr));
        buttonPointColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        radioButtonPoint->setText(QCoreApplication::translate("MainWindow", "Point", nullptr));
        checkBoxRound->setText(QCoreApplication::translate("MainWindow", "Round", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Background", nullptr));
        buttonBGColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        radioButtonMove->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        radioButtonRotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        radioButtonZoom->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        buttonUp->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        buttonRight->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        buttonDown->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        buttonLeft->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        buttonZ1->setText(QCoreApplication::translate("MainWindow", "\342\206\273", nullptr));
        buttonZ2->setText(QCoreApplication::translate("MainWindow", "\342\206\272", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
