# Week 5 |  DML and Join SQL Queries 
### Name: Dharani S
### SRN: PES2UG24CS157
### Section: C
## Task 1
## Creating tables
### Hostel
![alt text](image.png)
### Staff
![alt text](image-1.png)
### Room
![alt text](image-2.png)
### Bed
![alt text](image-3.png)
### Student
![alt text](image-4.png)
### Student_phone
![alt text](image-5.png)
### Facility
![alt text](image-6.png)
### Uses
![alt text](image-7.png)
### Allocation
![alt text](image-8.png)
### Payment
![alt text](image-9.png)
### Receipt
![alt text](image-10.png)
### All 11 tables
![alt text](image-11.png)
<div class="page-break"></div>

## Inserting sample data
### Hostel
![alt text](image-12.png)
### Staff
![alt text](image-13.png)
### Room
![alt text](image-14.png)
### Bed
![alt text](image-15.png)
### Student
![alt text](image-16.png)
### Student_phone
![alt text](image-17.png)
### Facility
![alt text](image-18.png)
### Uses
![alt text](image-19.png)
### Allocation
![alt text](image-20.png)
### Payment
![alt text](image-21.png)
### Receipt
![alt text](image-22.png)

<div class="page-break"></div>

## Task 2
### **PART A**
### Q1. Insert a new student, Kabir S. Oberoi (Male, DOB 2005-08-19, email kabir.oberoi@pes.edu), into Student.
![alt text](image-23.png)
### Q2. In a single INSERT statement, add both of Kabir's phone numbers -- 9876500009 and 9876500019 -- to Student_Phone. 
![alt text](image-24.png)
### Q3. In a single INSERT statement, record three new facility usage events: Kabir uses the WiFi Lounge (Facility_ID 1) on 2026-08-22, Kabir uses the Common Room (Facility_ID 5) on 2026-08-23, and Vikram Nair (Student_ID 5) uses the Gym (Facility_ID 3) on 2026-08-22. 
![alt text](image-25.png)
### Q4. The university approves a 10% salary hike for every Warden across all hostels. Update Staff accordingly. 
![alt text](image-26.png)
### Q5. Rohan Shetty (Student_ID 3) checks out of Room 102, Hostel 1 on 2026-08-20. Close his current allocation record and free up his bed (Bed_Number 1 in that room). 
![alt text](image-27.png)
### Q6. Record a new payment of 45000 (Online) made by Kabir on 2026-08-22, and the receipt generated for it on the same date. 
![alt text](image-28.png)
### Q7. Delete every payment that does not yet have a matching receipt. Do this with a subquery -- do not hard-code any Payment_ID. 
![alt text](image-29.png)
### Q8. List the names of all staff members working in Hostel 1 along with the first and last names of all students currently allocated to Hostel 1. Combine both result sets using UNION ALL. Display the name(s) and role (Staff or Student) for each record.  
![alt text](image-30.png)
### Q9. Using INTERSECT, find the Student_IDs of students who have both made at least one payment and used at least one facility. 
![alt text](image-31.png)
### Q10. Using EXCEPT, find every student who has never made a payment. 
![alt text](image-32.png)

<div class="page-break"></div>

### **Part B**
### Q1. List the Student_ID, first, middle and last name, hostel name and room number of every student who currently has an active allocation (Check_out_Date IS NULL). 
![alt text](image-33.png)
### Q2. List every staff member along with the name of their supervisor
![alt text](image-34.png)
### Q3. List every payment together with the paying student's name and the corresponding receipt number, if one has been generated. 
![alt text](image-35.png)
### Q4. Find every student who has never used any hostel facility. 
![alt text](image-36.png)
### Q5. For each hostel, count how many students currently reside in it (include hostels with zero current residents). 
![alt text](image-37.png)

### Q6. List every facility usage record as: facility name, student name, usage date -- ordered by facility, then date. 
![alt text](image-38.png)
### Q7. For every room, report how many beds in it are currently vacant. 
![alt text](image-39.png)
### Q8. List every staff member with the name and location of the hostel they work at.
![alt text](image-40.png) 
### Q9. For each hostel, compute the total fee revenue collected from its currently-residing students. 
![alt text](image-41.png)
### Q10. List every facility together with how many times it has been used, including facilities that have never been used. 
![alt text](image-42.png)
### Q11. Write a query using a RIGHT JOIN between HOSTEL and FACILITY to list all facilities along with the name of the hostel providing each facility.  
![alt text](image-43.png)
### Q12. Write a query using a LEFT JOIN to list all students (First_Name, Last_Name, Email_Address) along with their assigned Room_Number. Ensure that students who do not have an allocated room, such as Rohan, are also included in the result.
![alt text](image-44.png)