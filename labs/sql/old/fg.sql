declare 
cursor c_dep  is select deposit24.acc_id,customer24.name,deposit24.amt
		 from deposit24,customer24 where deposit24.cus_id=customer24.cus_id;
	a_id1 deposit24 acc_id%type;
	c_name customer24 name%type;
	amount deposit24 amt%type;
	--a_id1 number(5);
	--c_name varchar(10);
	--amount number(9,2);
begin

open c_dep ;
	if c_dep%isopen then
			dbms_output.put_line('One row added to table loan.');
			fetch c_dep into a_id1,c_name,amount;
			
				dbms_output.put_line(a_id1);
			
		
	endif;
	end;
