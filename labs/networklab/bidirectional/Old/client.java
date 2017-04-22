import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;


class client implements ActionListener,Runnable
{
    Frame f;
    TextField tf;
    static Thread t1;
    TextArea ta;
    Button b;
    Socket c1;
    ServerSocket s;
    DataOutputStream dout;
    String msg;
    DataInputStream din;
    String m;
    client()
    {
	try{
	    f = new Frame("Client");
	    tf = new TextField(10);
	    b = new Button("send");
	    ta = new TextArea(20,20);
	    f.setLayout(new FlowLayout());
	    f.setSize(500,500);
	    f.setVisible(true);
	    f.add(tf);
	    f.add(b);
	    f.add(ta);
	    b.addActionListener(this);
	    c1=new Socket("localhost",4567);
	}
	catch(Exception e)
	    {}
    }
    public void actionPerformed(ActionEvent ae)
    {
	try{
	    msg=tf.getText();
	    dout = new DataOutputStream(c1.getOutputStream());
	    dout.writeBytes(msg+"\n");
	    
	}
		catch(Exception e)
		    {}
    }
    public void run()
    {
	try
	    {
		if(Thread.currentThread()==t1)
		    {
			do{
			    
			    din = new DataInputStream(c1.getInputStream());
			    m = din.readLine();
			    ta.append(m+"\n");
			}while(!m.equals("quit"));	
			
		    }
	    }catch(Exception e)
	    {}
    }
    public static void main(String args[])
    {
	client c2=new client();
	t1=new Thread(c2);
	t1.start();
    }
    
}


	
