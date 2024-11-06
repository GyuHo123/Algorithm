-- 코드를 입력하세요
SELECT history_id, car_id, date_format(start_date, '%Y-%m-%d'), date_format(end_date, '%Y-%m-%d'),
CASE WHEN DATEDIFF(END_DATE, START_DATE) < 29 then '단기 대여' 
            ELSE '장기 대여' 
            END AS  RENT_TYPE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where year(start_date) = '2022' and month(start_date) = '9'
order by history_id desc