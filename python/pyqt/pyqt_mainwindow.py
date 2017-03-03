#/usr/bin/env python2
#mainwindow

import sys

from PyQt4.QtGui import *
from PyQt4.QtCore import SIGNAL,SLOT

class MainWindow(QMainWindow):
	def __init__(self,parent = None):
		QMainWindow.__init__(self,parent)
		self.resize(350,250)
		self.setWindowTitle('mainwindow')
		
		#create textedit as central widget
		textEdit = QTextEdit()
		self.setCentralWidget(textEdit)
		
		#create a QAction for adding menu list
		#set it's short cut keyboard combination
		exit = QAction(QIcon(''),'Exit',self)
		exit.setShortcut('Ctrl+W')
		
		#set mainwindow's status tips ,connect correspondant signas(notify) to slot(action)
		self.setStatusTip('Exit Application')
		self.connect(exit,SIGNAL('triggered()'),qApp,SLOT('quit()'))
		
		self.statusBar()
		
		#get a global menubar for add menu
		menubar = self.menuBar()
		file = menubar.addMenu('&File')
		file.addAction(exit)
		
		#create a toolbar for apps
		toolbar = self.addToolBar('Exit')
		toolbar.addAction(exit)

#start application
app = QApplication(sys.argv)
main = MainWindow()
#show our defined UI
main.show()

sys.exit(app.exec_())