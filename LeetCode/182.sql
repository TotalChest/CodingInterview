SELECT DISTINCT
    Email
FROM
    (SELECT Email, count(Email) OVER(PARTITION BY Email) as Person_count 
     FROM Person) as Person_table
WHERE Person_count > 1;
