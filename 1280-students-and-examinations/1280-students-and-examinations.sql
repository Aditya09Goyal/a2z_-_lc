with tmp as (
    SELECT * FROM Students as st 
    CROSS JOIN Subjects as sub 
)
select t.student_id , t.student_name , t.subject_name , count(e.subject_name) as attended_exams
from tmp t 
left join examinations as e 
on t.student_id = e.student_id and t.subject_name = e.subject_name 
group by t.student_id , t.student_name, t.subject_name 
order by t.student_id 