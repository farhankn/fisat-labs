import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;


class Clientbid implements ActionListener,Runnable
{
 Frame f;
 TextField tf;
 Button b1;
 TextArea ta;
 static Thread t;
 String msg;
 Socket c1;
 DataInputStream din;
 DataOutputStream dout;
 Clientbid()
 {
   try 
    {  
     f=new Frame("client");
     tf=new TextField("enter text");
     b1=new Button();
     b1.setLabel("send");
     ta=new TextArea();
     f.add(tf);
     f.add(b1);
     f.add(ta);
     f.setLayout(new FlowLayout());
     f.setVisible(true);
     f.setSize(500,500);
     b1.addActionListener(this);
     c1= new Socket("localhost",4567);
     
    }
 catch(Exception e) 
    {
    }

 }
 
 public void actionPerformed(ActionEvent ae)
  {  
     try{
       
         msg=tf.getText();
         dout=new DataOutputStream(c1.getOutputStream());
         dout.writeBytes(msg+"\n");
	if(msg.equals("quit")){System.exit(0);}
        }
     catch(Exception IOException)
        {
          ;
        }
  } 

 
public void run()
{
 try{
       String m;
        
           do
              {
                din=new DataInputStream(c1.getInputStream()); 
                m=din.readLine();
                ta.append(m+"\n");
              }while(!m.equals("quit"));
        
    }
 catch(Exception e)
        {
          ;
        }
            
}         
  
public static void main(String args[])
{
  
  Clientbid c2=new Clientbid();
  t=new Thread(c2);
  t.start();
  

}
}
