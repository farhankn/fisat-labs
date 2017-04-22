--Trigger for client_master table

create trigger client24 before delete or update on client_master24 referencing old as o new as n for each row
	declare
		op varchar(10);
	begin
		if delete then
			op:='Delete';
		elsif modify then
		op:='Update';
		end if;
		insert into audit_client24 values(:o.c_no,:o.name,:o.bal_due,op,sysdate);
	end;

begin
	no varchar(5);
	bal number(7,2);
	operation varchar(10);
begin
	operation:='&operation';
	no:='&no';
	if operation='Update' then
		bal:=&bal;
		update client_master24 set bal_due=bal where c_no=no;
	elsif operation='Delete' then
		delete from client_master24 where c_no=no;
	end if;
end;


