import sys
from PyQt4 import QtGui

def main():
app=QtGui.QApplication(sys.argv)
myWidget=QtGui.QWidget()
myWidget.show()
myWidget.setWindowTitle(" HELLO WORLD ")
sys.exit(app.exec_())

if __name__=="__main__":
main()
