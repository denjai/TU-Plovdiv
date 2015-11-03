/*=================================================================*/
  CREATE DATABASE "C:\exam\IBBookShop\Data\IBBookShop.gdb"
             user "SYSDBA"
         password "masterkey"
         page_size=4096;
/*=================================================================*/
CREATE TABLE AUTHORS_TBL
(
ID INTEGER NOT NULL,
NAME VARCHAR(12),
FAM  VARCHAR(15),
PRIMARY KEY(ID)
);

CREATE TABLE GENRES_TBL
(
ID INTEGER NOT NULL,
NAME VARCHAR(15),
PRIMARY KEY(ID)
);

CREATE TABLE BOOKS_TBL
(
ID INTEGER NOT NULL,
AID INTEGER,
GID INTEGER,
ISBN VARCHAR(12),
NAME VARCHAR(50),
PRIMARY KEY(ID),
FOREIGN KEY(AID) REFERENCES AUTHORS_TBL(ID),
FOREIGN KEY(GID) REFERENCES GENRES_TBL(ID)
);
/*=================================================================*/

CREATE GENERATOR AUTHORSTBL_IDGEN;
SET GENERATOR AUTHORSTBL_IDGEN TO 0;

CREATE GENERATOR BOOKSTBL_IDGEN;
SET GENERATOR BOOKSTBL_IDGEN TO 0;


SET TERM ^ ;

CREATE PROCEDURE AUTHORSTBL_IDSP
RETURNS(ID INTEGER)
AS
BEGIN
ID = GEN_ID(AUTHORSTBL_IDGEN, 1);
END^

CREATE PROCEDURE BOOKSTBL_IDSP
RETURNS(ID INTEGER)
AS
BEGIN
ID = GEN_ID(BOOKSTBL_IDGEN, 1);
END^

SET TERM ; ^

/*=================================================================*/

CREATE INDEX AuthorsTblNameNDX ON AUTHORS_TBL(NAME);
CREATE INDEX AuthorsTblFamNDX  ON AUTHORS_TBL(FAM);

/*=================================================================*/

SELECT A.NAME as AUTHOR, B.NAME as BOOK, G.NAME AS GENRE
FROM GENRES_TBL G, BOOKS_TBL B, AUTHORS_TBL A
WHERE G.NAME LIKE :PNAME AND G.ID = B.GID AND B.AID = A.ID

/*=================================================================*/

