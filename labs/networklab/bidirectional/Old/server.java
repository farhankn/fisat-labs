import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;


class server implements ActionListener,Runnable
{
			Frame f;
			TextField tf;
			static Thread t;
			TextArea ta;
			Button b;
			ServerSocket ss;
			Socket c;
			DataOutputStream dout;
			String msg;
			DataInputStream din;
			String m;
			Socket s3[]=new Socket[10];
			int count=0,i=0,j;
	server()
	{
		try{
			f = new Frame("Server");
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
			ss=new ServerSocket(4567);
			while(true)
			{
			s3[i]=ss.accept();
			i++;
			//count++;
			}
			
		}
		catch(Exception e)
		{}
	}
	public void actionPerformed(ActionEvent ae)
	{
		try{
			for(j=0;j<i;j++)
			{
			msg=tf.getText();	
			dout = new DataOutputStream(s3[j].getOutputStream());
			dout.writeBytes(msg+"\n");
			}
		
		  }
		catch(Exception e)
		{}
	}
	public void run()
	{
	try
		{
		if(Thread.currentThread()==t)
		{
			do{
				
				
				din = new DataInputStream(s3[j].getInputStream());
				m = din.readLine();
				ta.append(m+"\n");
				
							
			}while(!m.equals("quit"));	
			
		}
		}catch(Exception e)
		{}
	}
	public static void main(String args[])
	{
		server s1=new server();
		t=new Thread(s1);
		t.start();
	}

}
			

	
