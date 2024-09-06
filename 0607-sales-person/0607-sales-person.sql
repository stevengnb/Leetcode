# Write your MySQL query statement below
SELECT name
FROM SalesPerson sp
WHERE sp.sales_id NOT IN (
    SELECT sales_id
    FROM Orders s JOIN Company c ON s.com_id = c.com_id
    WHERE c.name LIKE 'RED'
)