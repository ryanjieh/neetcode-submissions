SELECT sales_person.name
FROM sales_person
WHERE NOT EXISTS (
    SELECT orders.order_id
    FROM orders LEFT JOIN company 
    ON orders.com_id = company.com_id
    WHERE sales_person.sales_id = orders.sales_id
    AND company.name = 'CRIMSON'
);