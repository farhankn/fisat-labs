import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
class clientgui implements ActionListener,Runnable{
Socket c;
Frame f;
TextField t1;
Button b1;
TextArea ta;
clientgui()
{
try{
c = new Socket("localhost",10000);}
catch(Exception e)
{
System.out.println("Exception "+e);
}
f = new Frame("Client");
t1 = new TextField("Enter text here");
b1 = new Button();
b1.setLabel("Send");
ta = new TextArea();
f.add(t1);
f.add(ta);
f.setLayout(new FlowLayout());
f.setVisible(true);
f.setSize(600,250);
b1.addActionListener(this);f.add(b1);
}

public static void main(String[] args) {
clientgui c1 = new clientgui();
Thread t1 = new Thread(c1);
t1.start();
}	

public void actionPerformed(ActionEvent ae){
String s1 = " ";
try
{
do{
DataInputStream din = new DataInputStream(System.in);
s1 = t1.getText();

DataOutputStream dout = new DataOutputStream(c.getOutputStream());
dout.writeBytes(s1+"\n");
}while(!s1.equals("quit"));
}
catch(Exception e)
{
System.out.println("Exception "+e);
}
}

public void run()
{
String s2 = " ";
String output = " ";
try
{
DataInputStream dout1 = new DataInputStream(c.getInputStream());
output=dout1.readLine();
System.out.println(output);
do{ta.append(output+"\n");}
while(!output.equals("quit"));
}catch(Exception e)
{
System.out.println("Exception "+e);
}
//ta.setText(s2);

}

}


