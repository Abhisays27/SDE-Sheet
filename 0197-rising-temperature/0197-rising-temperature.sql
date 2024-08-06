# Write your MySQL query statement below
SELECT w2.id 
FROM Weather w1, Weather w2 
WHERE w2.temperature > w1.temperature AND w1.id + 1 = w2.id;

