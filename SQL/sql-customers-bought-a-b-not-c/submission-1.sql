SELECT customers.customer_id, customers.customer_name
FROM customers FULL OUTER JOIN orders
    ON customers.customer_id = orders.customer_id
GROUP BY customers.customer_id
HAVING (
    COUNT(CASE WHEN orders.product_name = 'A' THEN 1 END) > 0
    AND COUNT(CASE WHEN orders.product_name = 'B' THEN 1 END) > 0
    AND COUNT(CASE WHEN orders.product_name = 'C' THEN 1 END) = 0
)
ORDER BY customers.customer_name
;
