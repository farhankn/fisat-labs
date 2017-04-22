import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
class publicclient extends Thread implements ActionListener
{
	Frame f;
	Button btn;
	TextArea ta;
	TextField tf;
	String msg;
	Socket s;
	Thread t;
	publicclient()
	{
		try
		{
			f=new Frame();
			s=new Socket("localhost",8844);
			f.setLayout(new FlowLayout());
			btn=new Button("send");
			msg=new String("hello");
			ta=new TextArea(20,20);
			tf= new TextField(20);
			f.add(tf);
			f.add(btn);
			f.add(ta);
			f.setVisible(true);
			t= new Thread(this);
			btn.addActionListener(this);
			t.start();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
		public void actionPerformed(ActionEvent ae)
		{
			try
			{
				msg=tf.getText();
				DataOutputStream dout=new DataOutputStream(s.getOutputStream());
				dout.writeBytes(msg+"\n");

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
					DataInputStream din=new DataInputStream(s.getInputStream());
					msg=din.readLine();
					ta.append(msg+"\n");
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
				publicclient a=new publicclient();
			}

			catch(Exception e)
			{
				System.out.println(e);
			}
		}
}
					
