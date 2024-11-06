-- 코드를 입력하세요
SELECT concat('/home/grep/src/', a.BOARD_ID, '/', a.FILE_ID, a.FILE_NAME, a.FILE_EXT) as FILE_PATH from used_goods_file a join USED_GOODS_BOARD b on a.board_id = b.board_id
where b.views = 
(
    select max(views)
    from used_goods_board
)
ORDER BY FILE_ID DESC