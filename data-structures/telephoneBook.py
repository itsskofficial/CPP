#accepting number of clients
n= int(input("Enter number of clients: "))

class Hashtable:
	def __init__(self):
		self.table[10]=[0] * 10
		self.pos=-1
	def insert_element(self,x,probe_type):
		pos=x%10
		if (self.table[pos]!=0):
			self.table[pos]=x
		else:
			if probe_type==0:
				current
                for i in range(n):
                    if (table[pos]!=0):
                        table[pos]=x
                        return pos
                    else:
                        pos=(pos+1)%10
                if i==n-1:
                    return -1
	def remove_element(x):
		pos=x%10
		if (table[pos]!=null):
			ele=table[pos]
			return ele
		else:
			pos=(pos+1)%10
	def display_elements():
		for i in range(n):
			print(table[pos])

t=Hashtable()
ch=0

while ch!=4:
	print("Welcome user, these are your options: ")
	print("1.Insert element\n2.Remove element]\n3.Display elements")
	ch=int(input("Enter your choice: "))
	if ch==1:
		x=int(input("Enter element to insert: "))
		pos=t.insert_element(x)
		if pos==-1:
			print("Can't insert element, table full")
		else:
			print(f"{x} is inserted at {pos}")