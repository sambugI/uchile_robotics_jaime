import serial 
import time
class BMS:
    def __init__(self):
        self.port = serial.Serial("/dev/battery_bms", 9600, timeout=1.0)
        self.request = bytes.fromhex("DD A5 03 00 FF FD 77") #Esta wea es la serie de bytes que hay que enviarle al BMS para que responda con info.
        self.voltage = 0.0
        self.current = 0.0 
        self.temp = 0.0
        self.percentage = 0.0
        self.total_capacity = 0.0
        self.residual_capacity = 0.0

    def read(self):
        self.port.write(self.request)
        byte_list = self.port.read(34)
        time.sleep(0.15)
        self.voltage = (int(byte_list[4])*256 + int(byte_list[5]))/100 
        self.current = (int(byte_list[6])*256 + int(byte_list[7]))/100
        self.temp = (int(byte_list[29])*256 + int(byte_list[30]) -2731)/10
        self.total_capacity = (int(byte_list[10])*256 + int(byte_list[11]))/100
        self.residual_capacity = (int(byte_list[8])*256 + int(byte_list[9]))/100
        self.percentage = int(byte_list[23])
    def write(self):
        print(str(self.voltage) + "V")
        print(str(self.current) + "A")  
        print(str(self.temp) + "C")
        print(str(self.total_capacity) + "Ah")
        print(str(self.residual_capacity) + "Ah")
        print(str(self.percentage) + "%")


while True:
    print(str(16.6) + "V")
    print(str(1.2) + "A")  
    print(str(21.3) + "C")
    print(str(8.8) + "Ah")
    print(str(9.7) + "Ah")
    print(str(0.9) + "%")
    time.sleep(0.15)