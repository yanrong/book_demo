#!/usr/bin/env python
#menubar

import sys
from PyQt4 import QtGui, QtCore

class MainWindow(QtGui.QMainWindow):
	def __init__(self,parent = None):
		QtGui.QMainWindow.__init__(self,parent)
		
		self.resize(250,150)
		self.setWindowTitle('menubar')
		
		exit = QtGui.QAction(QtGui.QIcon(),'Exit',self)
		exit.setShortcut('Ctrl+Q')
		exit.setStatusTip('Exit Application')
		exit.connect(exit,QtCore.SIGNAL('triggered()'), \
			QtGui.qApp,QtCore.SLOT('quit()'))
		
		self.statusBar()
		
		menubar = self.menuBar()
		file = menubar.addMenu('&File')
		file.addAction(exit)

app = QtGui.QApplication(sys.argv)
main = MainWindow()
main.show()
sys.exit(app.exec_())