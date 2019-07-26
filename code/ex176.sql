SELECT MAX(Salary) AS SecondHighestSalary
From Employee
WHERE Salary NOT IN(
    SELECT MAX(Salary)
    FROM Employee
);
