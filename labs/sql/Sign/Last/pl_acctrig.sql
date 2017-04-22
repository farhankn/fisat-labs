

create or replace trigger acc_trig18 
	before insert 
	on account18 
	referencing old as o new as n 
	for each row
declare
	cnt number(2);
	
begin
	select count(*) into cnt from account18 where name=:n.name;
	dbms_output.put_line(cnt);
	if cnt>2 then
		raise_application_error(-20001,'Limit of accounts exceeded.');
	end if;
	
end;
