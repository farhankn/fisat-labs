--Student grade using procedure.

create or replace procedure roll_grade
	(no in number,g out varchar) is
	tot number(5,2);
	mrk1 number(5,2);
	mrk2 number(5,2);
	mrk3 number(5,2);
begin
	select m1 into mrk1 from student_master24 where rollno=no;
	select m2 into mrk2 from student_master24 where rollno=no;
	select m3 into mrk3 from student_master24 where rollno=no;
	tot:=mrk1+mrk2+mrk3;
	if tot>250 then
		g:='A';
	elsif tot>200 and tot<=250 then
		g:='B';
	elsif tot>150 and tot<=200 then
		g:='C';
	elsif tot>100 and tot<=150 then
		g:='D';
	else
		g:='F';
	end if;
	dbms_output.put_line('Total :'||tot);
end;


/*  SQL> @pl_procedure2.sql;
 27  /

Procedure created. */
