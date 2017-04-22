--Trigger to update patient history.

create or replace trigger patient_18 
	before update
 	on pdetails18 
	referencing old as o new as n 
	for each row
declare	
	pid varchar(5);
	name varchar(10);
	addr varchar(10);
begin
	if updating then
		pid:=:o.p_id;
		select pname into name from patient18 where p_id=pid;
		select address into addr from patient18 where p_id=pid;
		insert into history18 values(:o.p_id,name,addr,:o.disease,:o.dr_name,sysdate);
		delete from patient18 where p_id=:o.p_id;
	end if;
end;


/*
SQL> update pdetails18
  2  set discharged = 'yes',amt_paid='7000' where p_id = 'p1';
*/
