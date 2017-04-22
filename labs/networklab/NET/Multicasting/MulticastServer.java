import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;

class MulticastServer implements ActionListener
{
	DatagramSocket ds;
	//MulticastSocket ms;
	TextField tf;
	Button b;
	String str;
	Frame f;
	DatagramPacket dp;
	MulticastServer() 
	{
		try{		
		ds=new DatagramSocket();
		f= new Frame("server");
		b=new Button("send");	
		f.setLayout(new FlowLayout());
		f.setSize(300,380);
		tf=new TextField(30);
		f.add(tf);
		f.add(b);
		b.addActionListener(this);
		f.setVisible(true);
		}
		catch(Exception e){}
		
	}
	public void actionPerformed(ActionEvent ae)
	{
		try{
			
			byte b[]=new byte[1024];
			str=tf.getText();
			tf.setText(" ");
			b=str.getBytes();
			InetAddress addr = InetAddress.getByName("224.2.2.3");
			dp=new DatagramPacket(b,b.length,addr,8888);
			System.out.println(dp);
			ds.send(dp);
			if(str.equals("quit"))
			{
				System.exit(0);
			}
		}
		catch(Exception e)
		{System.out.println("Excep");}	
	}

public static void main(String args[]) 
{

MulticastServer bs=new MulticastServer();
	
	
}

}

		
