--Trigger to update patient history.

create or replace trigger patient_24 
	before update
 	on pdetails24 
	referencing old as o new as n 
	for each row
declare	
	pid varchar(5);
	name varchar(10);
	addr varchar(10);
begin
	if updating then
		pid:=:o.p_id;
		select pname into name from patient24 where p_id=pid;
		select address into addr from patient24 where p_id=pid;
		insert into history24 values(:o.p_id,name,addr,:o.disease,:o.drname,sysdate);
		delete from patient24 where p_id=:o.p_id;
	end if;
end;
