--Fibonacci series

declare 
	num number(2);
	temp1 number(2);
	temp2 number(2);
	temp number(2);
begin
	num:=&num;
	temp1:=0;
	temp2:=1;
	dbms_output.put_line('Fibonacci Series:');
	for i in 1..num 
	loop
		dbms_output.put_line(temp1);
		temp:=temp2;		
		temp2:=temp1+temp2;
		temp1:=temp;
		
	
	end loop;
	
end;