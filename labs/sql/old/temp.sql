declare 
	str varchar(15);
	len number(2);
begin
	
	str:='&str';
	len:=length(str);
	dbms_output.put_line('len: '||len);
end;
