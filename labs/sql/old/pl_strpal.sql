--Program to check whether a string is a palindrome.

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
		dbms_output.put_line('Given string is a palindrome.');
	else
		dbms_output.put_line('Given string is not a palindrome.');
	end if;
end;

/*Enter value for str: amma
old   6: 	str:='&str';
new   6: 	str:='amma';
Given string is a palindrome.

PL/SQL procedure successfully completed. */
