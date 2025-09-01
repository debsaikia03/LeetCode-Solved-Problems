# Write your MySQL query statement below
select p.project_id, round(sum(e.experience_years) * 1.0/ count(distinct p.employee_id), 2) as average_years
from project as p
join employee as e
on p.employee_id = e.employee_id 
group by p.project_id