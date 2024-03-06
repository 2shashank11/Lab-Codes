set serveroutput on

create or replace function count_book(bk_subject varchar)
return number as bk_count number;

begin
    select count(*) into bk_count
    from count_book
    where subject=bk_subject

return bk_count;

end;/

begin
    dbms_output.put_line("Number of books is: " || count_book('&Subject'));
end;/