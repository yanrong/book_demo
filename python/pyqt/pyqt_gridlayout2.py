#!/usr/bin/env python
#grid layout 2

import sys

from PyQt4.QtGui import (QGridLayout,QApplication,QWidget,QLineEdit,QLabel)

class GridLayout(QWidget):
	def __init__(self,parent = None):
		QWidget.__init__(self)
		
		self.setWindowTitle('grid layout')
		
		title = QLabel('Title')
		author = QLabel('Author')
		review = QLabel('Review')
		
		titleEdit = QLineEdit()
		authorEdit = QLineEdit()
		reviewEdit = QLineEdit()
		
		grid = QGridLayout()
		grid.setSpacing(10)
		
		grid.addWidget(title,1,0)
		grid.addWidget(titleEdit,1,1)
		
		grid.addWidget(author,2,0)
		grid.addWidget(authorEdit,2,1)
		
		grid.addWidget(review,3,0)
		grid.addWidget(reviewEdit,3,1,5,1)
		
		self.setLayout(grid)
		self.resize(350,300)
		
		
app = QApplication(sys.argv)
qb = GridLayout()
qb.show()

sys.exit(app.exec_())
