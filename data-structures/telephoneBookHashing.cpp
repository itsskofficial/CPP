#include <iostream>
#include <string>

struct telephoneRecord
{
  std::string name;
  long telephoneNo;
};

class hash
{
  int size;
  telephoneRecord *hashtable;
  bool *flag;
  public:
  hash()
  {
    std::cout << "Creating telephone book of default size 10" << std::endl;
    size = 10;
    hashtable = new telephoneRecord[size];
    flag = new bool[size];
    for(int i = 0; i < size; i++)
    {
      flag[i] = 0;
      hashtable[i].telephoneNo = -1;
    }
  }

  hash(int a)
  {
    std::cout << "Creating telephone book of size " << a << std::endl;
    size = a;
    hashtable = new telephoneRecord[size];
    flag = new bool[size];
    for(int i = 0; i < size; i++)
    {
      flag[i] = 0;
      hashtable[i].telephoneNo = -1;
    }
  }

  void insertLinearProbing(std::string name, long telephoneNo);
  void insertQuadraticProbing(std::string name, long telephoneNo);
  int searchLinearProbing(std::string name);
  int searchQuadraticProbing(std::string name);
  void display();
};

void hash::insertLinearProbing(std::string name, long telephoneNo)
{
  telephoneRecord *t = new telephoneRecord;
  t->name = name;
  t->telephoneNo = telephoneNo;

  int loc, ASCII_sum = 0;
  for(int i = 0; i < t->name.size(); i++)
  {
    ASCII_sum = ASCII_sum + int(t->name[i]);
  }

  loc = (ASCII_sum/t->name.size()) % size;
  for(int i = 0; i < size; i++)
  {
    if(flag[loc] == 0)
    {
      hashtable[loc] = *t;
      flag[loc] = 1;
      break;
    }
    else
    {
      loc = (loc + 1) % size;
    }
  }
}

void hash::insertQuadraticProbing(std::string name, long telephoneNo)
{
  telephoneRecord *t = new telephoneRecord;
  t->name = name;
  t->telephoneNo = telephoneNo;

  int loc, ASCII_sum = 0;
  for(int i = 0; i < t->name.size(); i++)
  {
    ASCII_sum = ASCII_sum + int(t->name[i]);
  }

  loc = (ASCII_sum/t->name.size()) % size;
  for(int i = 0; i < size; i++)
  {
    if(flag[loc] == 0)
    {
      hashtable[loc] = *t;
      flag[loc] = 1;
      break;
    }
    else
    {
      loc = (loc + i*i) % size;
    }
  }
}

int hash::searchLinearProbing(std::string name)
{
  int loc, ASCII_sum = 0, count = 0;
  for(int i =0; i < name.size(); i++)
  {
    ASCII_sum = ASCII_sum + int(name[i]);
  }

  loc = (ASCII_sum/name.size()) % size;

  if(flag[loc] == 0)
  {
    std::cout << name << " does not exist in the telephone book!" << std::endl;
    return -1;
  }
  else
  {
    if(hashtable[loc].name == name)
    {
      std::cout << "The phone number of " << name << "is " << hashtable[loc].telephoneNo << std::endl;
      return count;
    }
    else
    {
      for(int i = 0; i < size; i++)
      {
        loc = (loc + 1) % size;
        count++;

        if(hashtable[loc].name == name)
        {
          std::cout << "The phone number of " << name << "is " << hashtable[loc].telephoneNo << std::endl;
          return count;
        }
      }
    }
  }
}

int hash::searchQuadraticProbing(std::string name)
{
  int loc, ASCII_sum = 0, count = 0;
  for(int i =0; i < name.size(); i++)
  {
    ASCII_sum = ASCII_sum + int(name[i]);
  }

  loc = (ASCII_sum/name.size()) % size;

  if(flag[loc] == 0)
  {
    std::cout << name << " does not exist in the telephone book!" << std::endl;
    return -1;
  }
  else
  {
    if(hashtable[loc].name == name)
    {
      std::cout << "The phone number of " << name << "is " << hashtable[loc].telephoneNo << std::endl;
      return count;
    }
    else
    {
      for(int i = 0; i < size; i++)
      {
        loc = (loc + i*i) % size;
        count++;

        if(hashtable[loc].name == name)
        {
          std::cout << "The phone number of " << name << "is " << hashtable[loc].telephoneNo << std::endl;
          return count;
        }
      }
    }
  }
}

void hash::display()
{
  telephoneRecord *t;
  for(int i = 0; i < size; i++)
  {
      t = &hashtable[i];
      std::cout << t->name << " - " << t->telephoneNo << std::endl;
  }
}

int main()
{ 
  int ch, n1, n2;
  std::string name;
  long telephoneNo;
  hash book1, book2;

  do
  {
    std::cout << "1) Insert \n2) Search \n3)Display \n4)Exit" << std::endl;
    std::cin >> ch;

    switch(ch)
    {
    case 1:
    {
      std::cout << "Enter name" << std::endl;
      std::getline(std::cin >> std::ws, name);
      std::cout << "Enter telephone number" << std::endl;
      std::cin >> telephoneNo;
      book1.insertLinearProbing(name, telephoneNo);
      book2.insertQuadraticProbing(name, telephoneNo);
      break;
    }
    
    case 2:
      std::cout << "Enter name to be searched: ";
      std::getline(std::cin >> std::ws, name);
      n1 = book1.searchLinearProbing(name);
      n2 = book2.searchQuadraticProbing(name);
      std::cout << "No. of comparisons by linear probing: " << n1 << std::endl;
      std::cout << "No. of comparisons by quadratic probing: " << n2 << std::endl;
      break;

    case 3:
      std::cout << "Book 1 (Linear Probing): " << std::endl;
      book1.display();
      std::cout << std::endl;
      std::cout << "Book 2 (Quadratic Probing): " << std::endl;
      book2.display();
      break;

    default:
      std::cout << "Please enter valid choice" << std::endl;
      break;
    }

} while(ch!=4);
  return 0;

}