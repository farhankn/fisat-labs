declare 
	total number(15);
	grade varchar2(2);
	roll number(3);
	dis_amt number(9);
begin
	roll:='&roll';
	select mark1+mark2+mark3 into total from marks18 where roll=RNO;
	
	dbms_output.put_line(total);

	if (total>=250 and total<300) then 
		grade:='A';
	elsif (total>=200 and total<250) then 
		grade:='B';
	elsif (total>=150 and total<200) then 
		grade:='C';
	elsif (total>=120 and total<150) then 
		grade:='D';
	else  
		grade:='F';
	end if;
	
	
	dbms_output.put_line('The Grade of the student is : '|| grade);
	commit;
end;

