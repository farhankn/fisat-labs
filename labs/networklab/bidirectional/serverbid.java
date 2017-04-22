import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;
class Serverbid implements ActionListener,Runnable
{
  Frame f;
  TextField tf;
  Button b1;
  TextArea ta;
  ServerSocket ss;
  static Thread t;
  String msg;
  Socket s2;
  DataOutputStream dout;
  DataInputStream din;
	
 Serverbid()
 {
  try
   {   
  f=new Frame("server");
  tf=new TextField("enter text");
  b1=new Button("send");
  ta=new TextArea();
  f.add(tf);
  f.add(b1);
  f.add(ta);
  f.setLayout(new FlowLayout());
  f.setVisible(true);
  f.setSize(500,500);
  ss=new ServerSocket(4567);
  s2=ss.accept();
  b1.addActionListener(this);
   }
  catch(Exception e)
        {
          ;
        }
            
 }

 public void actionPerformed(ActionEvent ae)
  {  
     try{
       
         msg=tf.getText();
	//ta.setText(msg);
         dout=new DataOutputStream(s2.getOutputStream());
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
                din=new DataInputStream(s2.getInputStream()); 
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
    try{  
        Serverbid c=new Serverbid();
        t=new Thread(c);
        t.start();
       }

    catch(Exception io)
      {

      }
   }

}


       
       
       
       
      
      
     
     
  
     
