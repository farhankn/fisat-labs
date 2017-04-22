declare

 name varchar2(15);
 address varchar2(15);
 bid branch.branch_id%type;
 cnname varchar2(15);
 present number(1);
 bal ac.bal%type;


begin
	cnname:='&cnname';
	bid:='&bid';
	bal:=&bal;
	
		insert into ac values (cnname,seq.nextval,bal,bid) ;
		select address into address from cust_bank where cname=cnname;
		

exception
		when no_data_found then
		address:='&address';
		insert into ac values(cnname,seq.nextval,bal,bid); 
		insert into cust_bank values (cnname,address);

end;
