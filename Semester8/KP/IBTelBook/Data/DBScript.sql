/*=================================================================*/
CREATE DATABASE "C:\Projects\IBTelBook\Data\IBTelBook.gdb"
         user "SYSDBA"
         password "masterkey"
         page_size=4096;
/*=================================================================*/
CREATE TABLE PERSONS_TBL
(
ID INTEGER NOT NULL,
NAME VARCHAR(12),
FAM VARCHAR(15),
ADDRESS VARCHAR(33),
PRIMARY KEY(ID)
);

CREATE TABLE TELTYPES_TBL
(
ID INTEGER NOT NULL,
TELTYPE VARCHAR(10),
PRIMARY KEY(ID)
);

CREATE TABLE TELS_TBL
(
ID INTEGER NOT NULL,
PID INTEGER,
TID INTEGER,
NOMER VARCHAR(33),
PRIMARY KEY(ID),
FOREIGN KEY(PID) REFERENCES PERSONS_TBL(ID),
FOREIGN KEY(TID) REFERENCES TELTYPES_TBL(ID)
);
