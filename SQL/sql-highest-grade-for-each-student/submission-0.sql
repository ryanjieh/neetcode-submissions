SELECT DISTINCT  student_id, 
FIRST_VALUE(exam_id) OVER (PARTITION BY student_id ORDER BY score DESC, exam_id ASC) as exam_id,
FIRST_VALUE(score) OVER (PARTITION BY student_id ORDER BY score DESC, exam_id ASC) as score
FROM exam_results
ORDER BY student_id ASC
;
