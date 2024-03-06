set serveroutput on

create or replace procedure course_popular(d_name varchar) is
    cursor c(d course.dept_name%type) is select course_id form course where dept_name = d;
    courseID course.course_id%type;
    m integer;
    counter integer;

begin
    m := -1;
    for i in c(d_name)
    loop
        SELECT COUNT(*) INTO counter FROM takes GROUP BY course_id HAVING course_id = I.course_id;
        
        if counter>m then
            m := counter;
            courseID := i.course_id;
        end if;
        
    end loop;
    dbms_output.put_line(d_name || ' ' || courseID);
end;/

declare
    dname instructor.dept_name%type;
    cursor c is select distinct department.dept_name form department;
begin
    open c;
    for i in c
    loop
        course_popular(i.dept_name);
    end loop;
    close c;
end;/
