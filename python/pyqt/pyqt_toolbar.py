#/usr/bin/env python
#toolbar for pyqt

import sys
from PyQt4 import QtGui,QtCore

class MainWindow(QtGui.QMainWindow):
	def __init__(self,parent = None):
		QtGui.QMainWindow.__init__(self,parent)
		
		self.resize(250,150)
		self.setWindowTitle('toolbar')
		
		self.exit = QtGui.QAction(QtGui.QIcon(''),\
			'Eixt',self)
		self.exit.setShortcut('Ctrl+Q')
		self.connect(self.exit,QtCore.SIGNAL('triggered()'),\
			QtGui.qApp,QtCore.SLOT('quit()'))
		self.toolbar = self.addToolBar('Exit')
		self.toolbar.addAction(self.exit)

app = QtGui.QApplication(sys.argv)
main = MainWindow()
main.show()
sys.exit(app.exec_())