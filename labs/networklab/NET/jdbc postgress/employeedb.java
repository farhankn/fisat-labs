import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.io.*;
public class employeedb{
    public static void main(String args[])
    {
	Connection c;
	PreparedStatement pst;
	try{
	    Class.forName("org.postgresql.Driver");
	    c=DriverManager.getConnection("jdbc:postgresql://fisatdb.fisat.edu/fisatdb2","fisat2","fisat2");
	    Statement stmt=c.createStatement();
	    ResultSet rs;
	    System.out.println("Connection Established");
	    DataInputStream din = new DataInputStream(System.in);
	    int id;
	    String name,dept;
	    float salary;			
	    int opt=1;
	    
	    while(opt!=0)
		{
		    System.out.println("MENU");
		    System.out.println("-----");
		    System.out.println("1.INSERT");
		    System.out.println("2.DISPLAY");
		    System.out.println("3.UPDATE");
		    System.out.println("4.QUIT");
		    System.out.println("Enter Choice");
		    opt=Integer.parseInt(din.readLine());
		    switch(opt)
			{
			case 1:
			    {
				// -------------------------------INSERT -------------------
				
				
				System.out.println("\nID: ");
				id=Integer.parseInt(din.readLine());
				System.out.println("\nName: ");
				name=din.readLine();
				System.out.println("\nSalary: ");
				salary=Float.parseFloat(din.readLine());
				System.out.println("\nDept: ");
				dept=din.readLine();
				pst=c.prepareStatement("INSERT INTO EMP18 VALUES(?,?,?,?);");
				pst.setInt(1,id);
				pst.setString(2,name);
				pst.setFloat(3,salary);
				pst.setString(4,dept);
				pst.executeUpdate();		
				break;
			    }
			    
			case 2:
			    {
				// ------------------------------ DISPLAY ------------------
			String sql="SELECT * from EMP18;";
			rs=stmt.executeQuery(sql);
			System.out.println("ID\tNAME\tSALARY\tDEPARTMENT");
			while(rs.next())
			    {
				System.out.println(rs.getInt("id")+"\t"+rs.getString("name")+"\t"+rs.getFloat("salary")+"\t"+rs.getString("dept")+"\n");
			    }
			break;
			    }
			case 3:
			    {
				// ------------------------------UPDATE -----------------
				
				System.out.println("\n Update: ");
				System.out.println("\nID: ");
				id=Integer.parseInt(din.readLine());
				System.out.println("\nName: ");
				name=din.readLine();
				System.out.println("\nSalary: ");
				salary=Float.valueOf(din.readLine());
				//System.out.println("type"+typeOf(salary));			
				System.out.println("\nDept: ");
				dept=din.readLine();
				pst=c.prepareStatement("UPDATE EMP18 SET id=?, name=?, salary=?, dept=?  WHERE id = ?;");
				pst.setInt(1,id);
				pst.setString(2,name);
				pst.setDouble(3,salary);
				pst.setString(4,dept);
				pst.setInt(5,id);
				pst.executeUpdate();		
				break;
			    }
			case 4:
			    {
				opt=0;
				break;
			    }			
			}		
		}
	    
	}
	catch(Exception e)
	    {
		System.out.println("Cannot Establish connection or Database Error "+e);
	    }
    }
}






			
		