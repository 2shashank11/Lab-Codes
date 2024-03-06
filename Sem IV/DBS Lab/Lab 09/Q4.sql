set serveroutput on;

create or replace procedure display_students(dept varchar) is
    cursor c is select name from student where dept_name = dept;

    begin  
    dbms_output.put_line("Students from department: " || dept);
    open c;
    for i in c loop
        dbms_output.put_line(i.name);
    end loop;
    close c;
    end;/

create or replace procedure display_courses(dept varchar) is
    cursor c is select course_id, title from course where dept_name = dept;
    begin
        open c;
        for i in c loop    
                dbms_output.put_line(i.course_id || ' ' || i.title);
        end loop;
        close c;
    end;/

declare
    dept department.dept_name%type;
begin
    dept := ('&dept');
    display_students(dept);
    display_course(dept);
end;/
