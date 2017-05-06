SELECT COUNT(*)
FROM user1, trans
WHERE user1.userid = trans.userId AND user1.tax > 50000;
