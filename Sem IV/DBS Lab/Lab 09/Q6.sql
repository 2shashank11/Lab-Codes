set serveroutput on;

create or replace function department_highest(dept varchar) is
    cursor c(d instructor.dept_name) is select * from instructor where dept_name = dept;
    inst_salary integer;
    inst_name instructor.name%type;

    begin
    open c;
    inst_salary := 0;
        for i in c(dept) loop
            if i.salary>inst_salary then 
                inst_salary := i.salary;
                inst_name := i.name;
            end if;
        end loop;
    close c;
    end;/
declare
    cursor c is select distinct dept_name from department;
begin
    open c;
    for i in c loop 
        department_highest(i.dept_name);
    end loop;  
    close c; 
end;/