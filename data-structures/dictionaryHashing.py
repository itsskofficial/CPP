class Dictionary:
    def __init__(self):
        self.elements=[{'key':0, 'value':0 } * 10]
        self.chain=[-1 * 10]
        self.chain_index=[-1 * 10]

    def insert(self,ele, chain_type):
        flag=0
        for i in self.elements:
            if i['key']==0:
                flag=1

        if flag==1:
            pos=ele['key']%len(self.elements)
            if self.elements[pos]['key']==0:
                self.elements[pos]=ele
            else:
                if chain_type==0:
                    count=1
                    current=pos

                    while(self.elements[current]['key']!=0 or count!=len(self.elements)):
                        current=(current+1)%len(self.elements)
                        count+=1
                    if count==len(self.elements):
                            print("Hash table full, operation terminated")
                    else:
                        self.elements[current]=ele

                        if self.chain[pos]==-1:
                            self.chain[pos]=current
                            self.chain_index[pos]=current
                        else:
                            self.chain[self.chain_index[pos]]=current
                            self.chain_index[pos]=current
                else:
                    count=1
                    current=pos

                    while self.elements[current]['key']==0 or self.elements[pos]['key']%len(self.elements)!=pos or count==len(self.elements):
                        current=(current+1)%len(self.elements)
                        count+=1
                    
                    if count==len(self.elements):
                            print("Hash table full, operation terminated")
                    else:
                        if self.elements[current]['key']==0:
                            self.elements[current]=ele

                            if self.chain[pos]==-1:
                                self.chain[pos]=current
                                self.chain_index[pos]=current
                            else:
                                self.chain[self.chain_index[pos]]=current
                                self.chain_index[pos]=current
                        else:
                            count=1
                            temp=self.elements[current]
                            self.elements[current]=ele

                            if self.chain[pos]==-1:
                                self.chain[pos]=current
                                self.chain_index[pos]=current
                            else:
                                self.chain[self.chain_index[pos]]=current
                                self.chain_index[pos]=current

                            pos=temp%len(self.elements)

                            while(self.elements[current]['key']!=0 or count==len(self.elements)):
                                current=(current+1)%len(self.elements)
                                count+=1

                            if count==len(self.elements):
                                print("Hash table full, operation terminated")
                            else:
                                self.elements[current]=temp

                                if self.chain[pos]==-1:
                                    self.chain[pos]=current
                                    self.chain_index[pos]=current
                                else:
                                    self.chain[self.chain_index[pos]]=current
                                    self.chain_index[pos]=current
    def delete(self,key):
        flag=0
        for i in range(len(self.elements)):
            if self.elements[i]['key']==key:
                temp=self.elements[i]
                self.elements[i]['key']=0
                self.elements[i]['value']=0
                if self.chain[i]!=-1:
                    next=self.chain[i]
                    for j in self.chain:
                        if j==i:
                            prev=self.chain.index(j)
                    self.chain[prev]=next
                    self.chain[i]=-1
                    if i in self.chain_index:
                        self.chain_index[self.chain_index.index(i)]==prev
                else:
                    self.chain_index[temp%len(self.elements)]=-1
                flag=1
        if flag==1:
            print("Element deleted successfully")
        else:
            print("Element not found")
    
    def find(self,key):
        flag=0
        for i in range(len(self.elements)):
            if self.elements[i]['key']==key:
                flag=1
        
        if flag==1:
            print("Element found")
        else:
            print("Element not found")
    
    def display(self):
        print("Element\tChain")
        for i in range(len(self.elements)):
            print(f"")



choice=0
d=Dictionary()
while choice!=4:
    choice=int(input("What do you want to do?\n1. Insert an element\n2. Delete an element\n3. Find an element\n4. Exit\nEnter option number: "))
    if choice==1:
        key=int(input("Enter key: "))
        value=int(input("Enter value: "))
        ele={'key':key,'value':value}
        chain_type=int(input("Enter 0 for chaining without replacement and 1 for chaining with replacement: "))
        d.insert(ele,chain_type)
    elif choice==2:
        key=int(input("Enter key to delete: "))
        d.delete(key)
    elif choice==3:
        key=int(input("Enter key to find: "))
        d.find(key)
    elif choice==4:
        exit(1)
    else:
        print("\nEnter valid option number")
        exit(1)
        

