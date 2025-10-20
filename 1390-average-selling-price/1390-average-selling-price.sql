# Write your MySQL query statement below
select p.product_id, ifnull(round(sum(p.price * u.units) / sum(u.units), 2), 0) as average_price
from prices p
left join unitsSold u
on p.product_id = u.product_id
and u.purchase_date between p.start_date and p.end_date
group by p.product_id

#NULLIF(x,0)	Avoids division by zero	NULLIF(0,0) → NULL
#IFNULL(x,0)	Converts NULL to 0	IFNULL(NULL,0) → 0

