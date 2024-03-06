set serveroutput on;

create or replace procedure display_message(str varchar) is
begin
    dbms_output.put_line(str);
end;/

declare 
begin
    display_msg('Good Day to You');
end;/