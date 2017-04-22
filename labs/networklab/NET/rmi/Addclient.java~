import java.rmi.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
public class Addclient implements ActionListener
{
	Frame f;
	Button b1;
	Button b2;
	Button b3;
	Button b4;
	TextField t1;
	TextField t2;
	TextField t3;
	TextField t4;
	int e;
	AddServerIntf in;
	String url;
	Addclient()
	{
		try
		{
			f=new Frame();
			f.setLayout(new FlowLayout());
			b1=new Button("ADD");
			t1=new TextField(20);
			b2=new Button("SUB");
			t2=new TextField(20);			
			b3=new Button("MUL");
			t3=new TextField(20);
			b4=new Button("DIV");
			t4=new TextField(20);
			f.setTitle("Calculator");
			f.add(t1);
			f.add(t2);
			f.add(t3);
			f.add(b1);
			f.add(b2);
			f.add(b3);
			f.add(b4);
			b1.addActionListener(this);
			b2.addActionListener(this);
			b3.addActionListener(this);
			b4.addActionListener(this);
			f.setSize(500,200);
			f.setVisible(true);
			url="rmi://localhost/Addserver";
			in=(AddServerIntf)Naming.lookup(url);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	public void actionPerformed(ActionEvent ae)
	{
		try{
			int c=Integer.parseInt(t1.getText());
			int d=Integer.parseInt(t2.getText());
			if(ae.getSource()==b1)
			{
				e=in.add(c,d);
				t3.setText(String.valueOf(e));
			}
			else if(ae.getSource()==b2)
			{
				e=in.sub(c,d);
				t3.setText(String.valueOf(e));
			}
			else if(ae.getSource()==b3)
			{
				e=in.mul(c,d);
				t3.setText(String.valueOf(e));
			}
			else if(ae.getSource()==b4)
			{
				e=in.div(c,d);
				t3.setText(String.valueOf(e));
			}
		}
		catch(Exception e)
		{	
			System.out.println(e);
		}
	}
	public static void main(String rgs[])
	{
		try{
			Addclient c= new Addclient();
			}
		catch(Exception e)
		{	
			System.out.println(e);
		}
	}
}
		
