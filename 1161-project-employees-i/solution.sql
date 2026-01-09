-- Write your PostgreSQL query statement below
SELECT p.project_id,
ROUND(SUM(e.experience_years)::NUMERIC/COUNT(p.project_id),2) AS average_years
FROM Project p
LEFT JOIN Employee e
ON e.employee_id=p.employee_id
GROUP BY p.project_id

