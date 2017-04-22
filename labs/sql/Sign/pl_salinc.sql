--Main program to increment the salary of an employee

declare
	sal number(9,2);
	enum varchar(5);
	new_salary number(9,2);
	ndate date;
	incr_amt number(9,2);
begin
	enum:='&enum';
	incr_amt:=&incr_amt;
	new_salary:=inc_salary(enum,incr_amt);
	select salary into sal from emp18 where eno=enum;
	select up_date into ndate from emp18 where eno=enum;
	dbms_output.put_line('Employee number :'||enum);
	dbms_output.put_line('Old salary :'||sal);
	dbms_output.put_line('New salary :'||new_salary);
	dbms_output.put_line('Update date :'||ndate);
	exception
		when no_data_found then
			dbms_output.put_line('Invalid Employee number.');	
	commit;
end;
