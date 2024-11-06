-- 코드를 작성해주세요
select a.id, b.fish_name, a.length
from fish_info a join fish_name_info b on a.fish_type = b.fish_type
where a.fish_type in
(
    SELECT FISH_TYPE
    FROM fish_info
    GROUP BY FISH_TYPE
    HAVING LENGTH = MAX(LENGTH)
)
order by id asc