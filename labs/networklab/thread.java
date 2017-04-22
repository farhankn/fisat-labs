import java.io.*;


class thread{
	public static void main(String[] args) 
	{
		runnable r = new runnable();
		Thread t = new Thread(r);
		runnable2 r2 = new runnable2();
		Thread t2 = new Thread(r2);
		t.start();
		t2.start();

	}
}


class runnable implements Runnable
{
	int i;
	public void run()
	{
		for (i=0;i < 6;i++ ) {
			System.out.println("Thread one "+ i);
		}
	}
}


class runnable2 implements Runnable
{
	int i;
	public void run()
	{
		for (i=5;i >= 0;i-- ) {
			System.out.println("Thread two "+ i);
		}
	}
}

/*
42813@user:/mnt/42813/networklab$ java thread 
Thread one 0
Thread two 5
Thread two 4
Thread one 1
Thread two 3
Thread one 2
Thread two 2
Thread one 3
Thread two 1
Thread one 4
Thread two 0
Thread one 5
*/