--Customer account 2
declare 
	ramt number(9,2);
	a_id number(5);
	tax number(9,2);
	c_id  varchar(5);
	d_amt number(9,2);
	l_amt number(9,2);	
	cursor c_dep  is select deposit24.acc_id,customer24.name,deposit24.amt
		 from deposit24,customer24 where deposit24.cus_id=customer24.cus_id;
	
	c_name  customer24.name%type;
begin
	c_id:='&c_id';
	select amt into d_amt from deposit24 where cus_id=c_id;
	select name into c_name from customer24 where cus_id=c_id;
	ramt:=&ramt;
	if ramt>(d_amt-500) then
		dbms_output.put_line('Balance amount in account: '||d_amt);
		dbms_output.put_line('Withdrawal not possible.Take loan.');
		l_amt:=ramt-d_amt+500;
		update deposit24 set amt=500 where cus_id=c_id;
		select acc_id into a_id from deposit24 where cus_id=c_id;
		insert into loan24 values(c_id,a_id,l_amt);
		dbms_output.put_line('One row added to table loan.');
	else
		update deposit24 set amt=amt-ramt where cus_id=c_id;
	end if;
	for d in c_dep
	loop
		tax:=(10/100)*d.amt;
		dbms_output.put_line('Account id: '||d.acc_id||' Customer name: '||d.name||' Tax: '||tax );
				 
	end loop;
	exception
		when no_data_found then
			dbms_output.put_line('Invalid customer number.');	
	commit;		
end;
		
/*  SQL> @pl_loan.sql;
 43  /
Enter value for c_id: C001
old  13: 	c_id:='&c_id';
new  13: 	c_id:='C001';
Enter value for ramt: 16400
old  16: 	ramt:=&ramt;
new  16: 	ramt:=16400;
Balance amount in account: 11000
Withdrawal not possible.Take loan.
One row added to table loan.
Account id: 1234 Customer name: Radha Tax: 50
Account id: 2345 Customer name: Ramu Tax: 50
Account id: 3456 Customer name: Ravi Tax: 50

PL/SQL procedure successfully completed.

Commit complete.  */	
	

