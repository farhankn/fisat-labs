import java.io.*;

class Complex
{
	int real;
	int im;
	void read()
	{
		try
		{		
			System.out.print("Real part: ");
			DataInputStream din1=new DataInputStream(System.in);
			int k1=Integer.parseInt(din1.readLine());
			real=k1;
               	 	System.out.print("Imaginary part: ");
			DataInputStream din2=new DataInputStream(System.in);
			int k2=Integer.parseInt(din2.readLine());
			im=k2;
		}
		catch(IOException io)
		{}
			
	}
	Complex add(Complex a,Complex b)
	{
		Complex temp=new Complex();
		temp.real=a.real+b.real;
		temp.im=a.im+b.im;
		return temp;
	}
}

class Complexmain
{
	public static void main(String[] args)
	{
		Complex c1=new Complex();
		Complex c2=new Complex();
		Complex c3=new Complex();
		c1.read();
		c2.read();
		c3=c3.add(c1,c2);
		System.out.println("The sum of " + c1.real + "+i" + c1.im + " and " + c2.real + "+i" + c2.im + " is: " + c3.real + "+i" + c3.im);
	}
}


