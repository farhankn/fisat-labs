import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;

class MulticastClient implements Runnable
{
	static Thread t1;
	MulticastSocket ms;
	DatagramPacket dp;
	TextArea ta;
	Frame f;
	byte b1[]=new byte[10240];
	MulticastClient() 
	{
		try{		
		ms=new MulticastSocket(8888);
		f= new Frame("client");	
		f.setLayout(new FlowLayout());
		f.setSize(300,380);
		ta=new TextArea(10,20);
		f.add(ta);
		f.setVisible(true);
		InetAddress addr=InetAddress.getByName("224.2.2.3");
		ms.joinGroup(addr);
		}
		catch(Exception e){}
		
	}
	public void run()
	{
		try{
			
			
			if(Thread.currentThread()==t1)
			{
				do
				{
					System.out.println("inside run");
					dp=new DatagramPacket(b1,b1.length);
					ms.receive(dp);
					System.out.println(dp);	
					String s=new String(dp.getData(),0,dp.getLength());
					System.out.println(s);
					if(s.equals("quit"))
					{
					System.exit(0);
					}
					ta.append(s);
				}while(true);
			}
		}
		catch(Exception e)
		{}	
	}

public static void main(String args[]) 
{
	try{
		MulticastClient bc=new MulticastClient();
		t1=new Thread(bc);
		t1.start();
	}
	catch(Exception e){}
}

}

		
