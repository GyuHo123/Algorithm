-- 코드를 작성해주세요
select a.item_id, b.item_name, b.rarity from item_tree a
join item_info b on a.item_id = b.item_id
WHERE a.PARENT_ITEM_ID IN (SELECT ITEM_ID
                              FROM ITEM_INFO
                              WHERE RARITY='RARE')
ORDER BY
    a.ITEM_ID DESC