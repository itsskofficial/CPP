#accepting number of clients
class Hashtable:
	def __init__(self):
		self.table[10]=[0] * 10
	def insert(self,ele,probe_type):
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
                    
	def delete(self,ele):
		flag=0
		for i in range(10):
			if self.table[i]==ele:
				self.table[i]=0
				flag=1
		if flag==1:
            print("Element removed")
        else:
            print("Element not found")
	
	def find(self,ele):
		flag=0
        current=-1
		for i in range(10):
			if self.table[i]==ele:
				self.table[i]=0
                flag=1
		        current=i
		if flag==1:
            print(f"Element found at position {current}")
        else:
            print("Element not found")
            
	def display_elements(self):
		for i in range(10):
			print(f"{self.table[i]}\n")

t=Hashtable()
choice=0

while choice!=5:
    choice=int(input("\nWhat do you want to do?\n1. Insert an element\n2. Delete an element\n3. Find an element\n4. Display elements\n5. Exit\n\nEnter option number: "))
    if choice==1:
        ele=int(input("Enter element: "))
        probe_type=int(input("\nEnter 0 for linear probing and 1 for quadratic probing: "))
        t.insert(ele,probe_type)
    elif choice==2:
        key=int(input("\nEnter key to delete: "))
        t.delete(ele)
    elif choice==3:
        key=int(input("\nEnter key to find: "))
        t.find(ele)
    elif choice==4:
        t.display()
    elif choice==5:
        exit(1)
    else:
        print("\nEnter valid option number")
        exit(1)