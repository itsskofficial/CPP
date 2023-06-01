#accepting number of clients
class Hashtable:
	def __init__(self):
		self.table[10]=[0] * 10
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
                if count==10:
                            print("\nHash table full, operation terminated")
                else:
                    self.table[current]=ele
            else:
                count=1
		        current=pos
                while self.table[current]!=0 and count!=10:
                    current=(pos + count**2) % 10
                    count+=1
                if count==10:
                            print("\nHash table full, operation terminated")
                else:
                    self.table[current]=ele
                    
	def remove_element(self,ele):
		flag=0
		for i in range(10):
			if self.table[i]==ele:
				self.table[i]=0
                flag=1
		if flag==1:
            print("Element removed")
        else:
            print("Element not found")
	
	def search_element(self,ele):
		flag=0
		for i in range(10):
			if self.table[i]==ele:
				self.table[i]=0
                flag=1
		        break
		if flag==1:
            print("Element removed")
        else:
            print("Element not found")
            
	def display_elements(self):
		for i in range(10):
			print(f"{self.table[i]}\n")

t=Hashtable()
ch=0

while ch!=4:
	print("Welcome user, these are your options: ")
	print("1.Insert an element\n2.Remove an element]\n3.Search an element\n4.Display elements\n5.Exit")
	ch=int(input("Enter your choice: "))
	if ch==1:
		x=int(input("Enter element to insert: "))
		pos=t.insert_element(x)
		if pos==-1:
			print("Can't insert element, table full")
		else:
			print(f"{x} is inserted at {pos}")