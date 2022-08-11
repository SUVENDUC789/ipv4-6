binary = {'0': '0000', '1': '0001', '2': '0010', '3': '0011', '4': '0100', '5': '0101', '6': '0110', '7': '0111',
          '8': '1000', '9': '1001', 'a': '1010', 'b': '1011', 'c': '1100', 'd': '1101', 'e': '1110', 'f': '1111'}

var="fE80::B97F:4EAD:B5a3:9dd1"

var=input("Enter Ipv-6 : ")
var=var.lower()
var2=[]

try:
    for i in var:
        if i==':':
            var2.append(i)
        else :
            var2.append(binary[i])
except:
    print("Please Enter valid Ipv-6 🤷‍♀️...")
    exit()

print("Binary form of the Ipv-6 :>")
for item in var2:
    print(item,end="")

