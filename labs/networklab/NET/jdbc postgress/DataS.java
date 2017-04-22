import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.io.*;
public class Data{
	public static void main(String args[])
	{
		Connection c;
		PreparedStatement pst;
		try{
			Class.forName("org.postgresql.Driver");
			c=DriverManager.getConnection("jdbc:postgresql://fisatdb.fisat.edu/fisatdb1","fisat1","fisat1");
			Statement stmt=c.createStatement();
			ResultSet rs;
			
			int opt=1;
			
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			while(opt!=0)
			{
				System.out.println("MENU");
				System.out.println("-----");
				System.out.println("1.DISPLAY");
				System.out.println("2.INSERT");
				System.out.println("3.UPDATE");
				System.out.println("4.HIGHEST SALARY");
				System.out.println("5.QUIT");
				System.out.println("Enter Choice");
				opt=Integer.parseInt(br.readLine());
				switch(opt)
				{
					case 1:
					{
						String sql="SELECT * from emp111;";
						rs=stmt.executeQuery(sql);
						System.out.println("ID\tNAME\tSALARY\tDEPARTMENT");
						while(rs.next())
						{
			System.out.println(rs.getInt("id")+"\t"+rs.getString("name")+"\t"+rs.getFloat("salary")+"\t"+rs.getString("dept")+"\n");
						}
					break;
					}
					case 2:
					{
						int id;
						String name,dept;
						float salary;
						System.out.println("\nID: ");
						id=Integer.parseInt(br.readLine());
						System.out.println("\nName: ");
						name=br.readLine();
						System.out.println("\nSalary: ");
						salary=Float.parseFloat(br.readLine());
						System.out.println("\nDept: ");
						dept=br.readLine();
						pst=c.prepareStatement("INSERT INTO emp111 VALUES(?,?,?,?);");
						pst.setInt(1,id);
						pst.setString(2,name);
						pst.setFloat(3,salary);
						pst.setString(4,dept);
						pst.executeUpdate();
					
						break;
					}
					case 3:
					{
						String name;
						float salary;
						System.out.println("\nName: ");
						name=br.readLine();
					
						System.out.println("\nSalary: ");
						salary=Float.parseFloat(br.readLine());
						
						
						pst=c.prepareStatement("UPDATE emp111 SET salary=? WHERE name=?;");
						pst.setFloat(1,salary);
						pst.setString(2,name);
						pst.executeUpdate();
						
						
						break;
					}
					case 4:
					{
						String sql="SELECT name from emp111 WHERE salary=(SELECT MAX(salary) from emp111);";
						ResultSet hs=stmt.executeQuery(sql);
						while(hs.next())
						{
							System.out.println("Employee with Highest Salary");
							System.out.println(hs.getString("name"));
						}
						break;
					}
					case 5:
						{
							opt=0;
							break;
						}
				}
			}
		}
			catch(Exception e){}
}	}
						
				

