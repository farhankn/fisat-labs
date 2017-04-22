import java.io.*;
import java.net.*;
class server
{
	public static void main(String[] args) {		
		String output=" ";
		try
		{
       			ServerSocket s = new ServerSocket(10000);
			Socket s1=s.accept();
           	do{
			
			DataInputStream dout = new DataInputStream(s1.getInputStream());
			output=dout.readLine();
			if(output.equals("quit"))
				System.exit(0);
			else
          		  System.out.println(output);
            }while(!output.equals("quit"));
		}
		catch(Exception e)
		{
			System.out.println("Exception "+e);
		}
		
		
		System.out.println(output);


	}
}
