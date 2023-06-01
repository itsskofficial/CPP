#accepting number of clients
class Hashtable:
	def __init__(self):
		self.table[10]=[0] * 10
		self.pos=-1
	def insert_element(self,ele,probe_type):
		pos=x%10
		if (self.table[pos]!=0):
			self.table[pos]=ele
		else:
            if probe_type==0:
                count=1
                current=pos+1
                while self.table[current]!=0 and count!=10:
                    current=(current+1)%10
                    count+=1
                if count==len(self.elements):
                            print("\nHash table full, operation terminated")
                    else:
                        self.table[current]=ele
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