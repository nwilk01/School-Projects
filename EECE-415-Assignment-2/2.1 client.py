#Assignment 2 EECE 415
#Nathan Wilk
import time
from socket import *

#setting the IP and PORT to send to and variable initiallization
IP = "127.0.0.1" #149.61.209.81 Raspberry Pi IP
PORT = 12000
min = 10000;
max =0;
average=0;
pings = 0.00000;
#sending 10 pings
for x in range (1,11):
    MESSAGE = 'ping %d %f' % (x, time.time()) # create message with time stamp
    socketter = socket(AF_INET, SOCK_DGRAM) #creating a socket using UDP 
    socketter.settimeout(1) #setting a timeout of 1 second to assume packet loss
    begin = time.time() #getting current time at message sent in seconds for RTT
    socketter.sendto(MESSAGE, (IP, PORT)) #send ping
    try: 
        data, server = socketter.recvfrom(1024) #data that is returned
        finish = time.time() #getting current time message is recieved in seconds for RTT 
        RTT = finish-begin #calculating RTT
        print "Response: " + data 
        print "Round Trip Time: %f" % (RTT) 
        if (max < RTT): #check for new max time
            max = RTT
        if (min > RTT): #check for new min time
            min = RTT
        average = (average + RTT) #increases total time
        pings = pings+1 #increases number of sucessful responses
    except timeout: #catch error if message timeout
        print "Request Timed Out" 
print "Min RTT: %f" % (min) 
print "Max RTT: %f" % (max) 
average = average/pings #calculate average
pings = (pings/10)*100 #calculate percent loss
print "Average RTT: %f" % (average)
print "Percent of Packets Lost: %d" % (pings)
        
