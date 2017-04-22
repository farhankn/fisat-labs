--Customer account 2
declare 
	ramt number(9,2);
	a_id varchar(5);
	tax number(9,2);
	c_id  varchar(5);
	d_amt number(9,2);
	l_amt number(9,2);	
	cursor c_dep  is select deposit18.acc_id,customer18.name,deposit18.amt
		 from deposit18,customer18 where deposit18.cus_id=customer18.cus_id;
	c_name  customer18.name%type;
begin
	c_id:='&c_id';
	ramt:=&ramt;
	select amt into d_amt from deposit18 where cus_id=c_id;
	select name into c_name from customer18 where cus_id=c_id;

	if ramt>(d_amt-500) then
		dbms_output.put_line('Not enough Money, Lending money as Load');
		l_amt:=ramt-d_amt+500;
		update deposit18 set amt=500 where cus_id=c_id;
		select acc_id into a_id from deposit18 where cus_id=c_id;
		insert into loan18 values(c_id,a_id,l_amt);
		dbms_output.put_line('loan Updated');
	else
		update deposit18 set amt=amt-ramt where cus_id=c_id;
	end if;
	
	for d in c_dep
	loop
		tax:=d.amt+.01*d.amt;
		dbms_output.put_line('Account id: '||d.acc_id||' Customer name: '||d.name||' Tax: '||tax );
				 
	end loop;	
	
	commit;	
end;
