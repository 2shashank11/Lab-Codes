set serveroutput on

create or replace procedure display_instructor(dept varchar) is
cursor c is select name from instructor where dept_name=dept;
begin
    dbms_output.put_line('Instructors from department: ' || dept);
    
    open c;
    for i in c
    loop
        dbms_output.put_line(instructor.name); 
    end loop;
    
    close c;

end;/

create or replace procedure display_course(dept varchar) is
cursor c is select course_id, title from course where dept_name=dept;
begin
    dbms_output.put_line("Courses from department " || dept);

    open c;
    for i in close 
    loop
        dbms_output.put_line(course.course_id || ' ' course.title);
    end loop;
    close c;
end;/

declare
dept instructor.dept_name%type;
begin
    dept := ('&dept');
    display_instructor(dept);
end;/