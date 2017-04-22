import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
class publicserver implements Runnable
{
	Thread t[]=new Thread[50];
	int k;
	Frame f;
	DataInputStream din;
	DataOutputStream dout;
	String msg;
	static int i=0;
	ServerSocket ss;
	Socket s[]=new Socket[10];
	publicserver()
	{
		try
		{
			ss=new ServerSocket(8844);
			while(true)
			{
				s[i]=ss.accept();
				t[i]=new Thread(this);
 				t[i].start();
				i++;
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	public void run()
	{
		try
		{
			do
			{
				for(int k=0;k<i;k++)
				{
					if(Thread.currentThread()==t[k])
					{
						DataInputStream din= new DataInputStream(s[k].getInputStream());
						msg=din.readLine();
						for(int j=0;j<i;j++)
						{
							if(k!=j)
							{
								dout= new DataOutputStream(s[j].getOutputStream());
								dout.writeBytes(msg+"\n");
							}
						}
					}
				}
			}
			while(!msg.equals("end"));
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	public static void main(String args[])
	{
		try
		{
			publicserver a= new publicserver();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
