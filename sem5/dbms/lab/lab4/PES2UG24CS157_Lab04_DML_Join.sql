PROMPT (PES2UG24CS157@\u) [\d]>
CREATE DATABASE hostel;
USE hostel;

CREATE TABLE Hostel (
    Hostel_ID   INT PRIMARY KEY,
    Hostel_Name VARCHAR(100) NOT NULL,
    Location    VARCHAR(100) NOT NULL,
    Capacity    INT NOT NULL DEFAULT 0,
    CONSTRAINT chk_hostel_capacity CHECK (Capacity >= 0)
);
DESC Hostel;

CREATE TABLE Staff (
    Staff_ID      INT PRIMARY KEY,
    Staff_Name    VARCHAR(100) NOT NULL,
    Salary        DECIMAL(10,2) NOT NULL,
    Designation   VARCHAR(50) NOT NULL DEFAULT 'Support Staff',
    Hostel_ID     INT NOT NULL,
    Supervisor_ID INT NULL,
    CONSTRAINT chk_staff_salary CHECK (Salary > 0),
    CONSTRAINT fk_staff_hostel FOREIGN KEY (Hostel_ID)
        REFERENCES Hostel(Hostel_ID),
    CONSTRAINT fk_staff_supervisor FOREIGN KEY (Supervisor_ID)
        REFERENCES Staff(Staff_ID) ON DELETE SET NULL
);
DESC Staff;

CREATE TABLE Room (
    Hostel_ID   INT NOT NULL,
    Room_Number INT NOT NULL,
    Floor       INT NOT NULL DEFAULT 0,
    PRIMARY KEY (Hostel_ID, Room_Number),
    CONSTRAINT fk_room_hostel FOREIGN KEY (Hostel_ID)
        REFERENCES Hostel(Hostel_ID) ON DELETE CASCADE
);
DESC Room;

CREATE TABLE Bed (
    Hostel_ID   INT NOT NULL,
    Room_Number INT NOT NULL,
    Bed_Number  INT NOT NULL,
    Status      VARCHAR(10) NOT NULL DEFAULT 'Vacant',
    PRIMARY KEY (Hostel_ID, Room_Number, Bed_Number),
    CONSTRAINT chk_bed_status CHECK (Status IN ('Occupied','Vacant')),
    CONSTRAINT fk_bed_room FOREIGN KEY (Hostel_ID, Room_Number)
        REFERENCES Room(Hostel_ID, Room_Number) ON DELETE CASCADE
);
DESC Bed;

CREATE TABLE Student (
    Student_ID  INT PRIMARY KEY,
    First_Name  VARCHAR(50) NOT NULL,
    Middle_Name VARCHAR(50) NULL,
    Last_Name   VARCHAR(50) NOT NULL,
    Gender      VARCHAR(10) NOT NULL,
    DOB         DATE NOT NULL,
    Email       VARCHAR(100) NOT NULL UNIQUE
);
DESC Student;

CREATE TABLE Student_Phone (
    Student_ID   INT NOT NULL,
    Phone_Number VARCHAR(15) NOT NULL,
    PRIMARY KEY (Student_ID, Phone_Number),
    CONSTRAINT fk_phone_student FOREIGN KEY (Student_ID)
        REFERENCES Student(Student_ID) ON DELETE CASCADE
);
DESC Student_Phone;

CREATE TABLE Facility (
    Facility_ID     INT PRIMARY KEY,
    Facility_Name   VARCHAR(100) NOT NULL,
    Operating_Hours VARCHAR(20) DEFAULT '24x7',
    Hostel_ID       INT NOT NULL,
    CONSTRAINT fk_facility_hostel FOREIGN KEY (Hostel_ID)
        REFERENCES Hostel(Hostel_ID) ON DELETE CASCADE
);
DESC Facility;

CREATE TABLE Uses (
    Student_ID  INT NOT NULL,
    Facility_ID INT NOT NULL,
    Usage_Date  DATE NOT NULL,
    PRIMARY KEY (Student_ID, Facility_ID, Usage_Date),
    CONSTRAINT fk_uses_student FOREIGN KEY (Student_ID)
        REFERENCES Student(Student_ID) ON DELETE CASCADE,
    CONSTRAINT fk_uses_facility FOREIGN KEY (Facility_ID)
        REFERENCES Facility(Facility_ID) ON DELETE CASCADE
);
DESC Uses;

