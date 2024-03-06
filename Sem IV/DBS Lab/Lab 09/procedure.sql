set serveroutput on;

create or replace procedure display_hello(nam varchar) is
pl_name varchar(20);

begin   
    p1_name :=nam;
    dbms_output.put_line('Hello ' || pl_name);
end;/