import java.io.*;

class replace
{
	public static void main(String[] args)
	{
		String s1="NULL",s2="NULL",s3="NULL",s4="NULL";
		try
		{
			System.out.print("Enter the string: ");
			BufferedReader br1=new BufferedReader(new InputStreamReader(System.in));
			s1=br1.readLine();
			System.out.print("Enter the substring: ");
			BufferedReader br2=new BufferedReader(new InputStreamReader(System.in));
			s2=br2.readLine();
			System.out.print("Enter the replace string: ");
			BufferedReader br3=new BufferedReader(new InputStreamReader(System.in));
			s3=br3.readLine();
		}
		catch(IOException io)
		{}
		s4=s1.replaceAll(s2,s3);
		System.out.println("The final string is : "+s4);
	}
}