CREATE TABLE Allocation (
    Allocation_ID   INT PRIMARY KEY,
    Student_ID      INT NOT NULL,
    Hostel_ID       INT NOT NULL,
    Room_Number     INT NOT NULL,
    Allocation_Date DATE NOT NULL,
    Check_in_Date   DATE NOT NULL,
    Check_out_Date  DATE NULL,
    CONSTRAINT fk_alloc_student FOREIGN KEY (Student_ID)
        REFERENCES Student(Student_ID) ON DELETE CASCADE,
    CONSTRAINT fk_alloc_room FOREIGN KEY (Hostel_ID, Room_Number)
        REFERENCES Room(Hostel_ID, Room_Number) ON DELETE CASCADE
);
DESC Allocation;

CREATE TABLE Payment (
    Payment_ID   INT PRIMARY KEY,
    Student_ID   INT NOT NULL,
    Payment_Date DATE NOT NULL,
    Amount       DECIMAL(10,2) NOT NULL,
    Payment_Type VARCHAR(20) NOT NULL,
    CONSTRAINT chk_payment_amount CHECK (Amount > 0),
    CONSTRAINT fk_payment_student FOREIGN KEY (Student_ID)
        REFERENCES Student(Student_ID)
);
DESC Payment;

CREATE TABLE Receipt (
    Receipt_ID   INT PRIMARY KEY,
    Payment_ID   INT NOT NULL UNIQUE,
    Receipt_Date DATE NOT NULL,
    CONSTRAINT fk_receipt_payment FOREIGN KEY (Payment_ID)
        REFERENCES Payment(Payment_ID)
);
DESC Receipt;

SHOW TABLES;

INSERT INTO Hostel VALUES
(1, 'Sunrise Hostel', 'North Campus', 120),
(2, 'Blue Ridge Hostel', 'South Campus', 90),
(3, 'Lake View Hostel', 'East Campus', 60);
SELECT * FROM Hostel;

INSERT INTO Staff (Staff_ID, Staff_Name, Designation, Salary, Hostel_ID, Supervisor_ID) VALUES
(1, 'Ramesh Iyer', 'Warden', 45000, 1, NULL),
(4, 'Anita Sharma', 'Warden', 46000, 2, NULL),
(7, 'Kiran Bose', 'Warden', 44000, 3, NULL);

INSERT INTO Staff (Staff_ID, Staff_Name, Designation, Salary, Hostel_ID, Supervisor_ID) VALUES
(2, 'Sunil Kumar', 'Security', 22000, 1, 1),
(3, 'Geeta Rao', 'Cleaner', 18000, 1, 1),
(5, 'Mohan Das', 'Security', 21000, 2, 4),
(6, 'Priya Menon', 'Maintenance', 25000, 2, 4),
(8, 'Farhan Sheikh', 'Cleaner', 17500, 3, 7);
SELECT * FROM Staff;

INSERT INTO Room VALUES
(1, 101, 1), (1, 102, 1), (1, 201, 2),
(2, 101, 1), (2, 102, 1),
(3, 101, 1);
SELECT * FROM Room;

INSERT INTO Bed VALUES
(1, 101, 1, 'Occupied'), (1, 101, 2, 'Occupied'),
(1, 102, 1, 'Occupied'), (1, 102, 2, 'Vacant'),
(1, 201, 1, 'Occupied'), (1, 201, 2, 'Vacant'),
(2, 101, 1, 'Occupied'), (2, 101, 2, 'Vacant'),
(2, 102, 1, 'Occupied'), (2, 102, 2, 'Occupied'),
(3, 101, 1, 'Occupied'), (3, 101, 2, 'Vacant');
SELECT * FROM Bed;

INSERT INTO Student VALUES
(1, 'Aditya', NULL, 'Verma', 'M', '2005-03-14', 'aditya.verma@pes.edu'),
(2, 'Neha', 'R', 'Kulkarni', 'F', '2005-07-22', 'neha.kulkarni@pes.edu'),
(3, 'Rohan', NULL, 'Shetty', 'M', '2004-11-05', 'rohan.shetty@pes.edu'),
(4, 'Sanya', 'K', 'Malhotra', 'F', '2005-01-30', 'sanya.malhotra@pes.edu'),
(5, 'Vikram', NULL, 'Nair', 'M', '2004-09-18', 'vikram.nair@pes.edu'),
(6, 'Ishita', 'P', 'Bansal', 'F', '2005-05-09', 'ishita.bansal@pes.edu'),
(7, 'Arjun', NULL, 'Reddy', 'M', '2005-02-27', 'arjun.reddy@pes.edu'),
(8, 'Meera', 'S', 'Pillai', 'F', '2004-12-12', 'meera.pillai@pes.edu');
SELECT * FROM Student;

