create or replace trigger trigbank
before insert
on ac
referencing OLD as o NEW as n
for each row

declare
     c number(2);
	     	
begin
  
 
       select count(*) into c from ac where cname=:n.cname; 
       dbms_output.put_line('No of accounts=' || c);
       if c>2 then
		raise_application_error(-20000,'Cannot have any more accounts for this account no. ');
       end if;
end;
