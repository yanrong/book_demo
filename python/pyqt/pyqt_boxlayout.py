#/usr/bin/env python
#boxlayout

import sys

from PyQt4.QtGui import (QWidget,QApplication,QPushButton,QHBoxLayout,QVBoxLayout)

class BoxLayout(QWidget):
	def __init__(self,parent = None):
		QWidget.__init__(self,parent)
		
		self.setWindowTitle('box layout')
		
		ok = QPushButton('OK')
		cancel = QPushButton('Cancle')
		
		hbox = QHBoxLayout()
		hbox.addStretch(1)
		hbox.addWidget(ok)
		hbox.addWidget(cancel)
		
		vbox = QVBoxLayout()
		vbox.addStretch(1)
		vbox.addLayout(hbox)
		
		self.setLayout(vbox)
		self.resize(300,150)
	#@def  how to implement user defined slot function???????
		
app = QApplication(sys.argv)
qb = BoxLayout()
qb.show()

sys.exit(app.exec_())