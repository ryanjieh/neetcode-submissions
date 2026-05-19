SELECT DISTINCT seller_name 
FROM seller 
WHERE NOT EXISTS (
    SELECT orders.order_id
    FROM orders
    WHERE seller.seller_id = orders.seller_id
    AND orders.sale_date > '2019-12-31'
    AND orders.sale_date < '2021-01-01'
);