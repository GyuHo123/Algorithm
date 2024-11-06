-- 코드를 입력하세요
SELECT a.user_id, a.nickname, concat(city, ' ', street_address1, ' ', STREET_ADDRESS2) as 전체주소, concat(substring(tlno, 1, 3), '-', substring(tlno, 4, 4), '-', substring(tlno, 8)) as 전화번호
from USED_GOODS_USER a join USED_GOODS_BOARD b on b.WRITER_ID = a.USER_ID
GROUP BY writer_id
HAVING count(writer_id) >= 3
order by a.user_id desc
