import java.awt.*;
import java.applet.*;
/*<applet code="app" width=500 height=500>
</applet>
*/
public class app extends Applet implements Runnable
{
	Image img;
	int i=50,j=50,state;
	boolean stop_flag;
	Thread t = null;
	public void init()
	{
		img=getImage(getDocumentBase(),"flower.png");
		setBackground(Color.white);
		setForeground(Color.black);
	}
	public void start()
	{
		t=new Thread(this);
		stop_flag=false;
		t.start();
	}
	public void run()
	{
		char ch;
		try{
			for(;;)
			{
				if(i>=300&&j<300)
					j+=10;
				else if(j>=300&&i>=0)
					i=i-10;
				else if(i<300&&j==0)
					i+=10;
				else
					j-=10;
				repaint();
				Thread.sleep(300);
				if(stop_flag)
					break;
			}
		}
		catch(Exception e){}
	}
	public void stop()
	{
		stop_flag=true;
		t=null;
	}
	public void paint(Graphics g)
	{
			g.drawImage(img,i,j,this);
	}
	public static void main(String args[])
	{
		app c=new app();
	}
}
