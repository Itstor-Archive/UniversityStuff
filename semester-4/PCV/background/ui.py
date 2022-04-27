# -*- coding: utf-8 -*-

################################################################################
# Form generated from reading UI file 'untitledfycdsB.ui'
##
# Created by: Qt User Interface Compiler version 5.14.1
##
# WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import (QCoreApplication, QMetaObject, QObject, QPoint,
                            QRect, QSize, QUrl, Qt)
from PySide2.QtGui import (QBrush, QColor, QConicalGradient, QCursor, QFont,
                           QFontDatabase, QIcon, QLinearGradient, QPalette, QPainter, QPixmap,
                           QRadialGradient)
from PySide2.QtWidgets import *


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(880, 587)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        sizePolicy = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.centralwidget.sizePolicy().hasHeightForWidth())
        self.centralwidget.setSizePolicy(sizePolicy)
        self.centralwidget.setMaximumSize(QSize(961, 700))
        self.gridLayout = QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName(u"gridLayout")
        self.verticalLayout = QVBoxLayout()
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.verticalLayout_3 = QVBoxLayout()
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.outputFrame = QFrame(self.centralwidget)
        self.outputFrame.setObjectName(u"outputFrame")
        sizePolicy.setHeightForWidth(
            self.outputFrame.sizePolicy().hasHeightForWidth())
        self.outputFrame.setSizePolicy(sizePolicy)
        self.outputFrame.setMinimumSize(QSize(0, 0))
        self.outputFrame.setFrameShape(QFrame.StyledPanel)
        self.outputFrame.setFrameShadow(QFrame.Raised)

        self.verticalLayout_3.addWidget(self.outputFrame)

        self.horizontalLayout.addLayout(self.verticalLayout_3)

        self.verticalLayout_2 = QVBoxLayout()
        self.verticalLayout_2.setSpacing(0)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.verticalLayout_2.setSizeConstraint(QLayout.SetDefaultConstraint)
        self.verticalLayout_2.setContentsMargins(-1, -1, -1, 0)
        self.foregroundOutpuutButton = QPushButton(self.centralwidget)
        self.foregroundOutpuutButton.setObjectName(u"foregroundOutpuutButton")

        self.verticalLayout_2.addWidget(self.foregroundOutpuutButton)

        self.backgroundOutputButton = QPushButton(self.centralwidget)
        self.backgroundOutputButton.setObjectName(u"backgroundOutputButton")

        self.verticalLayout_2.addWidget(self.backgroundOutputButton)

        self.maskAOutputButton = QPushButton(self.centralwidget)
        self.maskAOutputButton.setObjectName(u"maskAOutputButton")

        self.verticalLayout_2.addWidget(self.maskAOutputButton)

        self.maskBOutputButton = QPushButton(self.centralwidget)
        self.maskBOutputButton.setObjectName(u"maskBOutputButton")

        self.verticalLayout_2.addWidget(self.maskBOutputButton)

        self.outputButton = QPushButton(self.centralwidget)
        self.outputButton.setObjectName(u"outputButton")

        self.verticalLayout_2.addWidget(self.outputButton)

        self.verticalSpacer = QSpacerItem(
            20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.verticalLayout_2.addItem(self.verticalSpacer)

        self.horizontalLayout.addLayout(self.verticalLayout_2)

        self.horizontalLayout.setStretch(0, 9)
        self.horizontalLayout.setStretch(1, 1)

        self.verticalLayout.addLayout(self.horizontalLayout)

        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.verticalLayout_4 = QVBoxLayout()
        self.verticalLayout_4.setObjectName(u"verticalLayout_4")
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        sizePolicy1 = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Minimum)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(
            self.label.sizePolicy().hasHeightForWidth())
        self.label.setSizePolicy(sizePolicy1)

        self.verticalLayout_4.addWidget(self.label)

        self.horizontalLayout_3 = QHBoxLayout()
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.verticalLayout_9 = QVBoxLayout()
        self.verticalLayout_9.setObjectName(u"verticalLayout_9")
        self.foregroundImageButton = QRadioButton(self.centralwidget)
        self.foregroundImageButton.setObjectName(u"foregroundImageButton")

        self.verticalLayout_9.addWidget(self.foregroundImageButton)

        self.foregroundVideoButton = QRadioButton(self.centralwidget)
        self.foregroundVideoButton.setObjectName(u"foregroundVideoButton")

        self.verticalLayout_9.addWidget(self.foregroundVideoButton)

        self.horizontalLayout_3.addLayout(self.verticalLayout_9)

        self.verticalLayout_7 = QVBoxLayout()
        self.verticalLayout_7.setObjectName(u"verticalLayout_7")
        self.foregroundLoadButton = QPushButton(self.centralwidget)
        self.foregroundLoadButton.setObjectName(u"foregroundLoadButton")

        self.verticalLayout_7.addWidget(self.foregroundLoadButton)

        self.horizontalLayout_3.addLayout(self.verticalLayout_7)

        self.verticalLayout_4.addLayout(self.horizontalLayout_3)

        self.line_3 = QFrame(self.centralwidget)
        self.line_3.setObjectName(u"line_3")
        self.line_3.setFrameShape(QFrame.HLine)
        self.line_3.setFrameShadow(QFrame.Sunken)

        self.verticalLayout_4.addWidget(self.line_3)

        self.label_2 = QLabel(self.centralwidget)
        self.label_2.setObjectName(u"label_2")

        self.verticalLayout_4.addWidget(self.label_2)

        self.horizontalLayout_5 = QHBoxLayout()
        self.horizontalLayout_5.setObjectName(u"horizontalLayout_5")
        self.verticalLayout_10 = QVBoxLayout()
        self.verticalLayout_10.setObjectName(u"verticalLayout_10")
        self.backgroundImageButton = QRadioButton(self.centralwidget)
        self.backgroundImageButton.setObjectName(u"backgroundImageButton")

        self.verticalLayout_10.addWidget(self.backgroundImageButton)

        self.backgroundVideoButton = QRadioButton(self.centralwidget)
        self.backgroundVideoButton.setObjectName(u"backgroundVideoButton")

        self.verticalLayout_10.addWidget(self.backgroundVideoButton)

        self.horizontalLayout_5.addLayout(self.verticalLayout_10)

        self.verticalLayout_11 = QVBoxLayout()
        self.verticalLayout_11.setObjectName(u"verticalLayout_11")
        self.backgroundLoadButton = QPushButton(self.centralwidget)
        self.backgroundLoadButton.setObjectName(u"backgroundLoadButton")

        self.verticalLayout_11.addWidget(self.backgroundLoadButton)

        self.horizontalLayout_5.addLayout(self.verticalLayout_11)

        self.verticalLayout_4.addLayout(self.horizontalLayout_5)

        self.horizontalLayout_2.addLayout(self.verticalLayout_4)

        self.line = QFrame(self.centralwidget)
        self.line.setObjectName(u"line")
        self.line.setFrameShape(QFrame.VLine)
        self.line.setFrameShadow(QFrame.Sunken)

        self.horizontalLayout_2.addWidget(self.line)

        self.verticalLayout_14 = QVBoxLayout()
        self.verticalLayout_14.setObjectName(u"verticalLayout_14")
        self.horizontalLayout_14 = QHBoxLayout()
        self.horizontalLayout_14.setSpacing(20)
        self.horizontalLayout_14.setObjectName(u"horizontalLayout_14")
        self.verticalLayout_5 = QVBoxLayout()
        self.verticalLayout_5.setObjectName(u"verticalLayout_5")
        self.verticalLayout_12 = QVBoxLayout()
        self.verticalLayout_12.setObjectName(u"verticalLayout_12")
        self.label_9 = QLabel(self.centralwidget)
        self.label_9.setObjectName(u"label_9")

        self.verticalLayout_12.addWidget(self.label_9)

        self.horizontalLayout_8 = QHBoxLayout()
        self.horizontalLayout_8.setObjectName(u"horizontalLayout_8")
        self.hLowerLabel = QLabel(self.centralwidget)
        self.hLowerLabel.setObjectName(u"hLowerLabel")

        self.horizontalLayout_8.addWidget(self.hLowerLabel)

        self.lineEdit = QLineEdit(self.centralwidget)
        self.lineEdit.setObjectName(u"lineEdit")
        sizePolicy2 = QSizePolicy(
            QSizePolicy.MinimumExpanding, QSizePolicy.Fixed)
        sizePolicy2.setHorizontalStretch(0)
        sizePolicy2.setVerticalStretch(0)
        sizePolicy2.setHeightForWidth(
            self.lineEdit.sizePolicy().hasHeightForWidth())
        self.lineEdit.setSizePolicy(sizePolicy2)

        self.horizontalLayout_8.addWidget(self.lineEdit)

        self.verticalLayout_12.addLayout(self.horizontalLayout_8)

        self.horizontalLayout_10 = QHBoxLayout()
        self.horizontalLayout_10.setObjectName(u"horizontalLayout_10")
        self.sLowerLabel = QLabel(self.centralwidget)
        self.sLowerLabel.setObjectName(u"sLowerLabel")

        self.horizontalLayout_10.addWidget(self.sLowerLabel)

        self.lineEdit_2 = QLineEdit(self.centralwidget)
        self.lineEdit_2.setObjectName(u"lineEdit_2")
        sizePolicy2.setHeightForWidth(
            self.lineEdit_2.sizePolicy().hasHeightForWidth())
        self.lineEdit_2.setSizePolicy(sizePolicy2)

        self.horizontalLayout_10.addWidget(self.lineEdit_2)

        self.verticalLayout_12.addLayout(self.horizontalLayout_10)

        self.horizontalLayout_9 = QHBoxLayout()
        self.horizontalLayout_9.setObjectName(u"horizontalLayout_9")
        self.vLowerLabel = QLabel(self.centralwidget)
        self.vLowerLabel.setObjectName(u"vLowerLabel")

        self.horizontalLayout_9.addWidget(self.vLowerLabel)

        self.lineEdit_3 = QLineEdit(self.centralwidget)
        self.lineEdit_3.setObjectName(u"lineEdit_3")
        sizePolicy2.setHeightForWidth(
            self.lineEdit_3.sizePolicy().hasHeightForWidth())
        self.lineEdit_3.setSizePolicy(sizePolicy2)

        self.horizontalLayout_9.addWidget(self.lineEdit_3)

        self.verticalLayout_12.addLayout(self.horizontalLayout_9)

        self.verticalLayout_5.addLayout(self.verticalLayout_12)

        self.verticalSpacer_3 = QSpacerItem(
            20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.verticalLayout_5.addItem(self.verticalSpacer_3)

        self.horizontalLayout_14.addLayout(self.verticalLayout_5)

        self.verticalLayout_13 = QVBoxLayout()
        self.verticalLayout_13.setObjectName(u"verticalLayout_13")
        self.label_10 = QLabel(self.centralwidget)
        self.label_10.setObjectName(u"label_10")

        self.verticalLayout_13.addWidget(self.label_10)

        self.horizontalLayout_13 = QHBoxLayout()
        self.horizontalLayout_13.setObjectName(u"horizontalLayout_13")
        self.hUpperLabel = QLabel(self.centralwidget)
        self.hUpperLabel.setObjectName(u"hUpperLabel")

        self.horizontalLayout_13.addWidget(self.hUpperLabel)

        self.lineEdit_4 = QLineEdit(self.centralwidget)
        self.lineEdit_4.setObjectName(u"lineEdit_4")
        sizePolicy2.setHeightForWidth(
            self.lineEdit_4.sizePolicy().hasHeightForWidth())
        self.lineEdit_4.setSizePolicy(sizePolicy2)

        self.horizontalLayout_13.addWidget(self.lineEdit_4)

        self.verticalLayout_13.addLayout(self.horizontalLayout_13)

        self.horizontalLayout_11 = QHBoxLayout()
        self.horizontalLayout_11.setObjectName(u"horizontalLayout_11")
        self.sUpperLabel = QLabel(self.centralwidget)
        self.sUpperLabel.setObjectName(u"sUpperLabel")

        self.horizontalLayout_11.addWidget(self.sUpperLabel)

        self.lineEdit_5 = QLineEdit(self.centralwidget)
        self.lineEdit_5.setObjectName(u"lineEdit_5")
        sizePolicy2.setHeightForWidth(
            self.lineEdit_5.sizePolicy().hasHeightForWidth())
        self.lineEdit_5.setSizePolicy(sizePolicy2)

        self.horizontalLayout_11.addWidget(self.lineEdit_5)

        self.verticalLayout_13.addLayout(self.horizontalLayout_11)

        self.horizontalLayout_12 = QHBoxLayout()
        self.horizontalLayout_12.setObjectName(u"horizontalLayout_12")
        self.vUpperLabel = QLabel(self.centralwidget)
        self.vUpperLabel.setObjectName(u"vUpperLabel")

        self.horizontalLayout_12.addWidget(self.vUpperLabel)

        self.lineEdit_6 = QLineEdit(self.centralwidget)
        self.lineEdit_6.setObjectName(u"lineEdit_6")
        sizePolicy2.setHeightForWidth(
            self.lineEdit_6.sizePolicy().hasHeightForWidth())
        self.lineEdit_6.setSizePolicy(sizePolicy2)

        self.horizontalLayout_12.addWidget(self.lineEdit_6)

        self.verticalLayout_13.addLayout(self.horizontalLayout_12)

        self.verticalSpacer_4 = QSpacerItem(
            20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.verticalLayout_13.addItem(self.verticalSpacer_4)

        self.horizontalLayout_14.addLayout(self.verticalLayout_13)

        self.verticalLayout_14.addLayout(self.horizontalLayout_14)

        self.valueUpdateButton = QPushButton(self.centralwidget)
        self.valueUpdateButton.setObjectName(u"valueUpdateButton")

        self.verticalLayout_14.addWidget(self.valueUpdateButton)

        self.horizontalLayout_2.addLayout(self.verticalLayout_14)

        self.line_2 = QFrame(self.centralwidget)
        self.line_2.setObjectName(u"line_2")
        self.line_2.setFrameShape(QFrame.VLine)
        self.line_2.setFrameShadow(QFrame.Sunken)

        self.horizontalLayout_2.addWidget(self.line_2)

        self.verticalLayout_6 = QVBoxLayout()
        self.verticalLayout_6.setObjectName(u"verticalLayout_6")
        self.radioButton_5 = QRadioButton(self.centralwidget)
        self.radioButton_5.setObjectName(u"radioButton_5")

        self.verticalLayout_6.addWidget(self.radioButton_5)

        self.radioButton_6 = QRadioButton(self.centralwidget)
        self.radioButton_6.setObjectName(u"radioButton_6")

        self.verticalLayout_6.addWidget(self.radioButton_6)

        self.verticalSpacer_2 = QSpacerItem(
            20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.verticalLayout_6.addItem(self.verticalSpacer_2)

        self.horizontalLayout_2.addLayout(self.verticalLayout_6)

        self.horizontalLayout_2.setStretch(0, 1)
        self.horizontalLayout_2.setStretch(2, 1)

        self.verticalLayout.addLayout(self.horizontalLayout_2)

        self.verticalLayout.setStretch(0, 7)
        self.verticalLayout.setStretch(1, 3)

        self.gridLayout.addLayout(self.verticalLayout, 0, 0, 1, 1)

        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate(
            "MainWindow", u"MainWindow", None))
        self.foregroundOutpuutButton.setText(
            QCoreApplication.translate("MainWindow", u"Foreground", None))
        self.backgroundOutputButton.setText(
            QCoreApplication.translate("MainWindow", u"Background", None))
        self.maskAOutputButton.setText(
            QCoreApplication.translate("MainWindow", u"Mask A", None))
        self.maskBOutputButton.setText(
            QCoreApplication.translate("MainWindow", u"Mask B", None))
        self.outputButton.setText(
            QCoreApplication.translate("MainWindow", u"Output", None))
        self.label.setText(QCoreApplication.translate(
            "MainWindow", u"Foreground Source", None))
        self.foregroundImageButton.setText(
            QCoreApplication.translate("MainWindow", u"Image", None))
        self.foregroundVideoButton.setText(
            QCoreApplication.translate("MainWindow", u"Video", None))
        self.foregroundLoadButton.setText(
            QCoreApplication.translate("MainWindow", u"Load", None))
        self.label_2.setText(QCoreApplication.translate(
            "MainWindow", u"Background Source", None))
        self.backgroundImageButton.setText(
            QCoreApplication.translate("MainWindow", u"Image", None))
        self.backgroundVideoButton.setText(
            QCoreApplication.translate("MainWindow", u"Video", None))
        self.backgroundLoadButton.setText(
            QCoreApplication.translate("MainWindow", u"Load", None))
        self.label_9.setText(QCoreApplication.translate(
            "MainWindow", u"Lower", None))
        self.hLowerLabel.setText(
            QCoreApplication.translate("MainWindow", u"H", None))
        self.lineEdit.setPlaceholderText("")
        self.sLowerLabel.setText(
            QCoreApplication.translate("MainWindow", u"S", None))
        self.lineEdit_2.setPlaceholderText("")
        self.vLowerLabel.setText(
            QCoreApplication.translate("MainWindow", u"V", None))
        self.lineEdit_3.setPlaceholderText("")
        self.label_10.setText(QCoreApplication.translate(
            "MainWindow", u"Upper", None))
        self.hUpperLabel.setText(
            QCoreApplication.translate("MainWindow", u"H", None))
        self.lineEdit_4.setPlaceholderText("")
        self.sUpperLabel.setText(
            QCoreApplication.translate("MainWindow", u"S", None))
        self.lineEdit_5.setPlaceholderText("")
        self.vUpperLabel.setText(
            QCoreApplication.translate("MainWindow", u"V", None))
        self.lineEdit_6.setPlaceholderText("")
        self.valueUpdateButton.setText(
            QCoreApplication.translate("MainWindow", u"Update", None))
        self.radioButton_5.setText(
            QCoreApplication.translate("MainWindow", u"RGB", None))
        self.radioButton_6.setText(
            QCoreApplication.translate("MainWindow", u"HSV", None))
    # retranslateUi


if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    MainWindow = QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
