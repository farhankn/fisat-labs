import java.io.*;
import java.net.*;

class client
{
	public static void main(String[] args) 
	{
	String s1 = " ";
	try
		{
		Socket c = new Socket("localhost",10000);
		do{
		System.out.println("Enter the string");
		DataInputStream din = new DataInputStream(System.in);
		s1 = din.readLine();
		DataOutputStream dout = new DataOutputStream(c.getOutputStream());
		dout.writeBytes(s1+"\n");
		}while(!s1.equals("quit"));
	}
	catch(Exception e)
		{
			System.out.println("Exception "+e);
		}
	}
}
