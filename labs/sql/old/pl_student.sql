--Student Grade
declare
	no number(3);
	
	grade varchar(2);
begin
	no:=&no;
	roll_grade(no,grade);
	dbms_output.put_line('Grade :'||grade);
	exception
		when no_data_found then
			dbms_output.put_line('Invalid Employee number.');	
	commit;
end;


