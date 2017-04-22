import sys
from PyQt4 import QtGui
def myApp(QtGui.QWidget):
    def __init__(self):
        super(myApp,self).__init__()
        self.initUI()
    def initUI(self):
        self.setGeometry(0,0,700,750)
        self.ledit=QtGui.QTextEdit(self)
        self.btn=QtGui.QPushButton("Load",self)
        self.ledit.setGeometry(80,50,500,500)
        self.btn.pressed.connect(self.buttonpressed)
        self.setWindowTitle(" Code Editor ")
        self.setToolTip("main window")
        self.setToolTip(" Load ")
        #self.setGeometry(400,400,800,850)
        self.btn1=QtGui.QPushButton("SAVE",self)
        self.btn1.setGeometry(90,0,50,50)
        self.btn1.pressed.connect(self.savebuttonpressed)
        self.show()
    def buttonpressed(self):
        filename= QtGui.QFileDialog.getOpenFileName(self,'Open File','','Text(.txt *.ini *.py)')
        x=open(filename,"r").read().replace("\n","
")
        x=x.replace("\t","    ")
        x=x.replace(" "," ")
        x=x.replace("def",'def')
        x=x.replace("def",'def')
        self.ledit.setHtml(x)
        self.setWindowTitle("title")
    def savebuttonpressed(self):
        filename = QtGui.QFileDialog.getSaveFileName(self,'Open File','','Text(.txt *.ini *.py)')
        x=self.ledit.toPlainText()
        open(filename,"w").write(x)
    def closeEvent(self,event):
        reply=QtGui.QMessageBox.question(self,"My Question","Do you Want to Quit",QtGui.QMessageBox.Yes|QtGui.QMessageBox.No,QtGui.QMessageBox.No)

        if reply==QtGui.QMessageBox.No:
            event.ignore()

def main():
    app=QtGui.QApplication(sys.argv)
    wid=myApp()
    sys.exit(app.exec_())

if __name__=="__main__":
    main()
