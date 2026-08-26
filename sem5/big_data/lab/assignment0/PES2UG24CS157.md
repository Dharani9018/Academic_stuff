# Assignment0: Hadoop Map reduce
### Name: Dharani S
### SRN: PES2UG24CS157
### Section: C

## 1. Verify the number of records:
![alt text](image.png)
## 2. `cat sales.jsonl` 
![alt text](image-1.png)
## 3. Pass the input dataset to the mapper:
`cat sales.jsonl | ./mapper.py`
![alt text](image-2.png)
## 4. Sort the output from mapper using: `cat sales.jsonl | ./mapper.py | sort`
![alt text](image-3.png)
## 5. sorted output  provided as input to the Reducer: `cat sales.jsonl | ./mapper.py | sort | ./reducer.py`
![alt text](image-4.png)
## 6. Ingest the dataset into HDFS
![alt text](image-5.png)

![alt text](image-6.png)
## 7. Run the MapReduce job on Hadoop
![alt text](image-7.png)
#### Check the output directory:
![alt text](image-8.png)
#### Verify its content
![alt text](image-9.png)
## 8. Verify the job through yarn
![alt text](image-10.png)
![alt text](image-11.png)