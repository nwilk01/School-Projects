#EECE 415 Assignment 2 Part 2 SMTP
#Written by Nathan Wilk

import ssl
import base64
from socket import *
msg ="\r\n I love computer networks!"
endmsg = "\r\n.\r\n"

# Choose a mail server (e.g. Google mail server) and call it mailserver mailserver = #Fill in start #Fill in end
mailserver = 'smtp.gmail.com'

# Create socket called clientSocket and establish a TCP connection with mailserver
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver, 25))

recv = clientSocket.recv(1024)
print recv
if recv[:3] != '220':
    print '220 reply not received from server.'

# Send HELO command and print server response.
heloCommand = 'EHLO Alice\r\n'
clientSocket.send(heloCommand)
recv1 = clientSocket.recv(1024)
print recv1
if recv1[:3]!= '250':
    print '250 reply not received from server.'

# Send STARTTL command and wrap socket in a SSL
command = 'STARTTLS\r\n'
clientSocket.send(command)
recvstart = clientSocket.recv(1024)
print recvstart
clientSocketSSL = ssl.wrap_socket(clientSocket)

#sending authorization
authMsg = 'AUTH LOGIN\r\n'
clientSocketSSL.send(authMsg)
recvauth = clientSocketSSL.recv(1024)
print recvauth

#sending username
username = 'ezbar2017'
busername = base64.b64encode(username)
clientSocketSSL.send(busername+'\r\n')
recvusername = clientSocketSSL.recv(1024)
print recvusername

#sending password blanked out for security reason
password = 'XXXXXX'
bpassword = base64.b64encode(password)
clientSocketSSL.send(bpassword+'\r\n')
recvpassword = clientSocketSSL.recv(1024)
print recvpassword


# Send MAIL FROM command and print server response.
command = 'MAIL FROM: <ezbar2017@gmail.com>\r\n'
clientSocketSSL.send(command)
recv2 = clientSocketSSL.recv(1024)
print 'Sender: ' + recv2
if recv2[:3]!= '250':
    print '250 reply not received from server.'
    
# Send RCPT TO command and print server response.
command = 'RCPT TO: <nwilk01@manhattan.edu>\r\n'
clientSocketSSL.send(command)
recv3 = clientSocketSSL.recv(1024)
print 'Reciever: ' +recv3
if recv2[:3]!= '250':
    print '250 reply not received from server.'

# Send DATA command and print server response.
command = 'DATA\r\n'
clientSocketSSL.send(command)
recv3 = clientSocketSSL.recv(1024)
print 'Sending Data'


# Send message data.
clientSocketSSL.send(msg)


# Message ends with a single period.
clientSocketSSL.send(endmsg)


# Send QUIT command and get server response.
command = 'QUIT\r\n'
clientSocketSSL.send(command)
recv3 = clientSocketSSL.recv(1024)
print 'Quiting'

