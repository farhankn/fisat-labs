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
		// if(s1.indexOf(s2)==-1)
		// 	System.out.println("Substring not found");
		// else
		// 	System.out.println("Substring found at location "+(s1.indexOf(s2)+1));
		s4=s1.replaceAll(s2,s3);
		System.out.println(s4);

	}
}

/*
42813@user:/mnt/42813/networklab$ java string 
Enter the string
Hello World
Enter the string to be searched
World
Enter the string to be replaced
Farhan
Hello Farhan
*/