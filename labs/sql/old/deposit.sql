declare
        cursor c_dep is select deposit24.acc_id,customer24.cus_name,deposit24.amt
                 from deposit24,customer24 where deposit24.cus_id=customer24.cus_id;
        amt number(9,2);
        a_id number(5);
        tax number(9,2);
        c_id  varchar(5);
        d_amt number(9,2);
        l_amt number(9,2);
        a_id1 c_dep%type;
        c_name c_dep%type;
        amount c_dep%type;
begin
        c_id:='&c_id';
        amt:=&amt;
        select amt into d_amt from deposit24 where cus_id=c_id;
        if amt>d_amt then
                l_amt:=amt-d_amt;
                select acc_id into a_id from deposit24 where cus_id=c_id;
                insert into loan24 values(c_id,a_id,l_amt);
                dbms_output.put_line('One row added to table loan.');
        endif;
        open c_dep a_id1,c_name,amount;
        if c_dep%isopen then
                loop
                        fetch c_dep a_id1,c_name,amount;
                        if c_dep%isfound then
                                tax=.01*amount;
                                dbms_output.put_line('Account id: '||a_id||' Customer name: '||c_name||' Tax: '||tax );
                        endif;
                end loop;
        endif;
end;






