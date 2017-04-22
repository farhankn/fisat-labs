--Sum of n natural numbers 

declare 
	num number(2);
	tot number(4);
	temp[] number(2);
begin
	num:=&num;
	tot:=0;
	for i in 1..num 
	loop
		temp[i]:=&temp[i];
		tot:=tot+temp[i];
	end loop;
	dbms_output.put_line('Sum of the numbers:'||tot);
end;
