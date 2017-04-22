import java.io.*;

class main
{
	public static void main(String args[])
	{
		complex c1 = new complex();
		c1.read();
		complex c2 = new complex();
		c2.read();
		complex c3 = new complex();
		c3 = c3.addComplex(c1,c2);
		System.out.println("sum is "+c3.ireal+" +"+c3.imaginary+"i");
		//System.out.println("Imaginary Part "+c3.imaginary);
		

	}
}

class complex
{
	int ireal,imaginary;
	complex()
	{
		ireal = 0;
		imaginary = 0;
	}

	void read()
	{
		try
		{
			DataInputStream din = new DataInputStream(System.in);
			System.out.println("Enter the Real");
			ireal = Integer.parseInt(din.readLine());
		}
		catch(Exception IOException)
		{
			;
		}
		try
		{
			DataInputStream dis = new DataInputStream(System.in);
			System.out.println("Enter the Imaginary Part");
			imaginary = Integer.parseInt(dis.readLine());
		}
		catch(Exception IOException)
		{
			;
		}
		
	}
	complex addComplex(complex c1,complex c2)
	{
		complex ctemp = new complex();
		ctemp.ireal = c1.ireal + c2.ireal;
		ctemp.imaginary = c1.imaginary + c2.imaginary;
		return ctemp;
	}
}

/*
42813@user:/mnt/42813/networklab$ java main 
Enter the Real
3
Enter the Imaginary Part
2
Enter the Real
5
Enter the Imaginary Part
2
sum is 8 +4i
*/