# Write your MySQL query statement below
select s.student_id, s.student_name, sb.subject_name, count(ex.subject_name) as attended_exams
from Students s
cross join Subjects sb
left join Examinations ex 
on s.student_id = ex.student_id and sb.subject_name = ex.subject_name  
group by s.student_id, s.student_name, sb.subject_name
order by s.student_id, sb.subject_name