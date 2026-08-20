# Write your MySQL query statement below
select e2.name
from Employee e1
Join Employee e2
on e1.managerId = e2.id
GROUP BY e2.id, e2.name
HAVING COUNT(*) >= 5;
