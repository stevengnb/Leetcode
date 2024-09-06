# Write your MySQL query statement below
DELETE p
FROM person p JOIN person j ON p.email = j.email
WHERE p.id > j.id