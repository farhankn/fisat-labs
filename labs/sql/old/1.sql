declare
	n number(2);
	i number(2);
begin

	for i in 0..5
	loop:
		n:=n+i;	
	end loop;
	
dbms_output.put_line("sum",n);
end
