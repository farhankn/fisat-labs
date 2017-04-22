--Sum of first n natural numbers 

declare 
	num number(2);
	tot number(4);
begin
	num:=&num;
	tot:=0;
	for i in 1..num 
	loop
		tot:=tot+i;
	end loop;
	dbms_output.put_line('Sum of the numbers:'||tot);
end;
