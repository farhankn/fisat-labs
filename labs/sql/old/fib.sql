declare 
	num number(2);
	num1 number(2);
	num2 number(2);
	temp number(2);
begin
	num:=&num;
	num1:=0;
	num2:=1;
	dbms_output.put_line('Series is as follows:');
	for i in 1..num 
	loop
		dbms_output.put_line(num1);
		temp:=num2;		
		num2:=num1+num2;
		num1:=temp;			
	end loop;	
end;
