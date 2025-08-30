# Write your MySQL query statement below
select MAX(salary) as secondhighestsalary
from employee
where salary < (
    select max(salary) from employee
);