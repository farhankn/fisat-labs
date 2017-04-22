declare 
	str varchar(15);
	ch varchar(15);
	len number(2);
begin
	str:='&str';
	len:=length(str);
	for i in reverse 1..len
	loop
		ch:=ch||substr(str,i,1);
	end loop;
	if str=ch then
		dbms_output.put_line('Palindrome.');
	else
		dbms_output.put_line('Not Palindrome.');
	end if;
end;
