set serveroutput on

create or replace function square(n number) is 
    return number as squared number;

    begin
    squared := n*n;
    return squared;
    end;/

declare
    n number;
begin
    n := ('&n');
    dbms_output.put_line('Square of ' || n || ' is ' || square(n));
end;