import java.io.*;
class string
{
	public static void main(String[] args) {
		String s1=" ";
		String s2=" ";
		String s3=" ";
		String s4=" ";

		try
		{
		System.out.println("Enter the string");
		DataInputStream din = new DataInputStream(System.in);
		s1 = din.readLine();
		System.out.println("Enter the string to be searched");
		DataInputStream din2 = new DataInputStream(System.in);
		s2 = din2.readLine();	
		System.out.println("Enter the string to be replaced");
		DataInputStream din3 = new DataInputStream(System.in);
		s3 = din3.readLine();	
		}
		catch(Exception IOException)
		{
			;
		}
		s4=s1.replaceAll(s2,s3);
		System.out.println(s4);

	}
}

