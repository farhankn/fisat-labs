import java.io.*;
import java.net.*;

class uniserver
{
	public static void main(String[] args)
	{
		try
		{
			String s;
			ServerSocket ss=new ServerSocket(3333);
			Socket c=ss.accept();
			DataInputStream din=new DataInputStream(c.getInputStream());
			do
			{
				s=din.readLine();
				
				System.out.println(s);
			}while(!s.equals("quit"));
		}
		catch(Exception e)
		{}
	}
}

