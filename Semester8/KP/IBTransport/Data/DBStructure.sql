/*=================================================================*/
  CREATE DATABASE "C:\Users\kp\Desktop\IBTransport\Data\IBTransport.gdb"
             user "SYSDBA"
         password "masterkey"
         page_size=4096;
/*=================================================================*/
CREATE TABLE TRUCKS_TBL
(
ID INTEGER NOT NULL,
KATNO VARCHAR(12),
DESCRIPTION VARCHAR(25),
PRIMARY KEY(ID)
);

CREATE TABLE MAT_TBL
(
ID INTEGER NOT NULL,
NAME VARCHAR(25),
PRIMARY KEY(ID)
);

CREATE TABLE TRANSPORTS_TBL
(
ID INTEGER NOT NULL,
TID INTEGER,
MID INTEGER,
DATA VARCHAR(12),
QUANTITY NUMERIC(14,2),
PRIMARY KEY(ID),
FOREIGN KEY(TID) REFERENCES TRUCKS_TBL(ID),
FOREIGN KEY(MID) REFERENCES MAT_TBL(ID)
);

/*=================================================================*/

CREATE GENERATOR TRUCKSTBL_IDGEN;
SET GENERATOR TRUCKSTBL_IDGEN TO 0;

CREATE GENERATOR TRANSPORTSTBL_IDGEN;
SET GENERATOR TRANSPORTSTBL_IDGEN TO 0;


SET TERM ^ ;

CREATE PROCEDURE TRUCKSTBL_IDSP
RETURNS(ID INTEGER)
AS
BEGIN
ID = GEN_ID(TRUCKSTBL_IDGEN, 1);
END^

CREATE PROCEDURE TRANSPORTSTBL_IDSP
RETURNS(ID INTEGER)
AS
BEGIN
ID = GEN_ID(TRANSPORTSTBL_IDGEN, 1);
END^

SET TERM ; ^

/*=================================================================*/

CREATE INDEX TrucksTblKatNoNDX ON TRUCKS_TBL(KATNO);
CREATE INDEX TrucksTblDescriptionNDX ON TRUCKS_TBL(DESCRIPTION);

/*=================================================================*/

SELECT M.NAME AS MATERIAL, SUM(T.QUANTITY) AS KOLICHESTVO
FROM TRUCKS_TBL TK, TRANSPORTS_TBL T, MAT_TBL M
WHERE TK.KATNO = :PKATNO AND TK.ID = T.TID AND T.MID = M.ID
GROUP BY M.NAME

/*=================================================================*/

