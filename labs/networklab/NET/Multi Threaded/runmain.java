import java.io.*;

class run1 extends Thread
{
	{
		start();
	}
	public void run()
	{
		int i;
		for(i=1;i<=5;i++)
			System.out.println(getName()+" " + i);
	}
}
class run2 extends Thread
{
	{
		start();
	}
	public void run()
	{
		int i;
		for(i=5;i>=1;i--)
			System.out.println(getName()+" " + i);
	}
}
class runmain
{
	public static void main(String[] args)
	{
		run1 r1=new run1();
		run2 r2=new run2();
	}
}



