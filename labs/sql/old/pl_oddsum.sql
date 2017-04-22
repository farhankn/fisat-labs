--Sum of odd numbers with in a range

declare 
	lnum number(2);
	fnum number(2);
	num number(2);
	tot number(4);
begin
	fnum:=&fnum;
	lnum:=&lnum;
	tot:=0;
	if mod(fnum,2)=0 then
		num:=fnum+1;
	else
		num:=fnum;
	end if;
	while num<=lnum 
	loop
		tot:=tot+num;
		num:=num+2;
	end loop;
	dbms_output.put_line('Sum of the numbers:'||tot);
end;
