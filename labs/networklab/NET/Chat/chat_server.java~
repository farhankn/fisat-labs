import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;

class CentralServer extends Thread
{
	Frame f;
	TextArea ta;
	DatagramSocket ds;
	Socket s;
	Thread t;
	int port;
	
	CentralServer()
	{
		try
		{
			f=new Frame();
			f.setLayout(new FlowLayout());
			ta=new TextArea(15,25);
			f.setTitle("Server");
			f.setSize(300,300);
			f.setVisible(true);
			
			try
			{
				ds = new DatagramSocket(8888);
			}
			catch(Exception e)
			{}	
			
		}
		catch(Exception e)
		{}
	}
	public void run()
	{
		try
		{
			String msg;
			do
			{       
				byte b[]=new byte[1024];
				DatagramPacket dp1=new DatagramPacket(b,b.length);
				ds.receive(dp1);
				msg=new String(dp1.getData(),0,dp1.getLength());
				if(dp1.getPort()==1111)
					port=3333;
				else
					port=1111;
				b=msg.getBytes();
				DatagramPacket dp2=new DatagramPacket(b,b.length,InetAddress.getLocalHost(),port);
				ds.send(dp2);
			}while(!msg.equals("end"));
		}
		catch(Exception e)
		{}
	}
	public static void main(String[] args)
	{
		try
		{
			CentralServer cs=new CentralServer();
			cs.start();
		}
		catch(Exception e)
		{}
	}
}		
	

