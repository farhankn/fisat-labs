--
create or replace trigger acc_trig18 
	before insert 
	on account18 
	referencing old as o new as n 
	for each row
declare
	cnt number(2);
	 err18 exception;
begin
	
	select count(*) into cnt from account18 where name=:o.name;
	if cnt=3 then
		raise err18;
	end if;
	exception
		when err18 then
			dbms_output.put_line('Limit Exceeded');	
	commit;		
end;
