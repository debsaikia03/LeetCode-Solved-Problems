# Write your MySQL query statement below
# select MAX(salary) as secondhighestsalary
# from employee
# where salary < (
#    select max(salary) from employee
# );

select( 
    select distinct salary 
    from employee 
    order by salary desc
    limit 1 offset 1 
) as secondhighestsalary
