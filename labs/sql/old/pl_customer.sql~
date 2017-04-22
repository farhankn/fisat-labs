--Customer account
declare 
	cursor c_dep  is select deposit24.acc_id,customer24.name,deposit24.amt
		 from deposit24,customer24 where deposit24.cus_id=customer24.cus_id;
	a_id1  deposit24.acc_id%type;
	c_name  customer24.name%type;
	amount deposit24.amt%type;
	ramt number(9,2);
	a_id number(5);
	tax number(9,2);
	c_id  varchar(5);
	d_amt number(9,2);
	l_amt number(9,2);
	
begin
	c_id:='&c_id';
	ramt:=&ramt;
	select amt into d_amt from deposit24 where cus_id=c_id;
	dbms_output.put_line(ramt);
	if ramt>(d_amt-500) then
		l_amt:=ramt-d_amt+500;
		update deposit24 set amt=500 where cus_id_id=c_id;
		select acc_id into a_id from deposit24 where cus_id=c_id;
		insert into loan24 values(c_id,a_id,l_amt);
		dbms_output.put_line('One row added to table loan.');
	else
		update deposit24 set amt=amt-ramt where cus_id_id=c_id;
	endif;
	open c_dep ;
	if c_dep%isopen then
		while(c_%found)
		loop
		fetch c_dep into a_id1,c_name,amount;
			if c_dep%found then
				tax:=amount+.01*amount;
				dbms_output.put_line('Account id: '||a_id||' Customer name: '||c_name||' Tax: '||tax );
			endif;	 
		end loop;	
	endif;
	commit;	
	close c_dep;
end;
		
	
	
