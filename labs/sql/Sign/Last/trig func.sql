create or replace procedure insertcontent
	(name in varchar)
	 is
	bal number(9,2);
	br varchar(15);
begin
	
		bal:=&bal;
		br:='&br';
		insert into account18 values(name,accno18.nextval,bal,br);
	
	commit;
end;
