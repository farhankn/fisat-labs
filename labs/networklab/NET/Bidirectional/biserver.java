import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;

class biserver implements ActionListener,Runnable
{
    Frame f;
    TextField tf;
    TextArea ta;
    DataOutputStream dout;
    DataInputStream din;
    Socket c2 ;
    Button b;
    String str = " ";
    ServerSocket ss;
    biserver()
    {
	try
	    {

		f = new Frame("Server");
		tf = new TextField(20);
		ta = new TextArea();
		b = new Button("Send");
		f.setLayout(new FlowLayout());
		f.setVisible(true);
		f.setSize(500,500);
		f.add(tf);
		f.add(b);
		f.add(ta);
		b.addActionListener(this);
		ss = new ServerSocket(2222);
		c2 = ss.accept();

	    }
	catch(Exception e)
	    {}

    }
    public void actionPerformed(ActionEvent ae)
    {
	try 
	    {
		str = tf.getText();
		dout = new DataOutputStream(c2.getOutputStream());
		dout.writeBytes(str+ '\n');
	    }
	catch(Exception e)
	    {}
    }

    public void run()
    {
	try 
	    {
		String in;
		do
		    {
			din = new DataInputStream(c2.getInputStream());
			in = din.readLine();
			ta.append(in+"\n");
		    }while(!in.equals("quit"));
	    }
	catch(Exception e)
	    {}
    }
    public static void main(String[] args) {
	try 
	    {
		biserver bs = new biserver();
		Thread t = new Thread(bs);
		t.start();
	    }
	catch(Exception io)
	    {}
    }


}
