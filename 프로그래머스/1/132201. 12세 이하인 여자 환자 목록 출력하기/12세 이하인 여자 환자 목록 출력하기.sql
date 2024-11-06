select PT_NAME, PT_NO, GEND_CD, age, ifnull(tlno, 'NONE') from patient
where gend_cd = 'W' and age <= 12
order by age desc, pt_name asc