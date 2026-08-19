# Write your MySQL query statement below
Select e.name, b.bonus
From Employee e
Left Join bonus b
on e.empID = b.empId
WHERE b.bonus < 1000
OR b.bonus IS NULL;