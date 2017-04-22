--Function to increment salary.
create or replace function inc_salary
	(emp_id in varchar,incr in number)
	return number is
	newsal number(9,2);		
	sala number(9,2);
begin
	
		select salary into sala from emp18 where enum=emp_id;
		newsal:=sala+incr;
		update emp18 set new_sal=newsal where enum=emp_id;
		update emp18 set up_date=sysdate where enum=emp_id;
		return newsal;
	exception
		when no_data_found then
			dbms_output.put_line('Invalid Employee number.');	
	commit;
end;

