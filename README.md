# ERROR_404


OVERVIEW OF THE PROJECT :
* The main goal of the project is to design a bank locker security system based on rfid and gsm. 
* In this system, only the authentic person can recover money from the bank locker.
* This system consists of microcontroller,RFID reader,GSM modem,keypad and LCD.
* The RFID reader reads the ID number from the card and sends it to the microcontroller.
* If the card number is valid, then the microcontroller send the OTP to the authenticated person's mobile number.
* If the person sends the  OTP to the microcontroller, which verifies the OTP entered through the keypad, and acts accordingly.
* The output is shown in LED.

sketch_jan23b :	       
* An authorized rfid card number and the mobile number to which the password is to be sent is stored globally. 
* When the user scans his/her card, the rfid reader reads its number and checks it with the authorized card number stored.
* If its the same, an OTP is generated using certain calculations,and then sent to the registered mobile number, which must be entered in the keypad to unlock.
* If the OTP entered or the card scanned by user is wrong, the lock will remain closed.

final :	       
* The user's scanned rfid card number and the authorized card number are checked.
* The gsm is activated in text mode using the ATcommands.
* When both the card numbers match, an OTP will be generated randomly for security purposes, and is further sent to the authorized mobile number.
* If the OTP is correct, the door unlocks.
* The door remains locked, in case of incorrect OTP or unauthorized card. 

PROPOSED SYSTEM :
* The main goal of this project is to design and implement a bank locker security system based on RFID and GSM technology which can be organized in bank,secured offices 
  and homes. 
* In this system only authentic person can recover money from the bank locker. 
* We have implemented a bank locker security system based on RFID and GSM technology containing door locking system using RFID and GSM which can activate, authenticate,
  and validate the user and unlock the door in real time for bank locker secure access. 
* The main advantage of using passive RFID and GSM is more secure than other systems. 
* This system consists of microcontroller, RFID reader, GSM modem, keypad, and LCD.
* The RFID reader reads the rfid number from the card scanned and sends to the microcontroller,if the rfid card number is valid then microcontroller sends the SMS 
  request to the authenticated mobile number, for the original password to open the bank locker,if the person send the password to the microcontroller, which will 
  verify the passwords entered by the keypad and received from authenticated mobile phone. 
* If these two passwords are matched the locker will be opened otherwise it will remain in locked position, This system is more secure than other systems because 
  two passwords are required for verification.
* RFID system has much larger areas of use like transportation and logistics,security and animal tagging, postal tracking, time, attendance and road toll management.

TECHNOLOGY STACK :
* Arduino UNO
* GSM SIM800 Modem
* 16x2 LCD Display
* RFID Reader
* 4x3 Keypad