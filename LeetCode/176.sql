SELECT IFNULL((SELECT DISTINCT
                Salary AS SecondHighestSalary
            FROM
                Employee
            ORDER BY Salary DESC
            LIMIT 1 OFFSET 1), NULL) as SecondHighestSalary;
