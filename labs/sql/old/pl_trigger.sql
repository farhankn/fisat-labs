--Trigger for client_master table2.

create or replace trigger client18 
	before delete or update 
	on client_master18 
	referencing old as o new as n 
	for each row
declare
		op varchar(10);
begin
		if deleting then
			op:='Delete';
		elsif updating then
			op:='Update';
		end if;
		insert into audit_client18 values(:o.c_no,:o.name,:o.bal_due,op,sysdate);
end;


