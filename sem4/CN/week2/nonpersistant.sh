#!/bin/bash
SERVER="10.228.215.62"

# Clear connection pool
curl --http1.0 -H "Connection: close" "http://$SERVER/index.html" > /dev/null

# Get each image with a delay and different output
for i in {1..10}; do

  curl --http1.0 \
       -H "Connection: close" \
       -H "User-Agent: NonPersistentTest/1.0" \
       -o /dev/null \
       -s \
       "http://$SERVER/Image%20-%20$i.jpg"
done