INSERT INTO Student_Phone VALUES
(1, '9876500001'), (1, '9876500011'),
(2, '9876500002'),
(3, '9876500003'),
(4, '9876500004'), (4, '9876500014'),
(5, '9876500005'),
(6, '9876500006'),
(7, '9876500007'),
(8, '9876500008');
SELECT * FROM Student_Phone;

INSERT INTO Facility VALUES
(1, 'WiFi Lounge', '24 Hours', 1),
(2, 'Laundry Room', '06:00-20:00', 1),
(3, 'Gym', '05:00-22:00', 2),
(4, 'Study Room', '24 Hours', 2),
(5, 'Common Room', '08:00-23:00', 3);
SELECT * FROM Facility;

INSERT INTO Uses VALUES
(1, 1, '2026-01-20'), (2, 1, '2026-01-20'), (3, 1, '2026-01-22'),
(1, 2, '2026-01-21'),
(4, 3, '2026-01-20'), (5, 3, '2026-01-21'),
(4, 4, '2026-01-25'), (6, 4, '2026-01-22'),
(7, 5, '2026-01-23');
SELECT * FROM Uses;

INSERT INTO Allocation VALUES
(1, 1, 1, 101, '2026-01-05', '2026-01-06', NULL),
(2, 2, 1, 101, '2026-01-05', '2026-01-06', NULL),
(3, 3, 1, 102, '2026-01-06', '2026-01-07', NULL),
(4, 4, 2, 101, '2026-01-05', '2026-01-06', NULL),
(5, 5, 2, 102, '2026-01-06', '2026-01-07', NULL),
(6, 6, 2, 102, '2026-01-06', '2026-01-07', NULL),
(7, 7, 3, 101, '2026-01-07', '2026-01-08', NULL),
(8, 3, 1, 201, '2025-06-01', '2025-06-02', '2025-12-20');
SELECT * FROM Allocation;

INSERT INTO Payment VALUES
(1, 1, '2026-01-10', 45000, 'Online'),
(2, 2, '2026-01-11', 45000, 'Cash'),
(3, 3, '2026-01-12', 42000, 'Card'),
(4, 4, '2026-01-10', 48000, 'Online'),
(5, 5, '2026-01-13', 48000, 'Cheque'),
(6, 6, '2026-01-14', 48000, 'Online'),
(7, 7, '2026-01-15', 40000, 'Cash'),
(8, 1, '2026-06-01', 45000, 'Online');
SELECT * FROM Payment;

INSERT INTO Receipt VALUES
(1, 1, '2026-01-10'),
(2, 2, '2026-01-11'),
(3, 3, '2026-01-12'),
(4, 4, '2026-01-10'),
(5, 5, '2026-01-13'),
(6, 6, '2026-01-14'),
(7, 7, '2026-01-15');
SELECT * FROM Receipt;

INSERT INTO Student (Student_ID, First_Name, Middle_Name, Last_Name, Gender, DOB, Email)
VALUES (9, 'Kabir', 'S', 'Oberoi', 'M', '2005-08-19', 'kabir.oberoi@pes.edu');
SELECT * FROM Student WHERE Student_ID = 9;

INSERT INTO Student_Phone (Student_ID, Phone_Number)
VALUES (9, '9876500009'), (9, '9876500019');
SELECT * FROM Student_Phone WHERE Student_ID = 9;

INSERT INTO Uses (Student_ID, Facility_ID, Usage_Date)
VALUES (9, 1, '2026-08-22'),
       (9, 5, '2026-08-23'),
       (5, 3, '2026-08-22');
SELECT * FROM Uses WHERE Student_ID IN (9, 5) AND Usage_Date >= '2026-08-22';

UPDATE Staff
SET Salary = Salary * 1.10
WHERE Designation = 'Warden';
SELECT * FROM Staff WHERE Designation = 'Warden';

UPDATE Allocation
SET Check_out_Date = '2026-08-20'
WHERE Student_ID = 3 AND Hostel_ID = 1 AND Room_Number = 102
  AND Check_out_Date IS NULL;

UPDATE Bed
SET Status = 'Vacant'
WHERE Hostel_ID = 1 AND Room_Number = 102 AND Bed_Number = 1;

SELECT * FROM Allocation WHERE Student_ID = 3;
SELECT * FROM Bed WHERE Hostel_ID = 1 AND Room_Number = 102;

INSERT INTO Payment (Payment_ID, Student_ID, Payment_Date, Amount, Payment_Type)
VALUES (9, 9, '2026-08-22', 45000, 'Online');

