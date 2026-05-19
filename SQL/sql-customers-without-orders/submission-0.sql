-- Write your query below
SELECT DISTINCT c.name as name
FROM customers c
WHERE NOT EXISTS (
    SELECT orders.id
    FROM customers RIGHT JOIN orders
        ON customers.id = orders.customer_id
    WHERE customers.name = c.name
);
