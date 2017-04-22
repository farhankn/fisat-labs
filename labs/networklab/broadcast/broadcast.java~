//bidirectional server
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;

class broadcast implements ActionListener {

Frame f;
int i=0,j=0;
TextField tf;
TextArea ta;
DataOutputStream dout;
DataInputStream din;
Socket c2[]=new Socket[20];
Button b;
String str = " ";
ServerSocket ss;

 broadcast()
{
try
{

f =  new Frame();
tf = new TextField(20);
ta = new TextArea();
b =  new Button("Send");
f.setLayout(new FlowLayout());
f.setVisible(true);
f.setSize(500,500);
f.add(tf);
f.add(b);
f.add(ta);
b.addActionListener(this);
ss = new ServerSocket(4321);
while(true)
{
c2[i] = ss.accept();
i++;
}
}
catch(Exception e)
{
System.out.println("Exception");
}

}
public void actionPerformed(ActionEvent ae)
{
try {
str = tf.getText();
for(j=0;j<i;j++)
{
dout = new DataOutputStream(c2[j].getOutputStream());
dout.writeBytes(str+ '\n');
}
}
catch(Exception e)
{
System.out.println("Exception");
}
}

/*public void run()
{
try {
String in;
do {

din = new DataInputStream(c2.getInputStream());
in = din.readLine();
ta.append(in+"\n");
}while(!in.equals("quit"));
}
catch(Exception e)
{
System.out.println("Exception");
}
}*/

public static void main(String[] args) {
try {
broadcast serv = new broadcast();
//Thread t = new Thread(serv);
//t.start();
}
catch(Exception io) {
System.out.println("Exception");
}
}


}
