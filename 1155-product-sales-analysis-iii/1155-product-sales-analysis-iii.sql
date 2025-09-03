# Write your MySQL query statement below
SELECT product_id, year AS first_year, quantity, price
FROM sales 
WHERE (product_id, year) in (
    SELECT product_id, MIN(year) as first_year
    FROM sales
    GROUP BY product_id
)