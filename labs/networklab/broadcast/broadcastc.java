//bideirectional client

import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;

class broadcastc implements ActionListener,Runnable{
 Frame f;
 TextField tf;
 TextArea ta;
 DataOutputStream dout;
 DataInputStream din;
 Socket s ;
 //Button b;
 String str = " ";

broadcastc()
{
try
{
s = new Socket("localhost",4321);

f = new Frame();
//tf = new TextField(20);
ta = new TextArea();
//b = new Button("Send");
f.setLayout(new FlowLayout());
f.setVisible(true);
f.setSize(500,500);
//f.add(tf);
//f.add(b);
f.add(ta);
//b.addActionListener(this);
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
dout = new DataOutputStream(s.getOutputStream());
dout.writeBytes(str+ '\n');
}
catch(Exception e)
{
System.out.println("Exception");
}
}
public void run()
{
try {
String in;
do {
din = new DataInputStream(s.getInputStream());
in = din.readLine();
ta.append(in+"\n");
}while(!in.equals("quit"));
}
catch(Exception e)
{
System.out.println("Exception");
}

}

public static void main(String[] args) {
try {
broadcastc cli = new broadcastc();
Thread t = new Thread(cli);
t.start();
}

catch(Exception io) {
System.out.println("Exception there");
}
}
}



























