

declare 
	total number(15);
	dis number(9);
	code varchar2(4);
	dis_amt number(9);
begin
	code:='&code';
	select item_qty*(item_rate+item_tax*item_rate/100) into total from purchase_details24 where p_code=code;
	dbms_output.put_line(total);

	if (total>=1000 and total<5000) then 
		dis:=total*5/100;
	elsif (total>=5001 and total<10000) then 
		dis:=total*5.5/100;
	elsif (total>=10001 and total<50000) then 
		dis:=total*6/100;
	elsif (total>=50001 and total<100000) then 
		dis:=total*7/100;
	else  
		dis:=total*8/100;
	end if;
	
	dis_amt:=total-dis;
dbms_output.put_line(dis);
	dbms_output.put_line('The discount price: '||dis_amt);
	commit;
end;

