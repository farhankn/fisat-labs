import java.awt.*;
import java.net.*;
import java.io.*;
import java.awt.event.*;
class brclient implements ActionListener,Runnable
{
    Frame f;
    TextField tf;
    static Thread t;
    Button b;
    DataOutputStream dout;
    TextArea ta;
    DataInputStream din;
    Socket c;
    String msg;
    String m;
	
    brclient()
    {
	try
	{
	    f=new Frame("Client");
	    tf=new TextField(20);
	    b=new Button("send");
	    ta=new TextArea();
	    f.setLayout(new FlowLayout());
	    f.setVisible(true);
	    f.setSize(500,500);
	    f.add(ta);
	    b.addActionListener(this);
	    c=new Socket("localhost",2222);
	}
	catch(Exception e){}
    }
    public void actionPerformed(ActionEvent ae)
    {}
    public void run()
    {
	try
	{
	    do
	    {
		din=new DataInputStream(c.getInputStream());
		m=din.readLine();
		ta.append(m+"\n");
	    }while(!m.equals("quit"));
	}
	catch(Exception e){}
    }
    public static void main(String[] args)
    {
	try
	{
	    brclient s1=new brclient();
	    t=new Thread(s1);
	    t.start();
	}
	catch(Exception e){}
    }
}
