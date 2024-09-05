# Write your MySQL query statement below
SELECT name AS 'Employee'
FROM employee e
WHERE managerId IS NOT NULL 
    AND salary > (
        SELECT salary
        FROM employee ee
        WHERE e.managerId = ee.id
    )