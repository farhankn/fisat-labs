import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;

class Client2 extends Thread implements ActionListener
{
	Frame f;
	Button btn;
	TextArea ta;
	TextField tf;
	String msg;
	DatagramSocket ds;
	Socket s;
	Thread t;
	byte b1[]=new byte[1024];

	Client2()
	{
		try
		{
			f=new Frame();
			f.setLayout(new FlowLayout());
			btn=new Button("Send");
			ta=new TextArea(50,50);
			tf=new TextField(20);
			f.setTitle("Client2");
			f.add(tf);
			f.add(btn);
			f.add(ta);
			f.setSize(500,200);
			f.setVisible(true);
			
			try
			{
				ds = new DatagramSocket(3333);
			}
			catch(Exception e)
			{}	
			t=new Thread(this);
			btn.addActionListener(this);
			t.start();
		}
		catch(Exception e)
		{}
	}
	public void actionPerformed(ActionEvent ae)
	{
		try
		{
			msg=tf.getText();
			b1=msg.getBytes();
			DatagramPacket dp1=new DatagramPacket(b1,b1.length,InetAddress.getLocalHost(),8888);
			ds.send(dp1);
		}
		catch(Exception e)
		{}
	}
	public void run()
	{
		try
		{
			do
			{
				byte b2[]=new byte[1024];	
				DatagramPacket dp2=new DatagramPacket(b2,b2.length);
				ds.receive(dp2);
				msg=new String(dp2.getData(),0,dp2.getLength());
				ta.append(msg+"\n");
			}while(!msg.equals("end"));
		}
		catch(Exception e)
		{}
	}
	public static void main(String[] args)
	{
		try
		{
			Client2 c2=new Client2();
		}
		catch(Exception e)
		{}
	}
}		
	

