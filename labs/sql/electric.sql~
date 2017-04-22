--Electricity bill
declare 
	cus_no varchar(5);
	c_no1 varchar(5);
	unit number(3);
	pres number(3);
	prev number(3);
	cost number(5);
	
begin
	cus_no:='&cus_no';
	
		select present into pres from elec_bill18 where c_no=cus_no;
		select prevs into prev from elec_bill18 where c_no=cus_no;
			unit:=prev-pres;
		if unit<=50 then
			cost:=unit*5;
		elsif unit>50 and unit<=100 then
			cost:=(unit-50)*10+250;
		elsif unit>100 and unit<=200 then
			cost:=(unit-100)*15+750;
		else
			cost:=(unit-200)*20+2250;
		end if;
		dbms_output.put_line('Previous Reading: '||prev);
		dbms_output.put_line('Present Reading: '||pres);
		dbms_output.put_line('Cost : '||cost);
	
	exception
		when no_data_found then
			dbms_output.put_line('Invalid customer number.');
end;

