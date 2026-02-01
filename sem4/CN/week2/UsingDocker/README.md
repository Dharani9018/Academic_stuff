```
Arch Linux (Host)
 ├── Firefox (Client)
 ├── Wireshark
 └── Docker
      └── Apache container (Server)
```

### Install Docker, Wireshark and Firefox
```bash
sudo pacman -S docker wireshark-qt firefox
```
### Step 0
#### A. enable docker
```bash
sudo systemctl enable --now docker
```
#### B. start docker
```bash
sudo systemctl start docker
```
#### C.
##### without this command every docker command would be needing sudo
```bash
sudo usermod -aG docker $USER
```
#### D. logout and login
```bash
logout
```
#### E. Confirm:
```bash
docker run hello-world
```
### step 1 : Run apache inside docker:
#### A: Pull Apache image
```bash
docker pull httpd:2.4
```
#### B: Create a Working directory
```bash
mkdir -p ~/lab2/html
```
##### mv all contents(index.html and images) to the html directory.
#### C: Run apache container
```bash
docker run -d \
  --name lab2 \
  -p 8080:80 \
  -v $(pwd)/html:/usr/local/apache2/htdocs \
  httpd:2.4
```
#### D: verify
```
docker ps
```
#### E: open browser - `http://localhost:8080` -> if the page loads, the server works.
### Step 2: Find server ip
```bash
ip addr show docker0
```
#### you'll see smtg like `172.17.0.1/16`
### Step 3: Server config:

#### A. Copy Apache config from the container to the host machine
```bash
docker cp lab2:/usr/local/apache2/conf/httpd.conf .
```
#### B. You'll see `httpd.conf` in the lab2 directory.
#### C. edit the the `httpd.conf` 
##### Find KeepAlive, if it doesnt exist add this below `Listen 80`
```
ServerName imserver
KeepAlive On
MaxKeepAliveRequests 100
KeepAliveTimeout 5
```
(for  persistant)
#### D. Stop and delete delete the container and run again with mounter config.
##### stop
```bash
docker stop lab2
```
##### start
```bash
docker rm lab2
```
##### mount the config file from the host inside the container
```bash
docker run -d \
  --name lab2 \
  -p 8080:80 \
  -v $(pwd)/html:/usr/local/apache2/htdocs \
  -v $(pwd)/httpd.conf:/usr/local/apache2/conf/httpd.conf \
  httpd:2.4
```
### E. Enter the container and restart the server
#### Enter the server:
```bash
docker exec -it apache-lab bash
```
#### Restart the server and exit
```bash
httpd -k restart
```
```bash
exit
```
### Client config
#### 1. In the firefox search `about:config` -> accept risk and continue

