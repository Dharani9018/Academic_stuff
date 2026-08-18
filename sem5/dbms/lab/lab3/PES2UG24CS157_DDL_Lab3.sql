CREATE DATABASE smart_hostel_mgmt;
USE smart_hostel_mgmt;

CREATE TABLE HOSTEL (
    Hostel_ID     INT PRIMARY KEY,
    Hostel_Name   VARCHAR(50) NOT NULL,
    Location      VARCHAR(100),
    Capacity      INT CHECK (Capacity > 0)
);

CREATE TABLE STAFF (
    Staff_ID       INT PRIMARY KEY,
    Name           VARCHAR(50) NOT NULL,
    Salary         DECIMAL(10,2) DEFAULT 0,
    Job            VARCHAR(50),
    Hostel_ID      INT NOT NULL,
    Supervisor_ID  INT,
    FOREIGN KEY (Hostel_ID) REFERENCES HOSTEL(Hostel_ID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (Supervisor_ID) REFERENCES STAFF(Staff_ID)
        ON DELETE SET NULL ON UPDATE CASCADE
);

CREATE TABLE ROOM (
    Hostel_ID    INT,
    Room_Number  VARCHAR(10),
    Floor        INT,
    PRIMARY KEY (Hostel_ID, Room_Number),
    FOREIGN KEY (Hostel_ID) REFERENCES HOSTEL(Hostel_ID)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE BED (
    Hostel_ID     INT,
    Room_Number   VARCHAR(10),
    Bed_Number    VARCHAR(10),
    Availability  ENUM('Available','Occupied') DEFAULT 'Available',
    PRIMARY KEY (Hostel_ID, Room_Number, Bed_Number),
    FOREIGN KEY (Hostel_ID, Room_Number) REFERENCES ROOM(Hostel_ID, Room_Number)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE STUDENT (
    Student_ID     INT PRIMARY KEY,
    First_Name     VARCHAR(50) NOT NULL,
    Middle_Name    VARCHAR(50),
    Last_Name      VARCHAR(50) NOT NULL,
    Gender         CHAR(1),
    Date_of_Birth  DATE,
    Email_Address  VARCHAR(100) UNIQUE
);

CREATE TABLE STUDENT_PHONE (
    Student_ID    INT,
    Phone_Number  VARCHAR(15),
    PRIMARY KEY (Student_ID, Phone_Number),
    FOREIGN KEY (Student_ID) REFERENCES STUDENT(Student_ID)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE ALLOCATES (
    Hostel_ID        INT,
    Room_Number      VARCHAR(10),
    Student_ID       INT,
    Allocation_Date  DATE,
    Check_in_Date    DATE,
    Check_out_Date   DATE,
    PRIMARY KEY (Hostel_ID, Room_Number, Student_ID, Allocation_Date),
    FOREIGN KEY (Hostel_ID, Room_Number) REFERENCES ROOM(Hostel_ID, Room_Number)
        ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (Student_ID) REFERENCES STUDENT(Student_ID)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE PAYMENT (
    Payment_ID    INT PRIMARY KEY,
    Payment_Date  DATE DEFAULT (CURRENT_DATE),
    Amount        DECIMAL(10,2) CHECK (Amount > 0),
    Payment_Type  VARCHAR(30),
    Student_ID    INT NOT NULL,
    FOREIGN KEY (Student_ID) REFERENCES STUDENT(Student_ID)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE RECEIPT (
    Receipt_ID    INT PRIMARY KEY,
    Receipt_Date  DATE,
    Payment_ID    INT NOT NULL UNIQUE,
    FOREIGN KEY (Payment_ID) REFERENCES PAYMENT(Payment_ID)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE FACILITY (
    Facility_ID      INT PRIMARY KEY,
    Facility_Name    VARCHAR(50) NOT NULL,
    Operating_Hours  VARCHAR(30),
    Hostel_ID        INT NOT NULL,
    FOREIGN KEY (Hostel_ID) REFERENCES HOSTEL(Hostel_ID)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE USES (
    Student_ID   INT,
    Facility_ID  INT,
    Usage_Date   DATE,
    PRIMARY KEY (Student_ID, Facility_ID, Usage_Date),
    FOREIGN KEY (Student_ID) REFERENCES STUDENT(Student_ID)
        ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (Facility_ID) REFERENCES FACILITY(Facility_ID)
        ON DELETE CASCADE ON UPDATE CASCADE
);

SHOW TABLES;

ALTER TABLE FACILITY ADD COLUMN Facility_Code VARCHAR(10) FIRST;
DESC FACILITY;

ALTER TABLE STAFF ADD CONSTRAINT chk_salary CHECK (Salary >= 0);
SHOW CREATE TABLE STAFF\G

ALTER TABLE STAFF CHANGE COLUMN Job Designation VARCHAR(50);
DESC STAFF;

ALTER TABLE STUDENT MODIFY COLUMN Gender ENUM('M','F','Other');
DESC STUDENT;

ALTER TABLE STAFF DROP COLUMN Designation;
DESC STAFF;

ALTER TABLE HOSTEL MODIFY COLUMN Hostel_Name VARCHAR(100);
DESC HOSTEL;

ALTER TABLE PAYMENT RENAME TO FEE_PAYMENT;
SHOW TABLES;

SHOW CREATE TABLE RECEIPT\G

ALTER TABLE RECEIPT DROP FOREIGN KEY receipt_ibfk_1;
DROP TABLE FEE_PAYMENT;
SHOW TABLES;
