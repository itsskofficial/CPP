class Dictionary:
    def __init__(self):
        elements=[{'key':0, 'value':0 } * 10]
        chain=[-1 * 10]
        
    def insert(self,ele):
        pos=ele['key']%len(self.elements)
        if self.elements[pos]['key']==0:
            self.elements[pos]=ele
        else:
            current=pos
            while(self.elements[current]['key']==0):
                current=current+1
            self.elements[current]=ele
            self.chain[pos]=current
    

            

        



choice=0
d=Dictionary()
while choice!=4:
    choice=int(input("What do you want to do?\n1. Insert a word\n2. Delete a word\n3. Find a word\n4. Exit\nEnter option number: "))
    if choice==1:
        key=int(input("Enter key: "))
        value=int(input("Enter value: "))
        ele={'key':key,'value':value}
        chain_type=int(input("Enter 0 for chaining without replacement and 1 for chaining with replacement: "))

        

