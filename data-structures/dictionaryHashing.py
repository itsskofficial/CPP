class Dictionary:
    elements=[{'key':0, 'value':0 } * 10]
    chain=[-1 * 10]
    
    def insert(self,ele):
        pos=ele['key']%len(self.elements)
        if self.elements[pos]['key']==0:
            self.elements[pos]=ele
        else:
            

        



choice=0


while choice!=4:
    print("What do you want to do?")
    print("\n1. Insert a word\n2. Delete a word\n3. Find a word\n4. Exit")
    if choice==1:
        