INSERT INTO Receipt (Receipt_ID, Payment_ID, Receipt_Date)
VALUES (8, 9, '2026-08-22');

SELECT * FROM Payment WHERE Payment_ID = 9;
SELECT * FROM Receipt WHERE Payment_ID = 9;

SELECT * FROM Payment
WHERE Payment_ID NOT IN (SELECT Payment_ID FROM Receipt);

DELETE FROM Payment
WHERE Payment_ID NOT IN (SELECT Payment_ID FROM Receipt);

SELECT Staff_Name AS Name, 'Staff' AS Role
FROM Staff
WHERE Hostel_ID = 1
UNION ALL
SELECT CONCAT(s.First_Name, ' ', s.Last_Name) AS Name, 'Student' AS Role
FROM Student s
JOIN Allocation a ON s.Student_ID = a.Student_ID
WHERE a.Hostel_ID = 1 AND a.Check_out_Date IS NULL;

SELECT Student_ID FROM Payment
INTERSECT
SELECT Student_ID FROM Uses;

SELECT Student_ID FROM Student
EXCEPT
SELECT Student_ID FROM Payment;

SELECT s.Student_ID, s.First_Name, s.Middle_Name, s.Last_Name,
       h.Hostel_Name, a.Room_Number
FROM Student s
JOIN Allocation a ON s.Student_ID = a.Student_ID
JOIN Hostel h ON a.Hostel_ID = h.Hostel_ID
WHERE a.Check_out_Date IS NULL;

SELECT st.Staff_ID, st.Staff_Name, sup.Staff_Name AS Supervisor_Name
FROM Staff st
LEFT JOIN Staff sup ON st.Supervisor_ID = sup.Staff_ID;

SELECT p.Payment_ID, CONCAT(s.First_Name, ' ', s.Last_Name) AS Student_Name,
       p.Amount, r.Receipt_ID
FROM Payment p
JOIN Student s ON p.Student_ID = s.Student_ID
LEFT JOIN Receipt r ON p.Payment_ID = r.Payment_ID;

SELECT s.Student_ID, s.First_Name, s.Last_Name
FROM Student s
LEFT JOIN Uses u ON s.Student_ID = u.Student_ID
WHERE u.Student_ID IS NULL;

SELECT h.Hostel_ID, h.Hostel_Name,
       COUNT(a.Student_ID) AS Current_Residents
FROM Hostel h
LEFT JOIN Allocation a
       ON h.Hostel_ID = a.Hostel_ID AND a.Check_out_Date IS NULL
GROUP BY h.Hostel_ID, h.Hostel_Name;

SELECT f.Facility_Name, CONCAT(s.First_Name, ' ', s.Last_Name) AS Student_Name,
       u.Usage_Date
FROM Uses u
JOIN Facility f ON u.Facility_ID = f.Facility_ID
JOIN Student s ON u.Student_ID = s.Student_ID
ORDER BY f.Facility_Name, u.Usage_Date;

SELECT r.Hostel_ID, r.Room_Number,
       COUNT(b.Bed_Number) AS Vacant_Beds
FROM Room r
LEFT JOIN Bed b
       ON r.Hostel_ID = b.Hostel_ID AND r.Room_Number = b.Room_Number
       AND b.Status = 'Vacant'
GROUP BY r.Hostel_ID, r.Room_Number;

SELECT st.Staff_ID, st.Staff_Name, h.Hostel_Name, h.Location
FROM Staff st
JOIN Hostel h ON st.Hostel_ID = h.Hostel_ID;

SELECT h.Hostel_ID, h.Hostel_Name,
       SUM(p.Amount) AS Total_Revenue
FROM Hostel h
JOIN Allocation a ON h.Hostel_ID = a.Hostel_ID AND a.Check_out_Date IS NULL
JOIN Payment p ON a.Student_ID = p.Student_ID
GROUP BY h.Hostel_ID, h.Hostel_Name;

SELECT f.Facility_ID, f.Facility_Name,
       COUNT(u.Student_ID) AS Usage_Count
FROM Facility f
LEFT JOIN Uses u ON f.Facility_ID = u.Facility_ID
GROUP BY f.Facility_ID, f.Facility_Name;

SELECT f.Facility_Name, h.Hostel_Name
FROM Hostel h
RIGHT JOIN Facility f ON h.Hostel_ID = f.Hostel_ID;

SELECT s.First_Name, s.Last_Name, s.Email AS Email_Address, a.Room_Number
FROM Student s
LEFT JOIN Allocation a
       ON s.Student_ID = a.Student_ID AND a.Check_out_Date IS NULL;